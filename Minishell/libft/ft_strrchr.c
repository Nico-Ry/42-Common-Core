/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:41:02 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 23:41:02 by nryser           ###   ########.ch       */
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
