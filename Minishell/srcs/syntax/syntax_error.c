/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:34:29 by nryser            #+#    #+#             */
/*   Updated: 2025/01/26 02:34:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pipe_error(t_minishell *minish)
{
	printf("Syntax error near unexpected token '|'\n");
	free_arglst(minish);
	minish->arg_lst = NULL;
	minish->last_exit_status = 2;
	start_shell(minish);
}

void	redir_error(t_minishell *minish)
{
	printf("Syntax error near unexpected token\n");
	free_arglst(minish);
	minish->arg_lst = NULL;
	minish->last_exit_status = 2;
	start_shell(minish);
}

void	heredoc_error(t_minishell *minish)
{
	printf("Syntax error near unexpected token 'newline'\n");
	free_arglst(minish);
	minish->arg_lst = NULL;
	minish->last_exit_status = 2;
	start_shell(minish);
}
