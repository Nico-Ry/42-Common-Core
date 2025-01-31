/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:42:12 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 23:42:12 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates sufficient memory for a copy of the string s, does the copy,
 * and returns a pointer to it.The pointer may subsequently be used
 * as an argument to the function free(3).
 * If insufficient memory is available, NULL is returned
 * and errno is set to ENOMEM.
 * @param s The string to duplicate.
 */
char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		len;
	int		i;

	len = 0;
	while (s[len] != '\0')
		len++;
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
		return (duplicate);
	}
	return (NULL);
}
