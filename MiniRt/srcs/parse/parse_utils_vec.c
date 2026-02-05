/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:23:34 by nryser            #+#    #+#             */
/*   Updated: 2025/05/05 18:23:34 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

static int	is_valid_vec3_parts(char **parts)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!is_float(parts[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_vec3(const char *str)
{
	char	**parts;
	int		valid;

	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	if (count_split(parts) != 3)
	{
		printf(R_B""X""RES""TOO_MANY_VEC3""AKA"%s"RES"", str);
		free_array(parts);
		return (0);
	}
	valid = is_valid_vec3_parts(parts);
	free_array(parts);
	return (valid);
}
