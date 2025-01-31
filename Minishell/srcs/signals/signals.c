/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:22:56 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 13:23:28 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief This global variable stores the last received signal's status.
 * sig_atomic_t ensures this variable is
 * updated correctly even in the presence of interrupts (signals).
 */
volatile sig_atomic_t	g_signal_status = 0;

/**
 * @brief Signal handler for child processes (e.g., during execution).
 * Sets appropriate exit codes for SIGINT and SIGQUIT.
 * @param signum Signal number.
 */
void	child_handle_sigint(int signum)
{
	if (signum == SIGINT)
		g_signal_status = 130;
	else
	{
		ft_putstr_fd("Quit", 1);
		g_signal_status = 131;
	}
}

/**
 * @brief Sets up signal handling for heredoc mode.
 * Ensures Ctrl-C interrupts heredoc correctly.
 */
void	setup_heredoc_signals(void)
{
	struct sigaction	act;

	act.sa_handler = &handle_sigint_heredoc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);
}

/**
 * @brief Sets up signal handlers for the parent process.
 * Ensures appropriate handling of Ctrl-C and Ctrl-\.
 */
void	setup_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = &handle_sigint;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigquit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

/**
 * @brief Sets up signal handlers for child processes during command execution.
 * Prevents interruption of the shell by child processes
 * and suppresses Ctrl-\ output.
 */
void	setup_child_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = &child_handle_sigint;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigquit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}
