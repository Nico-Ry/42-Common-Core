/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:23:59 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 20:24:30 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_cylinder(char **tokens, bool bonus)
{
	int	count;

	count = count_split(tokens);
	if (!bonus && count != 6)
		return (args_count_error(tokens, count, 6));
	if (bonus && count != 7)
		return (args_count_error(tokens, count, 7));
	if (!is_vec3(tokens[1]) || !is_vec3(tokens[2]))
		return (0);
	if (!is_float(tokens[3]) || !is_float(tokens[4]))
		return (0);
	if (!is_color(tokens[5]))
		return (0);
	if (bonus && !is_int(tokens[6]))
		return (0);
	return (1);
}

static t_cylinder	*build_cylinder(t_cylinder_input in)
{
	t_cylinder	*cyl;
	t_matrix	*scale_m;
	t_matrix	*align_m;
	t_matrix	*trans_m;
	t_matrix	*tmp;

	cyl = ft_cylinder();
	cyl->base.m = ft_material();
	cyl->base.m.c = in.color;
	if (in.patt_type >= 1 && in.patt_type <= 7)
		cyl->base.m.patt = create_patt_by_type(
				in.patt_type, in.color, SHAPE_CYLINDER);
	cyl->min = 0;
	cyl->max = in.height;
	cyl->closed = true;
	scale_m = scale(in.diameter / 2.0, 1, in.diameter / 2.0);
	align_m = align_up_vector(normalize(in.normal));
	trans_m = translate(in.position.x, in.position.y, in.position.z);
	tmp = multiply_and_free(scale_m, align_m);
	set_transf(cyl, multiply_and_free(tmp, trans_m));
	return (cyl);
}

int	add_cylinders(t_object **objects, t_parsed_scene *scene, int start)
{
	int	i;

	i = 0;
	while (i < scene->cylinder_count)
	{
		objects[start + i] = (t_object *)build_cylinder(scene->cylinders[i]);
		i++;
	}
	return (start + i);
}
