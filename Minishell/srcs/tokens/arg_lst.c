/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:39:24 by nryser            #+#    #+#             */
/*   Updated: 2025/01/28 23:39:24 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Returns the last node of the arg_lst linked list
 * @param arg_lst the linked list of all tokens
 */
t_args	*arg_lstlast(t_args *arg_lst)
{
	t_args	*tmp;

	if (!arg_lst)
		return (NULL);
	tmp = arg_lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/**
 * @brief Adds a new_node to the end of the arg_lst linked list
 * @param arg_lst the linked list of all tokens
 * @param new_node the new token to add
 */
void	arg_lstadd_back(t_args **arg_lst, t_args *new_node)
{
	t_args	*last;

	if (!arg_lst)
		return ;
	last = arg_lstlast(*arg_lst);
	if (!last)
		*arg_lst = new_node;
	else
	{
		last->next = new_node;
		new_node->prev = last;
	}
}

/**
 * @brief Creates a new_node for the arg_lst linked list,
 * adding a t_word *token node to it and initialising its
 * next and prev pointers to NULL
 * @param tok the token to add to the linked list
 */
t_args	*arg_lstnew(t_word *tok)
{
	t_args	*new_node;

	new_node = malloc(sizeof(t_args));
	if (!new_node)
		return (NULL);
	new_node->tok = tok;
	new_node->is_word = FALSE;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * @brief Sets index, value and type of token and adds it to the
 * arg_lst linked list in minish
 * @param minish the mother of all structs
 * @param arg the token's value
 * @param type the token's type
 * @param i the token's index
 */
void	add_arg_lst(t_minishell *minish, char *arg, t_tok type, int i)
{
	t_word	*tok;
	t_args	*new_node;

	tok = malloc(sizeof(t_word));
	if (!tok)
		ft_error(minish, "malloc");
	tok->i = i;
	tok->value = arg;
	tok->type = type;
	new_node = arg_lstnew(tok);
	if (type == LOC_VAR || type == WORD)
		new_node->is_word = TRUE;
	arg_lstadd_back(&minish->arg_lst, new_node);
}
