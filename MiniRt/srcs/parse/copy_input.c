/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:54:01 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 21:03:39 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static int	read_all(int fd, char *buf)
{
	int	bytes_read;
	int	total;

	total = 0;
	bytes_read = read(fd, buf + total, MAX_FILE - total);
	while (bytes_read > 0)
	{
		total += bytes_read;
		if (total >= MAX_FILE)
			return (-2);
		bytes_read = read(fd, buf + total, MAX_FILE - total);
	}
	if (bytes_read < 0)
		return (-1);
	return (0);
}

static int	grab_input(char *file, char **buf)
{
	int	fd;
	int	status;

	*buf = ft_calloc(sizeof(char), MAX_FILE);
	fd = open(file, O_RDONLY);
	if (fd < 0 || !(*buf))
		return (printf(AKA"Error\n❌ Could not open or allocate\n"RES));
	status = read_all(fd, *buf);
	close(fd);
	if (status == -1)
	{
		free(*buf);
		return (printf(AKA"Error\n❌ Read error\n"RES));
	}
	if (status == -2)
	{
		free(*buf);
		return (printf(AKA"Error\n❌ File too big"RES" (Max: 10240b)\n"));
	}
	printf(G_B"✔ "GR"input grabbed\n"RES);
	return (0);
}

// static int	grab_input(char *file, char **buf)
// {
// 	int	bytes_read;
// 	int	total;
// 	int	fd;

// 	total = 0;
// 	*buf = calloc(sizeof(char), MAX_FILE);
// 	fd = open(file, O_RDONLY);
// 	bytes_read = read(fd, *buf + total, MAX_FILE - total);
// 	while (bytes_read > 0)
// 	{
// 		total += bytes_read;
// 		if (total >= MAX_FILE)
// 		{
// 			free(*buf);
// 			return (printf(AKA"Error\n❌ File too big"RES" (Max: 10240b)n"));
// 		}
// 		bytes_read = read(fd, *buf + total, MAX_FILE - total);
// 	}
// 	if (bytes_read < 0)
// 	{
// 		free(*buf);
// 		return (printf(AKA"Error\n❌ Read error\n"RES));
// 	}
// 	close(fd);
// 	printf(G_B"✔ "GR"input grabbed\n"RES);
// 	return (0);
// }

static int	count_lines(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (count);
}

static char	**alloc_lines(char *str)
{
	int		i;
	int		count;
	char	**lines;

	i = 0;
	count = count_lines(str);
	lines = ft_calloc(count + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	while (i < count)
	{
		lines[i] = ft_calloc(MAX_LINE_LEN, sizeof(char));
		if (!lines[i])
			free_array(lines);
		i++;
	}
	return (lines);
}

char	**copy_input(char *file)
{
	char	*input;
	char	**lines;

	if (grab_input(file, &input))
		return (NULL);
	lines = alloc_lines(input);
	if (!lines)
	{
		free(input);
		return (NULL);
	}
	if (split_lines(input, lines))
	{
		free_array(lines);
		free(input);
		return (NULL);
	}
	free(input);
	return (lines);
}
