/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:37:24 by nryser            #+#    #+#             */
/*   Updated: 2025/01/28 23:38:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	check_token_syntax(t_args *current, int *error)
{
	t_tok	type;

	type = current->tok->type;
	if (type == PIPE)
		pipe_syntax(current, error);
	else if (type == REDIR_OUT || type == REDIR_APPEND || type == REDIR_IN)
		redir_syntax(current, error);
	else if (type == HERE_DOC)
		heredoc_syntax(current, error);
}

int	syntax_check(t_minishell *minish)
{
	t_args	*current;
	int		error;

	error = 0;
	current = minish->arg_lst;
	if (!current)
		return (0);
	while (current)
	{
		if (error == 1)
			break ;
		check_token_syntax(current, &error);
		current = current->next;
	}
	if (error == 1)
	{
		minish->last_exit_status = 2;
		return (minish->last_exit_status);
	}
	return (1);
}

void	pipe_syntax(t_args *arg, int *error)
{
	if (!arg->next || !arg->prev)
	{
		printf("Syntax error near unexpected token '|'\n");
		*error = 1;
		return ;
	}
	if (!(arg->prev->is_word) || !(arg->next->is_word))
	{
		printf("Syntax error near unexpected token '|'\n");
		*error = 1;
		return ;
	}
}

void	redir_syntax(t_args *arg, int *error)
{
	t_tok	next;
	char	*value;

	value = arg->tok->value;
	if (!arg->next)
	{
		printf("Syntax error near unexpected token '%s'\n", value);
		*error = 1;
		return ;
	}
	next = arg->next->tok->type;
	if (next == ENV_VAR || next == LOC_VAR || !(arg->next->is_word))
	{
		printf("Syntax error near unexpected token '%s'\n", value);
		*error = 1;
		return ;
	}
}

void	heredoc_syntax(t_args *arg, int *error)
{
	if (!arg->next || !arg->next->is_word)
	{
		printf("Syntax error near unexpected token 'newline'\n");
		*error = 1;
	}
}
