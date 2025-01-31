/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:01:47 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 22:01:47 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	handle_file_redirection_parent(t_redir *redir_data,
			int fd_backup[2], int std_fd)
{
	int	fd;
	int	flags;

	backup_original_fd(fd_backup, std_fd);
	flags = O_RDONLY;
	if (std_fd == STDOUT_FILENO)
	{
		flags = O_WRONLY | O_CREAT;
		if (redir_data->type == REDIR_OUT)
			flags |= O_TRUNC;
		else
			flags |= O_APPEND;
	}
	fd = open(redir_data->file, flags, 0644);
	if (fd < 0 || dup2(fd, std_fd) < 0)
	{
		perror("Error setting up redirection");
		if (fd >= 0)
			close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	handle_redirections_parent(t_ast *ast, int fd_backup[2])
{
	t_ast	*redir;
	t_redir	*redir_data;
	int		status;

	redir = ast;
	while (redir && redir->type == REDIRECTION_NODE)
	{
		redir_data = (t_redir *)redir->data;
		if (redir_data->type == REDIR_OUT || redir_data->type == REDIR_APPEND)
			status = handle_file_redirection_parent(redir_data,
					fd_backup, STDOUT_FILENO);
		else if (redir_data->type == REDIR_IN)
			status = handle_file_redirection_parent(redir_data,
					fd_backup, STDIN_FILENO);
		if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redir = redir->left;
	}
	return (EXIT_SUCCESS);
}

static void	handle_file_redirection_child(t_redir *redir_data,
				int std_fd, t_minishell *minish)
{
	int	fd;
	int	flags;

	flags = O_RDONLY;
	if (std_fd == STDOUT_FILENO)
	{
		flags = O_WRONLY | O_CREAT;
		if (redir_data->type == REDIR_OUT)
			flags |= O_TRUNC;
		else
			flags |= O_APPEND;
	}
	fd = open(redir_data->file, flags, 0644);
	if (fd == -1 || dup2(fd, std_fd) == -1)
	{
		perror("minishell: ");
		if (fd >= 0)
			close(fd);
		if (minish->last_exit_status == 130)
			exit(130);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static void	process_redirection(t_redir *redir_data, t_minishell *minish)
{
	if (redir_data->type == HERE_DOC)
		handle_heredoc_redirection(redir_data, minish);
	else if (redir_data->type == REDIR_OUT || redir_data->type == REDIR_APPEND)
		handle_file_redirection_child(redir_data, STDOUT_FILENO, minish);
	else if (redir_data->type == REDIR_IN)
		handle_file_redirection_child(redir_data, STDIN_FILENO, minish);
}

int	handle_redirections_child(t_ast *ast, t_minishell *minish)
{
	t_ast	*redir;

	redir = ast;
	while (redir && redir->type == REDIRECTION_NODE)
	{
		process_redirection((t_redir *)redir->data, minish);
		redir = redir->left;
	}
	return (EXIT_SUCCESS);
}
