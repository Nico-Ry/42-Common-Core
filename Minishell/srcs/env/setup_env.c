/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:08:54 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 09:08:54 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief creates a copy of envp and stores it in minishell->env_array
 * @param minish the mother of all structs
 * @param envp array of environment variables provided by the system
 */
void	duplicate_envp(t_minishell *minish, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		minish->env_array[i] = ft_strdup(envp[i]);
		i++;
	}
}

/**
 * @brief Readys the environment variables for parsing
 * @param minish the mother of all structs
 * @param envp array of environment variables provided by the system
 */
void	setup_env(char **envp, t_minishell *minish)
{
	minish->env_size = get_env_size(envp);
	minish->env_array = malloc(sizeof(char *) * (minish->env_size + 1));
	if (!minish->env_array)
		ft_error(minish, "malloc");
	minish->env_array[minish->env_size] = NULL;
	duplicate_envp(minish, envp);
	parse_env(minish, minish->env_array);
	increment_shlvl(minish);
}
	// print_env_all_type(minish->env_lst);

void	increment_shlvl(t_minishell *minish)
{
	t_varlist	*shlvl;
	int			new_lvl;
	char		*new_lvl_str;

	shlvl = find_var(minish->env_lst, "SHLVL");
	if (!shlvl)
	{
		add_var(minish, ft_strdup("SHLVL"), ft_strdup("1"), ENV);
		return ;
	}
	new_lvl = ft_atoi(shlvl->var->vvalue) + 1;
	new_lvl_str = ft_itoa(new_lvl);
	if (!new_lvl_str)
		ft_error(minish, "malloc");
	free(shlvl->var->vvalue);
	shlvl->var->vvalue = new_lvl_str;
}

static void	populate_env_array(t_varlist *env_lst, char **env_array)
{
	t_varlist	*current;
	int			i;
	char		*tmp;

	current = env_lst;
	i = 0;
	while (current)
	{
		if (current->var->vtype == ENV)
		{
			tmp = ft_strjoin(current->var->vname, "=");
			env_array[i] = ft_strjoin(tmp, current->var->vvalue);
			free(tmp);
			i++;
		}
		current = current->next;
	}
	env_array[i] = NULL;
}

char	**generate_env_array(t_varlist *env_lst)
{
	int			env_count;
	char		**env_array;
	t_varlist	*current;

	env_count = 0;
	current = env_lst;
	env_array = NULL;
	while (current)
	{
		if (current->var->vtype == ENV)
			env_count++;
		current = current->next;
	}
	env_array = malloc(sizeof(char *) * (env_count + 1));
	if (!env_array)
	{
		perror("generate_env_array: malloc failed");
		return (NULL);
	}
	populate_env_array(env_lst, env_array);
	return (env_array);
}
