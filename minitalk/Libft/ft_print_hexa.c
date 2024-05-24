/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:42:29 by nryser            #+#    #+#             */
/*   Updated: 2024/05/24 17:52:34 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_print_hexa(unsigned long long n, char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->hash)
	{
		if (c == 'x')
			count += ft_print_string("0x");
		else if (c == 'X')
			count += ft_print_string("0X");
		flags->hash = 0;
	}
	if (n >= 16)
		count += ft_print_hexa(n / 16, c, flags);
	if (c == 'x')
		ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	else if (c == 'X')
		ft_putchar_fd("0123456789ABCDEF"[n % 16], 1);
	count++;
	return (count);
}
