/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_chain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:24:19 by nryser            #+#    #+#             */
/*   Updated: 2025/01/08 17:24:19 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//called when curr_tok is redirection
/**
 * @brief creates a chain of redirection nodes, storing each new
 * redirection node as the left child of the previous node
 */

t_ast	*make_redir_chain(t_args **curr_tok)
{
	t_ast	*redir_ast;
	t_ast	*last_redir;
	t_ast	*redir_chain;

	last_redir = NULL;
	redir_chain = NULL;
	if (!curr_tok || !(*curr_tok))
		return (NULL);
	while ((*curr_tok)->tok->type != PIPE && (*curr_tok)->next)
	{
		if (is_redir((*curr_tok)->tok->type))
		{
			redir_ast = fill_redir_info(curr_tok);
			if (!redir_ast)
				return (NULL);
			if (!redir_chain)
				redir_chain = redir_ast;
			else
				last_redir->left = redir_ast;
			last_redir = redir_ast;
		}
		else
			increment_tok(curr_tok);
	}
	return (redir_chain);
}

/**
 * @brief creates a redirection node and fills it with the type and file
 * of the redirection operator and the filename that follows it
 */
t_ast	*fill_redir_info(t_args **curr_tok)
{
	t_ast	*redir_ast;
	t_redir	*redir_node;

	if (!curr_tok || !(*curr_tok))
		return (NULL);
	redir_ast = new_ast_node();
	redir_node = new_redir_node();
	if (!redir_ast || !redir_node)
		return (NULL);
	redir_node->type = (*curr_tok)->tok->type;
	increment_tok(curr_tok);
	redir_node->file = ft_strdup((*curr_tok)->tok->value);
	redir_ast->data = redir_node;
	redir_ast->type = REDIRECTION_NODE;
	redir_ast->left = NULL;
	redir_ast->right = NULL;
	increment_tok(curr_tok);
	return (redir_ast);
}

/**
 * @brief resets the token back to the first* token of the command line
 * and returns the first token that is a word
 * (other than filenames after redirs)
 * @note *Only goes back as far as the first PIPE token it encounters,
 * to avoid parsing the same thing twice
 */
t_args	**find_cmd_tok(t_args **curr_tok)
{
	if (!curr_tok || !(*curr_tok))
		return (NULL);
	while ((*curr_tok)->prev && (*curr_tok)->prev->tok->type != PIPE)
		*curr_tok = (*curr_tok)->prev;
	if ((*curr_tok)->tok->type == WORD)
		return (curr_tok);
	while ((*curr_tok)->tok->type != WORD && (*curr_tok)->next)
		increment_tok(curr_tok);
	return (curr_tok);
}

/**
 * @brief finds and sets curr_tok to the next pipe token if any
 */
t_args	**find_next_pipe(t_args **curr_tok)
{
	t_args	**tmp;

	if (!curr_tok || !(*curr_tok))
		return (NULL);
	tmp = curr_tok;
	while (tmp && (*tmp)->next)
	{
		if ((*tmp)->tok->type == PIPE)
			return (tmp);
		*tmp = (*tmp)->next;
	}
	return (NULL);
}
