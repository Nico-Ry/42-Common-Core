/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:40:28 by nryser            #+#    #+#             */
/*   Updated: 2024/10/14 20:14:24 by ameechan         ###   ########.fr       */
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
