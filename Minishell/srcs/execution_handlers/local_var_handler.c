/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:02:39 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 12:03:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_local_var(t_varlist **local_vars, const char *name)
{
	t_varlist	*prev;
	t_varlist	*current;

	prev = NULL;
	current = *local_vars;
	while (current)
	{
		if (ft_strcmp(current->var->vname, name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*local_vars = current->next;
			free_var(current->var);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	promote_variable(t_minishell *minish, const char *name, const char *value)
{
	t_varlist	*local_var;

	local_var = find_var(minish->local_vars, name);
	if (local_var)
	{
		if (!value)
			value = local_var->var->vvalue;
		add_or_update_env_var(minish, (char *)name, (char *)value);
		remove_local_var(&minish->local_vars, name);
	}
	return (0);
}

void	update_variable_value(t_varlist *var, char *value)
{
	if (var->var->vvalue)
		free(var->var->vvalue);
	var->var->vvalue = ft_strdup(value);
}

static int	update_existing_var(t_minishell *minish, char *name, char *value)
{
	t_varlist	*var;

	var = find_var(minish->local_vars, name);
	if (var)
	{
		update_variable_value(var, value);
		free(name);
		return (EXIT_SUCCESS);
	}
	var = find_var(minish->env_lst, name);
	if (var)
	{
		update_variable_value(var, value);
		free(name);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	handle_local_var(t_minishell *minish, const char *cmd)
{
	char	*name;
	char	*value;
	int		status;

	name = get_var_name(cmd);
	value = get_var_value(cmd);
	if (!name)
	{
		free(value);
		return (EXIT_FAILURE);
	}
	status = update_existing_var(minish, name, value);
	if (status == EXIT_SUCCESS)
		return (status);
	add_var(minish, name, value, LOCAL);
	free(name);
	return (EXIT_SUCCESS);
}
