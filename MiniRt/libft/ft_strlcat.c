/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:52:14 by nryser            #+#    #+#             */
/*   Updated: 2023/11/02 18:24:35 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_dest_len(char *dest, size_t size)
{
	size_t	dest_len;

	dest_len = 0;
	while (dest_len < size && dest[dest_len] != '\0')
	{
		dest_len++;
	}
	return (dest_len);
}

static size_t	find_src_len(const char *src)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	return (src_len);
}

static void	copy_src(char *dest, const char *src, size_t dest_len, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = find_dest_len(dest, size);
	if (dest_len >= size)
	{
		src_len = find_src_len(src);
		return (dest_len + src_len);
	}
	copy_src(dest, src, dest_len, size);
	src_len = find_src_len(src);
	return (dest_len + src_len);
}

/*size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	if (dest_len >= size)
	{
		src_len = 0;
		while (src[src_len] != '\0')
		{
			src_len++;
		}
		return (dest_len + src_len);
	}
	i = 0;
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	return (dest_len + src_len);
}*/
