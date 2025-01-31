/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:55:48 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 12:37:32 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	create_heredoc_tempfile(t_redir *dir)
{
	char	*temp_file;

	temp_file = generate_temp_file_name();
	if (!temp_file)
	{
		ft_putstr_fd("minishell: failed to generate temp file\n", 2);
		return (0);
	}
	dir->temp_file = temp_file;
	return (1);
}

static void	handle_heredoc_child(t_redir *dir, t_minishell *minish)
{
	int	fd;

	fd = open(dir->temp_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell: heredoc open failed");
		free(dir->temp_file);
		exit(EXIT_FAILURE);
	}
	setup_heredoc_signals();
	get_heredoc_line(fd, dir, minish);
	close(fd);
	exit(minish->last_exit_status);
}

static void	open_heredoc(t_redir *dir, t_minishell *minish)
{
	pid_t	pid;
	int		status;

	if (!create_heredoc_tempfile(dir))
		return ;
	pid = fork();
	if (pid == 0)
		handle_heredoc_child(dir, minish);
	waitpid(pid, &status, 0);
	update_exit_status(minish, status);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		unlink(dir->temp_file);
		free(dir->temp_file);
		dir->temp_file = NULL;
		minish->last_exit_status = 130;
	}
}

/*@brief: This function is used to preprocess heredocs in the AST.
** It will open the temp file for the heredoc and store the file descriptor
** in the redir_data struct.
** If the file cannot be opened, the function will return EXIT_FAILURE.
** If the function is interrupted by a signal, it will return 130.
*/
int	preprocess_heredocs(t_minishell *minish, t_ast *ast)
{
	t_redir	*redir_data;

	if (!ast)
		return (EXIT_SUCCESS);
	if (ast->type == PIPE_NODE)
	{
		if (preprocess_heredocs(minish, ast->left) == 130)
			return (130);
		if (preprocess_heredocs(minish, ast->right) == 130)
			return (130);
		return (EXIT_SUCCESS);
	}
	if (ast->type == REDIRECTION_NODE)
	{
		redir_data = (t_redir *)ast->data;
		if (redir_data->type == HERE_DOC && !redir_data->temp_file)
		{
			open_heredoc(redir_data, minish);
			if (g_signal_status == 130)
				return (minish->last_exit_status = 130);
			if (!redir_data->temp_file)
				return (EXIT_FAILURE);
		}
	}
	return (preprocess_heredocs(minish, ast->left));
}

void	handle_heredoc_redirection(t_redir *redir_data, t_minishell *minish)
{
	int	fd;

	if (!redir_data->temp_file || access(redir_data->temp_file, F_OK) != 0)
	{
		if (minish->last_exit_status == 130)
			return ;
		return ;
	}
	fd = open(redir_data->temp_file, O_RDONLY);
	if (fd == -1)
	{
		perror("minishell: open");
		return ;
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("minishell: ");
		close(fd);
		return ;
	}
	close(fd);
}
