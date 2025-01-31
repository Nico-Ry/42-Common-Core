/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_invalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:36:40 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 19:36:40 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit_too_many_args(t_minishell *minish)
{
	write(2, "miniHELL: exit: too many arguments\n", 35);
	minish->last_exit_status = 1;
	return (1);
}

int	exit_invalid_arg(t_minishell *minish, t_command *node)
{
	write(2, "miniHELL: exit: ", 16);
	write(2, node->args[1], ft_strlen(node->args[1]));
	write(2, ": numeric argument required\n", 28);
	minish->last_exit_status = 2;
	return (2);
}

int	exit_many_arguments(t_minishell *minish,
						t_command *node, int arg_count)
{
	if (arg_count == 2)
	{
		if (!is_valid_numeric(node->args[1]))
		{
			exit_invalid_arg(minish, node);
			if (minish)
				cleanup_minishell(minish);
			exit(2);
		}
	}
	if (arg_count > 2)
	{
		if (!is_valid_numeric(node->args[1]))
		{
			exit_invalid_arg(minish, node);
			if (minish)
				cleanup_minishell(minish);
			exit(2);
		}
		return (exit_too_many_args(minish));
	}
	return (0);
}
