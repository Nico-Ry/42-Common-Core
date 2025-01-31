/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:08:48 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 14:08:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	extract_and_validate_var(char *var, char **name, char **value)
{
	*name = get_var_name(var);
	*value = get_var_value(var);
	if (!validate_identifier(*name))
	{
		ft_putstr_fd("miniHell: `", STDERR_FILENO);
		ft_putstr_fd((char *)*name, STDERR_FILENO);
		ft_putstr_fd("`: not a valid identifier\n", STDERR_FILENO);
		free(*name);
		free(*value);
		return (0);
	}
	return (1);
}

static void	handle_existing_var(t_minishell *minish, char *name, char *value)
{
	t_varlist	*local_var;
	t_varlist	*env_var;

	local_var = find_var(minish->local_vars, name);
	env_var = find_var(minish->env_lst, name);
	if (env_var)
	{
		if (value)
			update_variable_value(env_var, value);
	}
	else if (local_var)
	{
		if (local_var->var->vvalue)
			promote_variable(minish, name, local_var->var->vvalue);
		else
			local_var->var->vexported = 1;
	}
}

static void	add_new_variable(t_minishell *minish, char *name)
{
	t_varlist	*new_node;

	add_var(minish, name, NULL, LOCAL);
	new_node = ft_lstlast(minish->local_vars);
	if (new_node != NULL)
		new_node->var->vexported = 1;
}

/**
 * @brief Processes a variable assignment.
 * Adds or updates the variable in the environment.
 * @param minish Minishell structure.
 * @param name The name of the variable.
 * @param value The value of the variable.
 * @return 0 on success, 1 on error.
 */
static int	process_variable_assignment(t_minishell *minish,
				char *name, char *value)
{
	t_varlist	*env_var;
	t_varlist	*local_var;

	env_var = find_var(minish->env_lst, name);
	local_var = find_var(minish->local_vars, name);
	if (env_var || local_var)
		handle_existing_var(minish, name, value);
	else
	{
		if (value && *value)
			add_var(minish, name, value, ENV);
		else
			add_new_variable(minish, name);
	}
	free(name);
	free(value);
	return (0);
}

/**
 * @brief Exports a variable.
 * Adds or updates the variable in the environment.
 * @param minish Minishell structure.
 * @param var The variable to export.
 * @return 0 on success, 1 on error.
 */
int	export_var(t_minishell *minish, char *var)
{
	char		*name;
	char		*value;

	if (!extract_and_validate_var(var, &name, &value))
		return (1);
	process_variable_assignment(minish, name, value);
	return (0);
}
