/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:13:43 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 10:13:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Checks if the given variable name is valid.
 * A valid name starts with a letter or underscore,
 * followed by alphanumeric characters or underscores.
 *
 * @param name The variable name to validate.
 * @return int 1 if valid, 0 otherwise.
 */
int	is_valid_identifier(const char *name)
{
	const char	*ptr;

	if (!name || !(*name))
		return (0);
	if (!(ft_isalpha(*name) || *name == '_'))
		return (0);
	ptr = name + 1;
	while (*ptr)
	{
		if (!(ft_isalnum(*ptr) || *ptr == '_'))
			return (0);
		ptr++;
	}
	return (1);
}

int	validate_identifier(const char *identifier)
{
	if (!is_valid_identifier(identifier))
		return (0);
	return (1);
}

/*
 * @brief Checks if the given path is a valid executable file.
 * @param cmd The command structure containing the path.
 * @return 1 if valid, 0 otherwise.
 */
int	is_valid_executable_path(t_command *cmd)
{
	struct stat	path_stat;

	if (lstat(cmd->cmd, &path_stat) == 0)
	{
		if (S_ISREG(path_stat.st_mode)
			&& access(cmd->cmd, X_OK) == 0)
			return (1);
	}
	return (0);
}

/*
 * @brief Checks if the command path is treating a file as a directory.
 * @param cmd The command structure containing the path.
 * @return 1 if invalid usage (Not a directory), 0 otherwise.
 */
int	is_invalid_directory_usage(t_command *cmd)
{
	struct stat	path_stat;
	char		*dir_path;

	if (!cmd->cmd)
		return (0);
	dir_path = get_parent_directory(cmd->cmd);
	if (!dir_path)
		return (0);
	if (lstat(dir_path, &path_stat) == 0)
	{
		if (S_ISREG(path_stat.st_mode))
		{
			free(dir_path);
			return (1);
		}
	}
	free(dir_path);
	return (0);
}

/*
 * @brief Extracts the parent directory from a given path.
 * @param path The full path of the command.
 * @return A newly allocated string containing the parent directory,
 *         or NULL if no parent directory exists.
 */
char	*get_parent_directory(const char *path)
{
	int		i;
	char	*dir_path;

	if (!path || !*path)
		return (NULL);
	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i--;
	if (i == 0)
		return (ft_strdup("/"));
	dir_path = (char *)malloc(i + 1);
	if (!dir_path)
		return (NULL);
	strncpy(dir_path, path, i);
	dir_path[i] = '\0';
	return (dir_path);
}
