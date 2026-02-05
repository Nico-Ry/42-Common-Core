/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:47:13 by nryser            #+#    #+#             */
/*   Updated: 2025/05/03 05:47:28 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static int	readable_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf(AKA"Error\n❌ can't open file "RES"`%s`\n", file);
		return (0);
	}
	printf(G_B"✔ "GR"readable file\n"RES);
	close(fd);
	return (1);
}

static int	valid_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 4 || file[i - 1] != 't' || file[i - 2] != 'r' || file[i - 3] != '.')
	{
		printf(AKA"Error\n❌ invalid extension "RES"`%s`\n", file);
		return (0);
	}
	printf(G_B"✔ "GR"valid extension\n"RES);
	return (1);
}

int	check_file(int ac, char **av)
{
	if (ac != 2)
	{
		printf(B_B"usage:"RES" %s <filename>\n", av[0]);
		return (0);
	}
	if (!valid_extension(av[1]))
	{
		printf(AKA"Error\n❌ invalid extension "RES"`%s`\n", av[1]);
		return (0);
	}
	if (!readable_file(av[1]))
	{
		printf(AKA"Error\n❌ can't open file "RES"`%s`\n", av[1]);
		return (0);
	}
	return (1);
}
