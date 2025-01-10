/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:59:15 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 13:59:15 by nryser           ###   ########.ch       */
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
