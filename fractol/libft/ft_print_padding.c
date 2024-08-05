/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:42:40 by nryser            #+#    #+#             */
/*   Updated: 2024/05/24 17:52:41 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_padding(int width, int len, char c)
{
	int	count;

	count = 0;
	while (width - len > 0)
	{
		ft_putchar_fd(c, 1);
		count++;
		width--;
	}
	return (count);
}
