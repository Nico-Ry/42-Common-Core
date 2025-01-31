/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:53:21 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 16:53:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/**
 * @brief reads from the first '=' in the string and
 * returns everything after it (the variable value)
 * @param str the string to read
 */
char	*get_var_value(const char *cmd)
{
	const char	*value_start;

	value_start = ft_strchr(cmd, '=');
	if (value_start)
		return (ft_strdup(value_start + 1));
	else
		return (ft_strdup(""));
}

/**
 * @brief reads up to the first '=' in the string and
 * returns everything before it (the variable name)
 * @param str the string to read
 */
char	*get_var_name(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_substr(str, 0, i));
}

static t_env	*prepare_var(t_minishell *minish, char *name,
							char *value, t_vtype type)
{
	t_env	*var;

	var = malloc(sizeof(t_env));
	if (!var)
		ft_error(minish, "malloc");
	var->vname = ft_strdup(name);
	if (!var->vname)
		ft_error(minish, "malloc");
	if (value)
	{
		var->vvalue = ft_strdup(value);
		if (!var->vvalue)
			ft_error(minish, "malloc");
	}
	else
		var->vvalue = NULL;
	var->vtype = type;
	var->vexported = 0;
	return (var);
}

/**
 * @brief Adds a new environment variable to the linked list
 * filling all appropriate fields (name, value, type)
 * @param minish the mother of all structs
 * @param name the name of the variable
 * @param value the value of the variable
 * @param type the type of the variable (ENV or LOCAL)
 */
void	add_var(t_minishell *minish, char *name, char *value, t_vtype type)
{
	t_varlist	*new_node;
	t_varlist	**target_list;
	t_env		*var;

	if (type == LOCAL)
		target_list = &minish->local_vars;
	else if (type == ENV)
		target_list = &minish->env_lst;
	else
		return ;
	var = prepare_var(minish, name, value, type);
	new_node = ft_lstnew(var);
	if (!new_node)
		ft_error(minish, "malloc");
	ft_lstadd_back(target_list, new_node);
}

/**
 * @brief Parses the environment variables and stores them in a linked list
 * @param minish the mother of all structs
 * @param env_array copy of envp
 */
void	parse_env(t_minishell *minish, char **env_array)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (env_array[i])
	{
		name = get_var_name(env_array[i]);
		if (!name)
			ft_error(minish, "malloc");
		value = get_var_value(env_array[i]);
		if (!value)
			ft_error(minish, "malloc");
		add_var(minish, name, value, ENV);
		free(name);
		free(value);
		i++;
	}
}
