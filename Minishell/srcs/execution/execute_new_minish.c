/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_new_minish.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:12:07 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 15:21:40 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * @brief Executes a new instance of minishell.
 * @note Calls execve to replace the current
 * process with a new minishell instance.
 * If execution fails, an error message is printed, and the process exits.
 *
 * @param path The path to the minishell executable.
 * @param argv The arguments passed to the new minishell instance.
 * @param env_array The environment variables for the new process.
 */
static void	exec_new_minishell(char *path, char **argv, char **env_array)
{
	execve(path, argv, env_array);
	perror("minishell: Error executing ./minishell");
	free(path);
	exit(EXIT_FAILURE);
}

/*
 * @brief Handles the parent process after forking a new minishell instance.
 * @note Waits for the child process to finish
 * and updates the exit status accordingly.
 * If waitpid fails, an error is printed, and the exit status is set to failure.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param pid The process ID of the child process.
 * @param path The path to the minishell executable.
 * @return int The exit status of the new minishell instance.
 */
static int	handle_parent_process(t_minishell *minish, pid_t pid, char *path)
{
	int	status;

	if (pid > 0)
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("minishell: Error waiting for child minishell");
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
	else
	{
		perror("minishell: Error forking for new minishell");
		free(path);
		return (EXIT_FAILURE);
	}
	return (minish->last_exit_status);
}

/*
 * @brief Prepares the environment for launching a new minishell instance.
 * @note Retrieves the current working directory,
 * constructs the path to minishell,
 * and updates the environment array.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param path Pointer to store the constructed path to minishell.
 * @param updated_env_array Pointer to store the updated environment array.
 * @return int Returns EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
static int	prepare_new_minishell(t_minishell *minish, char **path,
				char **updated_env_array)
{
	char	*cwd;

	cwd = get_env_var(minish, "PWD");
	if (!cwd)
	{
		perror("minishell: Error retrieving PWD");
		return (EXIT_FAILURE);
	}
	*path = ft_strjoin(cwd, "/minishell");
	if (!*path)
	{
		perror("minishell: Error constructing path to ./minishell");
		return (EXIT_FAILURE);
	}
	free_array(minish->env_array);
	minish->env_array = updated_env_array;
	return (EXIT_SUCCESS);
}

/*
 * @brief Forks and executes a new minishell instance.
 * @note The child process executes a new minishell,
 * while the parent waits for its completion.
 *
 * @param minish The minishell structure containing environment and state data.
 * @param path The path to the minishell executable.
 * @return int The exit status of the new minishell instance.
 */
static int	launch_new_minishell(t_minishell *minish, char *path)
{
	pid_t	pid;
	char	*argv[2];

	argv[0] = "./minishell";
	argv[1] = NULL;
	pid = fork();
	if (pid == 0)
		exec_new_minishell(path, argv, minish->env_array);
	return (handle_parent_process(minish, pid, path));
}

/*
 * @brief Handles the execution of a new instance of minishell (recursive call).
 * @note Updates SHLVL and captures the exit status of the new instance.
 *
 * @param minish The minishell structure containing environment and state data.
 * @return int The exit status of the new minishell instance.
 */
int	handle_new_minishell(t_minishell *minish)
{
	char	*path;
	char	**updated_env_array;
	int		prep_status;

	updated_env_array = NULL;
	updated_env_array = generate_env_array(minish->env_lst);
	if (!*updated_env_array)
	{
		perror("minishell: Failed to generate updated env_array");
		return (EXIT_FAILURE);
	}
	prep_status = prepare_new_minishell(minish, &path, updated_env_array);
	if (prep_status != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	prep_status = launch_new_minishell(minish, path);
	free(path);
	return (prep_status);
}
