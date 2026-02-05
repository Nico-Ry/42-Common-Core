/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:24:15 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:24:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static void	print_long_line(char *str, int index, int k)
{
	int	i;

	i = index - k;
	printf(R_B""X""RES"");
	while (str[i] && str[i] != '\n')
		printf(AKA"%c", str[i++]);
	printf(RES"  ->  "LONG_LINE"");
}

static int	copy_str(char *str, int *i, char **lines, int j)
{
	int	k;
	int	space_added;

	k = 0;
	space_added = 0;
	while (str[*i] && str[*i] != '\n' && k < MAX_LINE_LEN)
	{
		if (str[*i] != ' ' || space_added == 0)
		{
			if (str[*i] == ' ')
				space_added = 1;
			else
				space_added = 0;
			lines[j][k++] = str[*i];
		}
		(*i)++;
	}
	if (k >= MAX_LINE_LEN)
	{
		print_long_line(str, *i, k);
		return (1);
	}
	return (0);
}

int	split_lines(char *str, char **lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (str[i])
		{
			if (copy_str(str, &i, lines, j))
				return (-1);
		}
		j++;
	}
	return (0);
}
