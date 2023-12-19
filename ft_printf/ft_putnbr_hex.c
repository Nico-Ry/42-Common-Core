/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:58 by nryser            #+#    #+#             */
/*   Updated: 2023/12/19 16:45:33 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	ft_putnbr_hex(unsigned long nbr, char *hex_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 16)
	{
		print_len += ft_putnbr_hex(nbr / 16, hex_chars);
		if (print_len < 0)
			return (-1);
	}
	if (ft_char(hex_chars[nbr % 16]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}
