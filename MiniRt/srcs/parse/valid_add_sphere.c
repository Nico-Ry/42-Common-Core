/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:36:42 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:37:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_sphere(char **sp, bool bonus)
{
	int	count;

	count = count_split(sp);
	if (!bonus && count != 4)
		return (args_count_error(sp, count, 4));
	else if (bonus && count != 5)
		return (args_count_error(sp, count, 5));
	if (!is_vec3(sp[1]))
		return (0);
	if (!is_float(sp[2]))
		return (0);
	if (!is_color(sp[3]))
		return (0);
	if (bonus && !is_int(sp[4]))
		return (0);
	return (1);
}

int	add_spheres(t_object **objects, t_parsed_scene *scene, int start)
{
	int					i;
	t_sphere_input		in;
	t_sphere			*s;
	t_matrix			*scale_m;
	t_matrix			*trans_m;

	i = 0;
	while (i < scene->sphere_count)
	{
		in = scene->spheres[i];
		s = ft_sphere(1);
		s->base.m = ft_material();
		s->base.m.c = in.color;
		if (in.patt_type >= 1 && in.patt_type <= 7)
			s->base.m.patt = create_patt_by_type(in.patt_type, in.color, S_SPH);
		scale_m = scale(in.diameter / 2.0,
				in.diameter / 2.0,
				in.diameter / 2.0);
		trans_m = translate(in.position.x, in.position.y, in.position.z);
		set_transf(s, multiply_and_free(scale_m, trans_m));
		objects[start + i] = (t_object *)s;
		i++;
	}
	return (start + i);
}
