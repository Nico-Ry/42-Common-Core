/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:10:15 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 00:10:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Handles errors for the cd command.
 * Prints an error message when the directory change fails.
 * @param path The directory path that failed to change to.
 */
void	cd_error(const char *path)
{
	ft_putstr_fd("miniHell: cd: ", 2);
	ft_putstr_fd((char *)path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

/**
 * @brief Changes the working directory.
 * Updates the environment variables `PWD` and `OLDPWD` upon successful change.
 * @param minish The minishell structure containing environment variables.
 * @param path The directory path to change to.
 * @return int Exit status: 0 for success, 1 or 127 for failure.
 */
int	change_directory(t_minishell *minish, const char *path)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;

	oldpwd = getcwd(cwd, sizeof(cwd));
	if (!oldpwd)
	{
		ft_putstr_fd("miniHell: cd: error getting current directory\n", 2);
		return (127);
	}
	if (chdir(path) != 0)
	{
		cd_error(path);
		return (1);
	}
	set_env_var(minish, "OLDPWD", oldpwd);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		set_env_var(minish, "PWD", cwd);
	else
		ft_putstr_fd("miniHell: cd: error updating PWD\n", 2);
	return (0);
}

/**
 * @brief Resolves the path for `cd` when `~` or `-` is used.
 * Handles cases for `HOME` and `OLDPWD`.
 * @param node The command structure containing arguments.
 * @param minish The minishell structure containing environment variables.
 * @return char* Resolved path or NULL on error.
 */
char	*resolve_cd_path_home_or_oldpwd(t_command *node, t_minishell *minish)
{
	char	*path;

	if (!node->args[1] || node->args[1][0] == '~')
	{
		path = get_env_var(minish, "HOME");
		if (!path || !*path)
		{
			ft_putstr_fd("miniHell: cd: HOME not set\n", 2);
			return (NULL);
		}
		return (ft_strdup(path));
	}
	if (ft_strcmp(node->args[1], "-") == 0)
	{
		path = get_env_var(minish, "OLDPWD");
		if (!path || !*path)
		{
			ft_putstr_fd("miniHell: cd: OLDPWD not set\n", 2);
			return (NULL);
		}
		ft_putstr_fd(path, 1);
		write(1, "\n", 1);
		return (ft_strdup(path));
	}
	return (NULL);
}

/**
 * @brief Resolves the final path for `cd` after expansions and validation.
 * @param node The command structure containing arguments.
 * @param minish The minishell structure containing environment variables.
 * @return char* Resolved path or NULL on error.
 */
char	*resolve_cd_path(t_command *node, t_minishell *minish)
{
	char	*path;

	path = resolve_cd_path_home_or_oldpwd(node, minish);
	if (path)
		return (path);
	path = node->args[1];
	if (!path || !*path)
	{
		ft_putstr_fd("miniHell: cd: ", 2);
		ft_putstr_fd(node->args[1], 2);
		ft_putstr_fd(": Invalid path\n", 2);
		return (NULL);
	}
	return (path);
}

/**
 * @brief Executes the cd command.
 * Expands variables in the path (e.g., `$HOME`) and handles directory changes.
 * @param node The command structure containing arguments.
 * @param minish The minishell structure containing environment variables.
 * @return int Exit status: 0 for success, 1 for failure.
 */
int	handle_cd(t_command *node, t_minishell *minish)
{
	char	*path;
	int		status;

	if (node->argc > 2)
	{
		ft_putstr_fd("miniHell: cd: too many arguments\n", 2);
		return (1);
	}
	path = resolve_cd_path(node, minish);
	if (!path)
		return (1);
	status = change_directory(minish, path);
	minish->last_exit_status = status;
	if (path != node->args[1])
		free(path);
	return (status);
}
