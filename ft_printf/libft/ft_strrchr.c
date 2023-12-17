/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:41:12 by nryser            #+#    #+#             */
/*   Updated: 2023/11/02 19:44:36 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	c;
	char	*last;

	c = (char)ch;
	last = NULL;
	while (*str != '\0')
	{
		if (*str == c)
		last = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (last);
}
