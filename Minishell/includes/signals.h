/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:34:06 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 23:37:30 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

typedef struct s_minishell		t_mish;
/* Store the signal number */
extern volatile sig_atomic_t	g_signal_status;

//signals_utils.c

void							handle_sigint_heredoc(int signum);
void							handle_sigint(int signum);
void							handle_ctrl_d(char *input, t_mish *minish);

//signals.c

void							setup_heredoc_signals(void);
void							setup_signals(void);
void							setup_child_signals(void);

#endif
