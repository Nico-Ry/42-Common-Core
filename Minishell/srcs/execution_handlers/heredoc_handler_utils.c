/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:23:14 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 00:24:10 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_heredoc_putstr(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
	write(fd, "\n", 1);
}

void	handle_heredoc_interrupt(int fd, t_redir *dir, t_minishell *minish)
{
	close(fd);
	unlink(dir->temp_file);
	minish->last_exit_status = 130;
	g_signal_status = 0;
}

void	print_heredoc_eof_warning(t_redir *dir, t_minishell *minish)
{
	ft_putstr_fd("minishell: warning: ", 2);
	ft_putstr_fd("here-document delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(dir->file, 2);
	ft_putstr_fd("')\n", 2);
	minish->last_exit_status = 0;
}

void	process_heredoc_input(int fd, t_redir *dir, t_minishell *minish)
{
	char	*heredoc;

	while (1)
	{
		if (g_signal_status == 130)
		{
			handle_heredoc_interrupt(fd, dir, minish);
			break ;
		}
		heredoc = readline("> ");
		if (!heredoc)
		{
			print_heredoc_eof_warning(dir, minish);
			break ;
		}
		if (ft_strcmp(heredoc, dir->file) == 0)
		{
			free(heredoc);
			break ;
		}
		ft_heredoc_putstr(heredoc, fd);
		free(heredoc);
	}
}

void	get_heredoc_line(int fd, t_redir *dir, t_minishell *minish)
{
	setup_heredoc_signals();
	process_heredoc_input(fd, dir, minish);
	close(fd);
	setup_signals();
}
