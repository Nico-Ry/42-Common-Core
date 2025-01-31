/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:55:54 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 09:56:09 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Executes a built-in command.
 * @param minish Minishell structure.
 * @param cmd Command structure.
 */
int	execute_builtin(t_minishell *minish, t_command *cmd)
{
	if (!cmd || !cmd->cmd)
		return (1);
	exec_builtin(cmd->cmd, cmd, minish, STDOUT_FILENO);
	return (0);
}

static void	handle_child_process(t_minishell *minish,
			t_ast *ast, t_command *cmd_data)
{
	int	status;

	setup_child_signals();
	handle_redirections_child(ast, minish);
	status = execute_external(minish, cmd_data);
	exit(status);
}

static void	handle_parent_process(t_minishell *minish, pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("[DEBUG] handle_external_command: waitpid failed");
		minish->last_exit_status = EXIT_FAILURE;
	}
	else
	{
		if (WIFEXITED(status))
			minish->last_exit_status = WEXITSTATUS(status);
		else
			minish->last_exit_status = EXIT_FAILURE;
	}
}

int	handle_external_command(t_minishell *minish,
		t_ast *ast, t_command *cmd_data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		handle_child_process(minish, ast, cmd_data);
	else if (pid > 0)
		handle_parent_process(minish, pid);
	else
	{
		perror("[DEBUG] handle_external_command: Fork failed");
		exit(EXIT_FAILURE);
	}
	return (minish->last_exit_status);
}

/**
 * @brief Handles command execution (built-in or external).
 * @param minish Minishell structure.
 * @param cmd Command structure.
 */
int	handle_command(t_minishell *minish, t_command *cmd)
{
	int	status;

	if (is_new_localvar(cmd->cmd))
	{
		status = handle_local_var(minish, cmd->cmd);
		return (status);
	}
	if (is_builtin(cmd->cmd))
		status = exec_builtin(cmd->cmd, cmd, minish, STDOUT_FILENO);
	else
		status = execute_external(minish, cmd);
	return (status);
}
