/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_variable_assign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:34:23 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 18:34:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	extract_variable_name_value(char *arg, char **name, char **value)
{
	char	*equal_sign;

	equal_sign = ft_strchr(arg, '=');
	if (!equal_sign)
	{
		*name = ft_strdup(arg);
		*value = NULL;
		return (1);
	}
	*name = ft_substr(arg, 0, equal_sign - arg);
	*value = ft_strdup(equal_sign + 1);
	return (1);
}

static void	update_or_add_variable(t_minishell *minish,
				char *name, char *value, int exported)
{
	t_varlist	*env_var;
	t_varlist	*local_var;

	env_var = find_var(minish->env_lst, name);
	if (env_var)
	{
		update_variable_value(env_var, value);
		return ;
	}
	local_var = find_var(minish->local_vars, name);
	if (local_var)
	{
		update_variable_value(local_var, value);
		if (local_var->var->vexported || exported)
			promote_variable(minish, name, value);
	}
	else
	{
		add_var(minish, name, value, LOCAL);
		if (exported)
			promote_variable(minish, name, value);
	}
}

static int	process_variable_assignment(t_minishell *minish,
				char *arg, int exported)
{
	char		*name;
	char		*value;
	t_varlist	*local_var;

	if (!extract_variable_name_value(arg, &name, &value))
		return (0);
	if (!validate_identifier(name))
	{
		free(name);
		free(value);
		return (0);
	}
	local_var = find_var(minish->local_vars, name);
	if (value || (local_var && local_var->var->vexported) || exported)
		update_or_add_variable(minish, name, value, exported);
	else
		add_var(minish, name, value, LOCAL);
	free(name);
	free(value);
	return (1);
}

int	handle_variable_assignment(t_minishell *minish, t_command *cmd_data)
{
	int	i;
	int	has_assignments;
	int	exported;

	if (ft_strcmp(cmd_data->cmd, "echo") == 0)
		return (EXIT_FAILURE);
	has_assignments = 0;
	if (!cmd_data || !cmd_data->args)
		return (EXIT_FAILURE);
	exported = (ft_strcmp(cmd_data->cmd, "export") == 0);
	i = 0;
	while (cmd_data->args[i])
	{
		if (cmd_data->args[i][0] != '=' && ft_strchr(cmd_data->args[i], '='))
		{
			if (process_variable_assignment(minish,
					cmd_data->args[i], exported))
				has_assignments = 1;
		}
		i++;
	}
	if (has_assignments)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
