/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:16:53 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 21:16:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	backup_original_fd(int fd_backup[2], int std_fd)
{
	if (std_fd == STDOUT_FILENO && fd_backup[1] == -1)
		fd_backup[1] = dup(STDOUT_FILENO);
	else if (std_fd == STDIN_FILENO && fd_backup[0] == -1)
		fd_backup[0] = dup(STDIN_FILENO);
}

void	handle_redirection_standalone(t_minishell *minish, t_ast *ast)
{
	pid_t	pid;
	int		status;

	if (ast->type != REDIRECTION_NODE)
		return ;
	pid = fork();
	if (pid == 0)
	{
		setup_child_signals();
		status = handle_redirections_child(ast, minish);
		exit(status);
	}
	waitpid(pid, &status, 0);
	update_exit_status(minish, status);
}

/**
 * @brief Joins three strings into one.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @param s3 Third string.
 * @return A newly allocated string combining s1, s2, and s3.
 */
char	*ft_strjoin_three(const char *s1, const char *s2, const char *s3)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	result = malloc(len1 + len2 + len3 + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcpy(result + len1, s2);
	ft_strcpy(result + len1 + len2, s3);
	return (result);
}

/**
 * @brief Retrieve the value of an environment
 * variable from the environment list.
 *
 * @param env The linked list of environment variables.
 * @param var_name The name of the variable to retrieve.
 * @return The value of the environment variable, or NULL if not found.
 */
char	*get_env_value(t_varlist *env, const char *var_name)
{
	while (env)
	{
		if (ft_strcmp(env->var->vname, var_name) == 0)
			return (env->var->vvalue);
		env = env->next;
	}
	return (NULL);
}

/**
 * @brief Retrieves the value of the PATH
 * variable from the custom environment list.
 * @param env_lst Linked list of environment variables.
 * @return The value of PATH or NULL if not found.
 */
char	*get_path_from_env(t_varlist *env_lst)
{
	while (env_lst)
	{
		if (ft_strcmp(env_lst->var->vname, "PATH") == 0)
			return (env_lst->var->vvalue);
		env_lst = env_lst->next;
	}
	return (NULL);
}
