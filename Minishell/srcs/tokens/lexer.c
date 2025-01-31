/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:42:44 by nryser            #+#    #+#             */
/*   Updated: 2025/01/28 23:43:51 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_lexer(t_minishell *minish)
{
	int		i;
	t_tok	type;
	char	*processed_token;

	i = 0;
	type = NONE;
	minish->input_line = clean_input(&minish->input_line);
	if (!split_args(minish, minish->input_line))
		return (minish->last_exit_status);
	while (minish->args[i])
	{
		processed_token = process_token(minish, minish->args[i]);
		if (!processed_token)
			return (0);
		type = identify_token(processed_token);
		if (type == UFO)
			return (0);
		add_arg_lst(minish, processed_token, type, i);
		i++;
	}
	find_files(minish->arg_lst);
	return (1);
}

int	split_args(t_minishell *minish, char *input)
{
	int	i;

	i = 0;
	if (find_quotes(input))
	{
		if (!quotes_complete(input))
		{
			printf("Quotes are not complete\n");
			minish->last_exit_status = 2;
			return (0);
		}
		remove_spaces(input);
	}
	minish->args = ft_split(input, ' ');
	while (minish->args[i])
	{
		restore_spaces(minish->args[i]);
		i++;
	}
	return (1);
}

/**
 * @brief Finds redirection operators in the argument list and changes the type
 * of the next token to FILENAME (If it is a WORD)
 */
void	find_files(t_args *arg_lst)
{
	t_args	*current;

	current = arg_lst;
	while (current)
	{
		if (current->tok->type == REDIR_OUT
			|| current->tok->type == REDIR_APPEND
			|| current->tok->type == REDIR_IN
			|| current->tok->type == HERE_DOC)
		{
			if (current->next && current->next->is_word)
				current->next->tok->type = FILENAME;
		}
		current = current->next;
	}
}
