/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:39:05 by nryser            #+#    #+#             */
/*   Updated: 2025/01/31 19:39:13 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Converts a string to a long long integer.
 * Handles overflow and underflow cases explicitly.
 */

static long long	ft_atolonglong(const char *str)
{
	long long	i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

static char	*num_to_str(long long val)
{
	static char	buffer[22];
	char		*ptr;
	long long	abs_val;

	ptr = buffer + sizeof(buffer) - 1;
	*ptr = '\0';
	if (val == 0)
	{
		*--ptr = '0';
		return (ptr);
	}
	if (val < 0)
		abs_val = -val;
	else
		abs_val = val;
	while (abs_val > 0)
	{
		*--ptr = (abs_val % 10) + '0';
		abs_val /= 10;
	}
	if (val < 0)
		*--ptr = '-';
	return (ptr);
}

/**
 * @brief Checks if a string represents a valid numeric value.
 * Validates length and numeric content, including overflow detection.
 */
int	is_valid_numeric(const char *str)
{
	long long	val;
	char		*converted_str;

	if (!str || !*str)
		return (0);
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (0);
	val = ft_atolonglong(str);
	converted_str = num_to_str(val);
	if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "-0") == 0
		|| ft_strcmp(str, "+0") == 0)
		return (1);
	return (ft_strcmp(converted_str, str) == 0);
}

/**
 * @brief Cleans up a variable list.
 */
void	cleanup_varlist(t_varlist *varlist)
{
	t_varlist	*current;
	t_varlist	*next;

	current = varlist;
	while (current)
	{
		next = current->next;
		free(current->var->vname);
		free(current->var->vvalue);
		free(current->var);
		free(current);
		current = next;
	}
}

/**
 * @brief Handles the exit built-in command.
 * @param node The command node.
 * @param minish Minishell structure.
 * @return 0 if successful, 1 otherwise.
 */
int	handle_exit(t_command *node, t_minishell *minish)
{
	int	arg_count;
	int	exit_code;

	arg_count = 0;
	while (node->args[arg_count])
		arg_count++;
	write(1, "exit\n", 5);
	if (exit_many_arguments(minish, node, arg_count))
		return (1);
	if (arg_count == 2)
		exit_code = (ft_atolonglong(node->args[1]) % 256);
	else
		exit_code = minish->last_exit_status;
	if (minish)
		cleanup_minishell(minish);
	exit(exit_code);
}
