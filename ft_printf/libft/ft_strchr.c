/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:40:28 by nryser            #+#    #+#             */
/*   Updated: 2023/11/02 19:12:49 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	c;

	c = (unsigned char)ch;
	if (c == '\0')
	{
		while (*str != '\0')
		{
			str++;
		}
		return ((char *)str);
	}
	while (*str != '\0')
	{
		if ((unsigned char)*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
