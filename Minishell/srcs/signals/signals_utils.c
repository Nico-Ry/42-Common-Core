/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:23:34 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 13:23:34 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Signal handler for SIGINT (Ctrl-C) during heredoc.
 * @param signum Signal number.
 */
void	handle_sigint_heredoc(int signum)
{
	(void)signum;
	g_signal_status = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	rl_done = 1;
}

/**
 * @brief Signal handler for Ctrl-C (SIGINT).
 * Updates the g_signal_status and the shell's last_exit_status.
 * @param signum Signal number.
 */
void	handle_sigint(int signum)
{
	(void)signum;
	g_signal_status = 130;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/**
 * @brief Handles Ctrl-D (EOF) and exits the shell if no input is present.
 * Performs cleanup before exiting.
 * @param input Input string.
 * @param minish The minishell structure.
 */
void	handle_ctrl_d(char *input, t_minishell *minish)
{
	if (!input)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		cleanup_minishell(minish);
		exit(0);
	}
}
