/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:24:07 by nryser            #+#    #+#             */
/*   Updated: 2023/12/17 16:24:10 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printf(const char *str, ...)
{
	int		res;
	int		temp;
	va_list	ap;
	
	va_start(ap, str);
	while(*str)
	{
		if (*str == '%')
		{
			temp = ft_work(++str, ap);
			if (temp <0)
				return (-1);
			res += temp;					
		}
		else
		{
			if (ft_char(*str) <0)
				return (-1);
			res++;
		}
		str++;
	}
	va_end(ap);
	return (res);
	
}