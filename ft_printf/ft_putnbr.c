/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:48:46 by nryser            #+#    #+#             */
/*   Updated: 2023/12/19 16:29:09 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_int_min(void)
{
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putnbr(int nbr, char *dec_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr == -2147483648)
		print_len = ft_int_min();
	else
	{
		if (nbr < 0)
		{
			if (ft_char('-') < 0)
				return (-1);
			print_len++;
			nbr *= -1;
		}
		if (nbr >= 10)
		{
			print_len += ft_putnbr(nbr / 10, dec_chars);
			if (print_len < 0)
				return (-1);
		}
		if (ft_char(dec_chars[nbr % 10]) < 0)
			return (-1);
		print_len++;
	}
	return (print_len);
}
