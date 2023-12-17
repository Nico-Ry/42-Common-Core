/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:24:49 by nryser            #+#    #+#             */
/*   Updated: 2023/12/17 16:25:30 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *str)
{
	int	print_len;
	
	print_len = 0;
	if (!str)
	{
		print_len += ft_str("(null)");
		if (print_len < 0)
			return (-1);
	}
	else
	{
		while (*str)
		{
			if (ft_char(*str) < 0)
				return (-1);
			print_len++;
			str++;
		}
	}
	return (print_len);
}