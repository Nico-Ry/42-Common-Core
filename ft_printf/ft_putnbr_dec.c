/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:53 by nryser            #+#    #+#             */
/*   Updated: 2023/12/19 16:19:48 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putnbr_dec(unsigned int nbr, char *dec_chars)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 10)
	{
		print_len += ft_putnbr_dec(nbr / 10, dec_chars);
		if (print_len < 0)
			return (-1);
	}
	if (ft_char(dec_chars[nbr % 10]) < 0)
		return (-1);
	print_len++;
	return (print_len);
}
