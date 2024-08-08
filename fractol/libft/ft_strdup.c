/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:36:01 by nryser            #+#    #+#             */
/*   Updated: 2023/11/07 14:44:24 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		len;
	int		i;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (duplicate)
	{
		i = 0;
		while (s[i] != '\0')
		{
			duplicate[i] = s[i];
			i++;
		}
		duplicate[i] = '\0';
	}
	return (duplicate);
}

/* The strdup() function allocates sufficient memory
for a copy of the string s1, does the copy, and returns 
a pointer to it. The pointer may subsequently be used
 as an argument to the function free(3).
If insufficient memory is available, NULL is returned
 and errno is set to ENOMEM.
	*/