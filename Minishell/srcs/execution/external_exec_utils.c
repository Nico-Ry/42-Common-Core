/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_exec_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:13:59 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 11:14:05 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * @brief Joins a directory path and a command
 * name to form a full executable path.
 *
 * @param dir The directory path.
 * @param command The command name.
 * @return char* The full path to the command, or NULL on failure.
 */
char	*path_join(const char *dir, const char *command)
{
	size_t	len_dir;
	size_t	len_cmd;
	char	*full_path;

	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(command);
	full_path = malloc(len_dir + len_cmd + 2);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, dir);
	full_path[len_dir] = '/';
	ft_strcpy(full_path + len_dir + 1, command);
	return (full_path);
}

/*
 * @brief Searches for the executable in the custom PATH environment variable.
 * @note If the command is not found, returns NULL.
 *
 * @param cmd The command to search for.
 * @param env_lst The linked list of environment variables.
 * @param minish The minishell structure containing environment and state data.
 * @return char* The full path to the executable or NULL if not found.
 */
char	*find_executable(const char *cmd,
			t_varlist *env_lst, t_minishell *minish)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	path_env = get_path_from_env(env_lst);
	if (!path_env || !*path_env)
		return (ft_strdup(cmd));
	paths = ft_split(path_env, ':');
	i = 0;
	while (paths[i])
	{
		full_path = path_join(paths[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_array(paths);
	minish->last_exit_status = UNKNOWN_COMMAND;
	return (NULL);
}

static char	**allocate_env_array(t_varlist *env_lst, int *count)
{
	t_varlist	*tmp;
	char		**env_array;

	*count = 0;
	tmp = env_lst;
	while (tmp)
	{
		if (tmp->var->vtype == ENV)
			(*count)++;
		tmp = tmp->next;
	}
	env_array = malloc(sizeof(char *) * (*count + 1));
	if (!env_array)
		return (NULL);
	return (env_array);
}

/*
 * @brief Converts the linked list of environment variables to an array.
 * @note The array is NULL-terminated.
 *
 * @param env_lst The linked list of environment variables.
 * @return char** The array of environment variables.
 */
char	**convert_env_to_array(t_varlist *env_lst)
{
	int			count;
	char		**env_array;
	t_varlist	*tmp;
	int			i;

	env_array = allocate_env_array(env_lst, &count);
	if (!env_array)
		return (NULL);
	tmp = env_lst;
	i = 0;
	while (tmp)
	{
		if (tmp->var->vtype == ENV)
		{
			env_array[i] = ft_strjoin_three(
					tmp->var->vname, "=", tmp->var->vvalue);
			i++;
		}
		tmp = tmp->next;
	}
	env_array[i] = NULL;
	return (env_array);
}
