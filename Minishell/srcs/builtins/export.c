/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:21:19 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 14:21:19 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Finds the value of a variable by name.
 * Searches both local and environment variables.
 * @param minish Minishell structure.
 * @param name The name of the variable.
 * @return The value of the variable, or NULL if not found.
 */
char	*find_var_value(t_minishell *minish, const char *name)
{
	t_varlist	*local;
	t_varlist	*env;

	local = minish->local_vars;
	env = minish->env_lst;
	while (local)
	{
		if (ft_strcmp(local->var->vname, name) == 0)
			return (ft_strdup(local->var->vvalue));
		local = local->next;
	}
	while (env)
	{
		if (ft_strcmp(env->var->vname, name) == 0)
			return (ft_strdup(env->var->vvalue));
		env = env->next;
	}
	return (NULL);
}

int	add_or_update_env_var(t_minishell *minish, char *name, char *value)
{
	t_varlist	*current;

	current = minish->env_lst;
	while (current)
	{
		if (ft_strcmp(current->var->vname, name) == 0)
		{
			free(current->var->vvalue);
			current->var->vvalue = ft_strdup(value);
			current->var->vtype = ENV;
			return (0);
		}
		current = current->next;
	}
	add_var(minish, name, value, ENV);
	return (0);
}

static void	print_single_exported_var(t_varlist *var)
{
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(var->var->vname, STDOUT_FILENO);
	if (var->var->vvalue)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(var->var->vvalue, STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

/**
 * @brief Prints all exported environment variables.
 * @param minish Minishell structure.
 */
void	print_exported_env(t_minishell *minish)
{
	t_varlist	*tmp;
	t_varlist	*local;

	tmp = minish->env_lst;
	while (tmp)
	{
		print_single_exported_var(tmp);
		tmp = tmp->next;
	}
	local = minish->local_vars;
	while (local)
	{
		if (local->var->vexported)
			print_single_exported_var(local);
		local = local->next;
	}
}

/**
 * @brief Handles the 'export' built-in command.
 * Adds or updates environment variables.
 * @param node The command node.
 * @param minish Minishell structure.
 * @return 0 on success, 1 on error.
 */
int	handle_export(t_command *node, t_minishell *minish)
{
	int	i;
	int	status;

	status = 0;
	if (!node->args[1])
	{
		print_exported_env(minish);
		return (0);
	}
	i = 1;
	while (node->args[i])
	{
		if (export_var(minish, node->args[i]) == 1)
			status = 1;
		i++;
	}
	return (status);
}
