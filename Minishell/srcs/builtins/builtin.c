/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:09:50 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 14:09:50 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Checks if a command is a built-in.
 * @param cmd Command name.
 * @return 1 if built-in, 0 otherwise.
 */
int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (-1);
	return (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "exit") == 0 || ft_strcmp(cmd, "./minishell") == 0);
}

/**
 * @brief Traverses the AST recursively to find the command node.
 * @param ast The current AST node.
 * @return The command node if found, or NULL otherwise.
 */
t_command	*extract_command_data(t_ast *ast)
{
	if (!ast)
		return (NULL);
	if (ast->type == COMMAND_NODE)
		return ((t_command *)ast->data);
	if (ast->type == REDIRECTION_NODE || ast->type == PIPE_NODE)
		return (extract_command_data(ast->left));
	return (NULL);
}

/**
 * @brief Executes a built-in command.
 * Calls the corresponding function for the built-in command.
 * @param cmd Command name.
 * @param minish Minishell structure.
 * @param out_fd The file descriptor for output.
 */
int	handle_builtin_command(const char *cmd, t_command *cmd_data,
							t_minishell *minish, int out_fd)
{
	int	status;

	status = EXIT_FAILURE;
	if (ft_strcmp(cmd, "echo") == 0)
		status = handle_echo(cmd_data, minish, out_fd);
	else if (ft_strcmp(cmd, "cd") == 0)
		status = handle_cd(cmd_data, minish);
	else if (ft_strcmp(cmd, "pwd") == 0)
		status = handle_pwd(cmd_data);
	else if (ft_strcmp(cmd, "export") == 0)
		status = handle_export(cmd_data, minish);
	else if (ft_strcmp(cmd, "unset") == 0)
		status = handle_unset(cmd_data, minish);
	else if (ft_strcmp(cmd, "env") == 0)
		status = handle_env(cmd_data, minish);
	else if (ft_strcmp(cmd, "exit") == 0)
		status = handle_exit(cmd_data, minish);
	else if (ft_strcmp(cmd, "./minishell") == 0)
		status = handle_new_minishell(minish);
	else
		perror("miniHell: internal error: unknown builtin command\n");
	minish->last_exit_status = status;
	return (status);
}

/**
 * @brief Executes a built-in command.
 * Redirects the output to the specified file descriptor.
 * Calls the corresponding function for the built-in command.
 * @param cmd Command name.
 * @param cmd_data Command data.
 * @param minish Minishell structure.
 * @param out_fd The file descriptor for output.
 */
int	exec_builtin(const char *cmd, t_command *cmd_data,
					t_minishell *minish, int out_fd)
{
	int	stdout_backup;
	int	status;

	status = EXIT_FAILURE;
	stdout_backup = dup(STDOUT_FILENO);
	if (stdout_backup == -1)
	{
		perror("miniHell: Failed to back up stdout");
		return (EXIT_FAILURE);
	}
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror("miniHell: Failed to redirect stdout");
		close(stdout_backup);
		return (EXIT_FAILURE);
	}
	status = handle_builtin_command(cmd, cmd_data, minish, STDOUT_FILENO);
	if (dup2(stdout_backup, STDOUT_FILENO) == -1)
	{
		perror("miniHell: Failed to restore stdout");
		close(stdout_backup);
		return (EXIT_FAILURE);
	}
	close(stdout_backup);
	return (status);
}
