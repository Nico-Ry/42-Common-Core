/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:59:10 by nryser            #+#    #+#             */
/*   Updated: 2025/01/30 08:59:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Checks if the given string starts with
 * '-n' followed only by 'n' characters.
 * @param str The string to check.
 * @return true if it's a valid '-n' option, false otherwise.
 */
bool	is_valid_n_option(const char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-' || str[1] != 'n')
		return (false);
	while (str[++i])
	{
		if (str[i] != 'n')
			return (false);
	}
	return (true);
}

void	echo_write_args(t_command *node,
				t_minishell *minish, int out_fd, int start_index)
{
	int		i;

	(void)minish;
	i = start_index;
	while (node->args[i])
	{
		write (out_fd, node->args[i], ft_strlen(node->args[i]));
		if (node->args[i + 1])
			write(out_fd, " ", 1);
		i++;
	}
}

bool	echo_check_newline(t_command *node, int *start_index)
{
	if (is_valid_n_option(node->args[1]))
	{
		*start_index = 2;
		return (false);
	}
	*start_index = 1;
	return (true);
}

/**
 * @brief Handles the 'echo' built-in command.
 * Writes the arguments to the output file descriptor.
 * @param node The command node.
 * @param minish Minishell structure.
 * @param out_fd The file descriptor for output.
 * @return 0 on success, 1 on error.
 */
int	handle_echo(t_command *node, t_minishell *minish, int out_fd)
{
	int		start_index;
	bool	newline;
	int		i;

	(void)minish;
	if (!node || !node->cmd || !node->args)
		return (1);
	else if (node->argc == 1)
	{
		write(out_fd, "\n", 1);
		return (0);
	}
	newline = echo_check_newline(node, &start_index);
	i = start_index;
	while (node->args[i])
	{
		write (out_fd, node->args[i], ft_strlen(node->args[i]));
		if (node->args[i + 1])
			write(out_fd, " ", 1);
		i++;
	}
	if (newline)
		write(out_fd, "\n", 1);
	return (0);
}
