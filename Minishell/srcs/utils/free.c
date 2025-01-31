/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:32:35 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 13:33:02 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

/**
 * @brief Frees a single environment variable
 * @param var the t_env variable to free
 */
void	free_var(t_env *var)
{
	if (var->vname)
		free(var->vname);
	if (var->vvalue)
		free(var->vvalue);
	free(var);
}

// /**
//  * @brief Frees the entire environment linked list
//  * @param minish the mother of all structs
//  */
// void	free_env(t_minishell *minish)
// {
// 	t_varlist	*tmp;
// 	t_varlist	*next;

// 	if (!minish->env_lst)
// 		return ;
// 	tmp = minish->env_lst;
// 	while (tmp)
// 	{
// 		next = tmp->next;
// 		if (tmp->var)
// 		{
// 			free_var(tmp->var);
// 			free(tmp);
// 		}
// 		tmp = next;
// 	}
// 	if (minish->env_array)
// 		free_array(minish->env_array);
// 	minish->env_lst = NULL;
// 	minish->env_array = NULL;
// }

void	free_varlist(t_varlist *list)
{
	t_varlist	*tmp;
	t_varlist	*next;

	if (!list)
		return ;
	tmp = list;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->var)
		{
			free_var(tmp->var);
			free(tmp);
		}
		tmp = next;
	}
	list = NULL;
}
