/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:41:00 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 19:41:00 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

bool	is_numeric(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	validate_num_philosophers(const char *arg)
{
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid number of philosophers argument\n", 2);
		return (false);
	}
	return (true);
}

bool	validate_time_argument(const char *arg)
{
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid time argument\n", 2);
		return (false);
	}
	return (true);
}

bool	validate_num_must_eat(const char *arg)
{
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid number of times to eat argument\n", 2);
		return (false);
	}
	return (true);
}
