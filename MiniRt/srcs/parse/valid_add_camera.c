/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:21:49 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 09:21:49 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

void	orientation_err(double x, double y, double z)
{
	printf(R_B""X""RES"3d normal vector values out of range: ");
	if (x > 1 || x < -1)
		printf(AKA"%.2f"RES, x);
	else
		printf("%.2f", x);
	printf(",");
	if (y > 1 || y < -1)
		printf(AKA"%.2f"RES, y);
	else
		printf("%.2f", y);
	printf(",");
	if (z > 1 || z < -1)
		printf(AKA"%.2f"RES, z);
	else
		printf("%.2f", z);
	printf("\n");
}

int	valid_orientation(char *str)
{
	char	**parts;
	double	x;
	double	y;
	double	z;

	parts = ft_split(str, ',');
	x = ft_atof(parts[0]);
	y = ft_atof(parts[1]);
	z = ft_atof(parts[2]);
	free_array(parts);
	if (x > 1 || x < -1 || y > 1 || y < -1 || z > 1 || z < -1)
	{
		orientation_err(x, y, z);
		return (0);
	}
	return (1);
}

int	valid_camera(char **tokens)
{
	int		count;
	double	fov;

	count = count_split(tokens);
	if (count != 4)
		return (args_count_error(tokens, count, 4));
	if (!is_vec3(tokens[1]))
		return (0);
	if (!is_vec3(tokens[2]) || !valid_orientation(tokens[2]))
		return (0);
	if (!is_float(tokens[3]))
		return (0);
	fov = ft_atof(tokens[3]);
	if (fov < 0.0 || fov > 180.0)
	{
		printf(R_B""X""RES""FOV_ERR""AKA"%.0f\n"RES, fov);
		return (0);
	}
	return (1);
}
