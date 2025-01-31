/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:27:06 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 11:27:06 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Adds a new element to the end of the linked list
 * @param alst the linked list
 * @param new the new element to add
 */
void	ft_lstadd_back(t_varlist **alst, t_varlist *new)
{
	t_varlist	*last;

	if (!alst)
		return ;
	last = ft_lstlast(*alst);
	if (!last)
		*alst = new;
	else
		last->next = new;
}

/**
 * @brief Returns the last element of the linked list
 * @param lst the linked list
 */
t_varlist	*ft_lstlast(t_varlist *lst)
{
	t_varlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/**
 * @brief Creates a new element of the linked list
 * @param content the t_env *var to store in the linked list
 */
t_varlist	*ft_lstnew(void *content)
{
	t_varlist	*elem;

	elem = malloc(sizeof(t_varlist));
	if (!elem)
		return (NULL);
	elem->var = content;
	elem->next = NULL;
	return (elem);
}

/**
 * @brief Finds a variable by name in the specified variable list.
 *
 * @param var_list The linked list of variables (local_vars or env_lst).
 * @param name The name of the variable to search for.
 * @return t_varlist* A pointer to the variable node, or NULL if not found.
 */
t_varlist	*find_var(t_varlist *var_list, const char *name)
{
	while (var_list)
	{
		if (ft_strcmp(var_list->var->vname, name) == 0)
			return (var_list);
		var_list = var_list->next;
	}
	return (NULL);
}

/**
 * @brief Counts and returns the size of the envp
 * @param envp array of environment variables provided by the system
 */
ssize_t	get_env_size(char **envp)
{
	ssize_t	size;

	size = 0;
	while (envp[size])
		size++;
	return (size);
}
