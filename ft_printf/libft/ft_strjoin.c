/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:55:27 by nryser            #+#    #+#             */
/*   Updated: 2023/11/07 14:28:13 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	s2_len = 0;
	if (s2 != NULL)
	s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, s1_len + 1);
	if (s2)
		ft_strlcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}

/*
This function works basically the same way as ft_strlcat does, 
but instead of passing it a destination string that has to 
be correctly allocated 
as a parameter, we only pass two strings and ft_strjoin will 
allocate the required
 memory for both of them plus the NUL-terminating character.
s1 will be the first string in the result, s2 the second one.
*/