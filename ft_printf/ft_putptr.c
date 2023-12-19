/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:31:24 by nryser            #+#    #+#             */
/*   Updated: 2023/12/19 16:44:20 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static int	ft_ptr_hex(unsigned long nbr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 16)
	{
		print_len += ft_ptr_hex(nbr / 16, hex_chars);
		if (print_len < 0)
			return (-1);
	}
	if (ft_char(hex_chars[nbr % 16]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}

int	ft_putptr(unsigned long ptr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	print_len = ft_putstr("0x");
	if (print_len < 0)
		return (-1);
	print_len += ft_ptr_hex(ptr, hex_chars);
	if (print_len < 0)
		return (-1);
	return (print_len);
}
