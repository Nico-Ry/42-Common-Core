/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_add_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:03:33 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 20:40:26 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

int	valid_plane(char **tokens, bool bonus)
{
	int	count;

	count = count_split(tokens);
	if (!bonus && count != 4)
		return (args_count_error(tokens, count, 4));
	if (bonus && count != 5)
		return (args_count_error(tokens, count, 5));
	if (!is_vec3(tokens[1]))
		return (0);
	if (!is_vec3(tokens[2]))
		return (0);
	if (!is_color(tokens[3]))
		return (0);
	if (bonus && !is_int(tokens[4]))
		return (0);
	return (1);
}

int	add_planes(t_object **objects, t_parsed_scene *scene, int start)
{
	int				i;
	t_plane_input	in;
	t_plane			*p;
	t_matrix		*rot_m;
	t_matrix		*trans_m;

	i = 0;
	while (i < scene->plane_count)
	{
		in = scene->planes[i];
		p = ft_plane();
		p->base.m = ft_material();
		p->base.m.c = in.color;
		p->base.m.ambient = 0.1;
		p->base.m.diffuse = 0.9;
		p->base.m.specular = 0.0;
		if (in.patt_type >= 1 && in.patt_type <= 7)
			p->base.m.patt = create_patt_by_type(in.patt_type, in.color, S_PL);
		rot_m = align_up_vector(normalize(in.normal));
		trans_m = translate(in.position.x, in.position.y, in.position.z);
		set_transf(p, multiply_and_free(rot_m, trans_m));
		objects[start + i] = (t_object *)p;
		i++;
	}
	return (start + i);
}
