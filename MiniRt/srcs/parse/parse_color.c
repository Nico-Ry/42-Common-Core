/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:23:32 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:23:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

t_colour	parse_color(char *str)
{
	char		**split;
	double		r;
	double		g;
	double		b;
	t_colour	color;

	if (!str)
		return (ft_colour(0, 0, 0));
	split = ft_split(str, ',');
	if (!split || count_split(split) != 3
		|| !split[0] || !split[1] || !split[2])
	{
		write(2, "❌ parse_color: invalid input\n", 30);
		free_array(split);
		return (ft_colour(0, 0, 0));
	}
	r = ft_atof(split[0]) / 255.0;
	g = ft_atof(split[1]) / 255.0;
	b = ft_atof(split[2]) / 255.0;
	color = ft_colour(r, g, b);
	free_array(split);
	return (color);
}

static void	print_rgb_error(int r, int g, int b)
{
	printf(R_B""X""RES"RGB values out of range: ");
	if (r < 0 || r > 255)
		printf(AKA"%d"RES, r);
	else
		printf("%d", r);
	printf(",");
	if (g < 0 || g > 255)
		printf(AKA"%d"RES, g);
	else
		printf("%d", g);
	printf(",");
	if (b < 0 || b > 255)
		printf(AKA"%d"RES, b);
	else
		printf("%d", b);
	printf("\n");
}

static int	valid_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		print_rgb_error(r, g, b);
		return (0);
	}
	return (1);
}

int	is_color(const char *str)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(str, ',');
	if (!parts || count_split(parts) != 3)
	{
		printf(R_B""X""RES""TOO_MANY_VEC3""AKA"%s"RES"\n", str);
		free_array(parts);
		return (0);
	}
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	free_array(parts);
	if (!valid_rgb(r, g, b))
		return (0);
	return (1);
}
