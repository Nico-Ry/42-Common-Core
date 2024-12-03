/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:51:54 by nryser            #+#    #+#             */
/*   Updated: 2023/11/02 21:42:50 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

int	ft_process_digits(const char *str, int *sign)
{
	int	int_max;
	int	int_min;
	int	result;

	int_max = 2147483647;
	int_min = (-int_max -1);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (result > int_max / 10
			|| (result == int_max / 10 && (*str - '0') > int_max % 10))
		{
			if (*sign == 1)
				return (int_max);
			else
				return (int_min);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (sign * ft_process_digits(str, &sign));
}
