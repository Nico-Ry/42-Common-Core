/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:34:56 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 18:35:04 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Removes a variable from the environment.
 * This function searches for the variable by name in the linked list
 * and removes it if found.
 * @param minish The minishell structure containing environment variables.
 * @param name The name of the variable to unset.
 */
int	unset_var(t_minishell *minish, const char *name)
{
	t_varlist	*current;
	t_varlist	*prev;

	if (!minish || !minish->env_lst || !name)
		return (1);
	prev = NULL;
	current = minish->env_lst;
	while (current)
	{
		if (ft_strcmp(current->var->vname, name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				minish->env_lst = current->next;
			free(current->var->vname);
			free(current->var->vvalue);
			free(current->var);
			free(current);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

static int	unset_local(t_minishell *minish, const char *name)
{
	t_varlist	*current;
	t_varlist	*prev;

	if (!minish || !minish->local_vars || !name)
		return (1);
	prev = NULL;
	current = minish->local_vars;
	while (current)
	{
		if (ft_strcmp(current->var->vname, name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				minish->local_vars = current->next;
			free(current->var->vname);
			free(current->var->vvalue);
			free(current->var);
			free(current);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

/**
 * @brief Handles the unset command.
 * This function processes each argument passed to the unset command
 * and calls unset_var for each variable name.
 * @param node The command structure containing arguments.
 * @param minish The minishell structure containing environment variables.
 */
int	handle_unset(t_command *node, t_minishell *minish)
{
	int	i;

	i = 1;
	while (node->args[i])
	{
		unset_var(minish, node->args[i]);
		i++;
	}
	i = 1;
	while (node->args[i])
	{
		unset_local(minish, node->args[i]);
		i++;
	}
	return (0);
}
