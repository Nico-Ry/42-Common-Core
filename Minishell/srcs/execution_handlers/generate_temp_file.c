/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_temp_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:47:04 by nryser            #+#    #+#             */
/*   Updated: 2025/01/29 12:47:09 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	convert_suffix_to_string(int temp_suffix,
				char *file_path, int base_len)
{
	int		idx;
	int		start;
	int		end;
	char	temp;

	idx = base_len;
	while (temp_suffix > 0)
	{
		file_path[idx++] = (temp_suffix % 10) + '0';
		temp_suffix /= 10;
	}
	file_path[idx] = '\0';
	start = base_len;
	end = idx - 1;
	while (start < end)
	{
		temp = file_path[start];
		file_path[start] = file_path[end];
		file_path[end] = temp;
		start++;
		end--;
	}
}

static int	try_create_temp_file(char *file_path)
{
	int	fd;

	if (access(file_path, F_OK) != 0)
	{
		fd = open(file_path, O_CREAT | O_RDWR | O_EXCL, 0600);
		if (fd != -1)
		{
			close(fd);
			return (1);
		}
	}
	return (0);
}

char	*generate_temp_file_name(void)
{
	char	*base_path;
	int		base_len;
	int		random_suffix;
	char	*file_path;

	base_path = "/tmp/minishell_heredoc_";
	base_len = ft_strlen(base_path);
	random_suffix = 0;
	file_path = malloc(base_len + 12);
	if (!file_path)
		return (perror("malloc"), NULL);
	ft_strcpy(file_path, base_path);
	while (random_suffix <= 10000)
	{
		convert_suffix_to_string(random_suffix, file_path, base_len);
		if (try_create_temp_file(file_path))
			return (file_path);
		random_suffix++;
	}
	free(file_path);
	return (NULL);
}
