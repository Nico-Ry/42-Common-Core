/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:10:39 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 11:11:33 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * @brief Executes a built-in command in a child process.
 * @note Handles pipes and redirections before execution.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param ast The AST node to execute.
 * @param cmd_data The command data structure.
 * @param pipe_fds File descriptors for the pipeline (NULL if not in a pipeline).
 */
static void	execute_builtin_child(t_minishell *minish,
			t_ast *ast, t_command *cmd_data, int pipe_fds[2])
{
	setup_child_signals();
	if (pipe_fds)
	{
		if (pipe_fds[1] >= 0)
			dup2(pipe_fds[1], STDOUT_FILENO);
		if (pipe_fds[0] >= 0)
			dup2(pipe_fds[0], STDIN_FILENO);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
	}
	if (ast->type == REDIRECTION_NODE)
		handle_redirections_child(ast, minish);
	exec_builtin(cmd_data->cmd, cmd_data, minish, STDOUT_FILENO);
	exit(minish->last_exit_status);
}

/*
 * @brief Executes a built-in command in the parent process.
 * @note Handles redirections and restores file descriptors.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param ast The AST node to execute.
 * @param cmd_data The command data structure.
 * @return int The exit status of the command.
 */
static int	execute_builtin_parent(t_minishell *minish,
				t_ast *ast, t_command *cmd_data)
{
	int	status;
	int	fd_backup[2];

	fd_backup[0] = -1;
	fd_backup[1] = -1;
	if (ast->type == REDIRECTION_NODE
		&& handle_redirections_parent(ast, fd_backup) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	status = exec_builtin(cmd_data->cmd, cmd_data, minish, STDOUT_FILENO);
	if (fd_backup[0] != -1)
	{
		dup2(fd_backup[0], STDIN_FILENO);
		close(fd_backup[0]);
	}
	if (fd_backup[1] != -1)
	{
		dup2(fd_backup[1], STDOUT_FILENO);
		close(fd_backup[1]);
	}
	return (status);
}

static int	execute_builtin_command(t_minishell *minish,
				t_ast *ast, t_command *cmd_data, int pipe_fds[2])
{
	int		status;
	pid_t	pid;

	if (pipe_fds)
	{
		pid = fork();
		if (pid == 0)
			execute_builtin_child(minish, ast, cmd_data, pipe_fds);
		waitpid(pid, &status, 0);
		update_exit_status(minish, status);
		return (status);
	}
	return (execute_builtin_parent(minish, ast, cmd_data));
}

static int	execute_external_command(t_minishell *minish,
			t_ast *ast, t_command *cmd_data, int pipe_fds[2])
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		setup_child_signals();
		if (pipe_fds)
		{
			if (pipe_fds[0] >= 0)
				dup2(pipe_fds[0], STDIN_FILENO);
			if (pipe_fds[1] >= 0)
				dup2(pipe_fds[1], STDOUT_FILENO);
			close(pipe_fds[0]);
			close(pipe_fds[1]);
		}
		if (ast->type == REDIRECTION_NODE)
			handle_redirections_child(ast, minish);
		status = execute_external(minish, cmd_data);
		exit(status);
	}
	waitpid(pid, &status, 0);
	update_exit_status(minish, status);
	return (status);
}

/*
 * @brief Handles the execution of a command or redirection node.
 * @note Executes builtins, external commands, and standalone redirections.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param ast The AST node to execute.
 * @param pipe_fds The file descriptors for the pipe.
 * @return int The exit status of the executed command.
 */
int	handle_command_or_redirection(t_minishell *minish,
									t_ast *ast, int pipe_fds[2])
{
	t_ast		*redir_ast;
	t_command	*cmd_data;
	int			status;

	redir_ast = validate_command_ast(minish, ast);
	if (!redir_ast)
	{
		handle_redirection_standalone(minish, ast);
		return (EXIT_FAILURE);
	}
	cmd_data = extract_and_validate_command(minish, redir_ast);
	if (!cmd_data)
	{
		if (ast->type == REDIRECTION_NODE)
			handle_redirection_standalone(minish, ast);
		return (EXIT_SUCCESS);
	}
	if (cmd_data && is_builtin(cmd_data->cmd))
		status = execute_builtin_command(minish, ast, cmd_data, pipe_fds);
	else if (cmd_data)
		status = execute_external_command(minish, ast, cmd_data, pipe_fds);
	return (status);
}
