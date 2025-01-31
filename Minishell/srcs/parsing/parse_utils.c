/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:35:09 by nryser            #+#    #+#             */
/*   Updated: 2024/12/10 22:35:18 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Safely increments the current token to the next token
 */
void	increment_tok(t_args **curr_tok)
{
	if (!curr_tok || !(*curr_tok))
		return ;
	if ((*curr_tok)->next)
		*curr_tok = (*curr_tok)->next;
}

/**
 * @brief Counts the number of arguments in the linked list
 * @return the number of arguments - 1 (to not include the command)
 */
int	count_args(t_args *arg)
{
	int		count;
	t_args	*tmp;

	tmp = arg;
	count = 1;
	if (tmp->is_word && (!tmp->next || tmp->next->tok->type == PIPE))
		return (1);
	tmp = tmp->next;
	while (tmp && tmp->tok->type != PIPE)
	{
		if (tmp->is_word && tmp->tok->type != FILENAME)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

/**
 * @brief checks if type is any of four redirections: > >> < <<
 * @return TRUE or FALSE
 */
int	is_redir(t_tok type)
{
	if (!type)
		return (FALSE);
	if (type == REDIR_APPEND || type == REDIR_IN
		|| type == REDIR_OUT || type == HERE_DOC)
		return (TRUE);
	return (FALSE);
}

void	add_args_to_cmd(t_command *cmd_node, t_args *curr_tok, int arg_count)
{
	while (curr_tok && curr_tok->tok->type != PIPE)
	{
		if (curr_tok->is_word && curr_tok->tok->type != FILENAME)
		{
			cmd_node->args[arg_count] = ft_strdup(curr_tok->tok->value);
			arg_count++;
		}
		curr_tok = curr_tok->next;
	}
}

/**
 * @brief appends a command node to the leftmost node in the redir_ast chain
 * @param redir_ast the root redir_node in the redir_ast chain
 * @param cmd_node the command node to append to the leftmost node
 */
void	append_cmd(t_ast **redir_ast, t_ast *cmd_node)
{
	t_ast	*last_redir;

	last_redir = *redir_ast;
	if (!redir_ast || !cmd_node)
		return ;
	while (last_redir->left)
		last_redir = last_redir->left;
	last_redir->left = cmd_node;
}
