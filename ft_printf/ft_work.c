/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:24:25 by nryser            #+#    #+#             */
/*   Updated: 2023/12/17 16:24:29 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_work(const char *str, va_list ap)
{
	int		count;

	count = 0;
	if (*str == '%')
		count = write(1, "%", 1);
	else if (*str == 'c')
		count = ft_char(va_arg(ap, int));
	else if (*str == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (*str == 'p')
		count = ft_putptr(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (*str == 'd' || *str == 'i')
		count = ft_putnbr(va_arg(ap, int), "0123456789");
	else if (*str == 'x')
		count = ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		count = ft_putnbr_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*str == 'u')
		count = ft_putnbr_dec(va_arg(ap, unsigned int), "0123456789");
	else
		return (-1);
	return (count);
}