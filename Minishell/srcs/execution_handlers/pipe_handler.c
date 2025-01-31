/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:12:25 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 20:26:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	execute_left_child(t_minishell *minish, t_ast *ast, int pipe_fds[2])
{
	close(pipe_fds[0]);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[1]);
	handle_redirections_child(ast->left, minish);
	execute_cmd(minish, ast->left);
	exit(minish->last_exit_status);
}

static void	execute_right_child(t_minishell *minish,
				t_ast *ast, int pipe_fds[2])
{
	close(pipe_fds[1]);
	dup2(pipe_fds[0], STDIN_FILENO);
	close(pipe_fds[0]);
	handle_redirections_child(ast->right, minish);
	execute_cmd(minish, ast->right);
	exit(minish->last_exit_status);
}

int	setup_pipe_and_first_child(t_minishell *minish,
		t_ast *ast, int pipe_fds[2], pid_t *pid1)
{
	if (pipe(pipe_fds) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	*pid1 = fork();
	if (*pid1 == -1)
		return (perror("fork"), EXIT_FAILURE);
	if (*pid1 == 0)
		execute_left_child(minish, ast, pipe_fds);
	return (EXIT_SUCCESS);
}

int	create_second_child(t_minishell *minish, t_ast *ast,
		int pipe_fds[2], pid_t *pid2)
{
	*pid2 = fork();
	if (*pid2 == -1)
		return (perror("fork"), EXIT_FAILURE);
	if (*pid2 == 0)
		execute_right_child(minish, ast, pipe_fds);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	return (EXIT_SUCCESS);
}

int	execute_pipe(t_minishell *minish, t_ast *ast)
{
	int		pipe_fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (setup_pipe_and_first_child(minish, ast,
			pipe_fds, &pid1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_second_child(minish, ast, pipe_fds, &pid2) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	waitpid(pid1, NULL, 0);
	if (waitpid(pid2, &minish->last_exit_status, 0) == -1)
	{
		perror("minishell: Error waiting for child minishell");
		minish->last_exit_status = EXIT_FAILURE;
	}
	else
	{
		if (WIFEXITED(minish->last_exit_status))
			minish->last_exit_status = WEXITSTATUS(minish->last_exit_status);
		else
			minish->last_exit_status = EXIT_FAILURE;
	}
	return (minish->last_exit_status);
}
