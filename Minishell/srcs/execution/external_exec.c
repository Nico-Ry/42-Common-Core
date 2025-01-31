/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:13:11 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 10:13:11 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * @brief Prints an error message to stderr in the format:
 *        miniHell: <cmd>: <message>\n
 * @param cmd The command that caused the error.
 * @param msg The error message to display.
 */
static void	print_error_message(const char *cmd, const char *msg)
{
	write(2, "miniHell: ", 10);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

/*
 * @brief Resolves the executable path for a command.
 * @param minish The minishell structure.
 * @param cmd The command structure.
 * @return The resolved path or NULL.
 */
static char	*get_executable_path(t_minishell *minish, t_command *cmd)
{
	if (cmd->cmd[0] == '/' || (cmd->cmd[0] == '.'
			&& (cmd->cmd[1] == '/' || cmd->cmd[1] == '.')))
	{
		if (is_invalid_directory_usage(cmd))
		{
			print_error_message(cmd->cmd, "Not a directory");
			minish->last_exit_status = 126;
			return (NULL);
		}
		if (is_valid_executable_path(cmd))
			return (ft_strdup(cmd->cmd));
		print_error_message(cmd->cmd, "No such file or directory");
		minish->last_exit_status = 127;
		return (NULL);
	}
	return (find_executable(cmd->cmd, minish->env_lst, minish));
}

static void	handle_child_process(char *path,
				t_command *cmd, t_minishell *minish)
{
	execve(path, cmd->args, minish->env_array);
	perror("execve");
	free(path);
	exit(127);
}

static int	handle_parent_process(t_minishell *minish, pid_t pid, char *path)
{
	int	status;

	free(path);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		minish->last_exit_status = 128 + WTERMSIG(status);
	else
		minish->last_exit_status = WEXITSTATUS(status);
	return (minish->last_exit_status);
}

/*
 * @brief Executes an external command in a child process.
 * @note If the command is not found, prints
 * an error message and sets exit status to 127.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param cmd The command to execute.
 * @return int The exit status of the executed command.
 */
int	execute_external(t_minishell *minish, t_command *cmd)
{
	pid_t	pid;
	char	*path;

	path = get_executable_path(minish, cmd);
	if (!path)
	{
		if (cmd->cmd[0] != '/' && !(cmd->cmd[0] == '.' && cmd->cmd[1] == '/'))
			print_error_message(cmd->cmd, "command not found");
		if (minish->last_exit_status != 126)
			minish->last_exit_status = 127;
		return (minish->last_exit_status);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(path);
		return (1);
	}
	if (pid == 0)
		handle_child_process(path, cmd, minish);
	return (handle_parent_process(minish, pid, path));
}
