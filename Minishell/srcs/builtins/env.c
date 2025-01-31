/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:18:24 by nryser            #+#    #+#             */
/*   Updated: 2025/01/08 23:20:00 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Prints the environment variables to the specified file descriptor.
 * @param node The command structure containing arguments and context.
 * @param minish The minishell structure containing environment variables.
 */
int	handle_env(t_command *node, t_minishell *minish)
{
	t_varlist	*tmp;

	(void)node;
	tmp = minish->env_lst;
	while (tmp)
	{
		if (tmp->var->vtype == ENV)
		{
			write(STDOUT_FILENO, tmp->var->vname, ft_strlen(tmp->var->vname));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, tmp->var->vvalue, ft_strlen(tmp->var->vvalue));
			write(STDOUT_FILENO, "\n", 1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/**
 * @brief Retrieves an environment variable's value by name.
 * @param minish The minishell structure containing environment variables.
 * @param name The name of the environment variable.
 * @return The value of the environment variable or NULL if not found.
 */
char	*get_env_var(t_minishell *minish, const char *name)
{
	t_varlist	*current;

	current = minish->env_lst;
	while (current)
	{
		if (ft_strncmp(current->var->vname, name, ft_strlen(name) + 1) == 0)
			return (current->var->vvalue);
		current = current->next;
	}
	return (NULL);
}

/**
 * @brief Sets an environment variable value by name.
 * Updates the value of an environment variable within the minishell structure.
 * @param minish The minishell structure containing environment variables.
 * @param name The name of the environment variable.
 * @param value The value to set for the environment variable.
 */
void	set_env_var(t_minishell *minish, const char *name, const char *value)
{
	t_varlist	*current;

	current = minish->env_lst;
	while (current)
	{
		if (ft_strncmp(current->var->vname, name, ft_strlen(name) + 1) == 0)
		{
			free(current->var->vvalue);
			current->var->vvalue = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
}
