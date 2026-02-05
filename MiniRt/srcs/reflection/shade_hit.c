/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:09:20 by nryser            #+#    #+#             */
/*   Updated: 2025/05/09 18:09:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

static t_shading	build_shading_args(t_computations comps, t_light *light)
{
	t_shading	s;

	s.m = ((t_object *)comps.obj)->m;
	s.l = light;
	s.point = comps.over_point;
	s.eyev = comps.eyev;
	s.normalv = comps.normalv;
	s.obj = comps.obj;
	return (s);
}

static t_colour	process_light(t_world *w, t_computations comps,
					int i, bool ignore_shadows)
{
	t_shading	light_args;
	bool		in_shadow;
	t_colour	result;

	light_args = build_shading_args(comps, w->lights[i]);
	if (ignore_shadows)
		in_shadow = false;
	else
		in_shadow = is_shadowed(w, light_args.point, w->lights[i]);
	result = ft_shading(light_args, in_shadow);
	return (mult_colour(result, w->lights[i]->brightness));
}

/**
 * @brief Computes the color at the point of intersection.
 *
 * Uses the Phong reflection model (ambient, diffuse, specular)
 * to calculate the visible color at the intersection point
 * based on lighting, surface material, eye vector, and normal.
 *
 * @param world Pointer to the scene (objects + light).
 * @param comps Precomputed intersection information (position, normal, etc).
 * @return The final color at the intersection.
 */
t_colour	shade_hit(t_world *w, t_computations comps, bool ignore_shadows)
{
	t_colour	ambient;
	t_colour	light_sum;
	t_colour	final_color;
	int			i;

	ambient = mult_colour(w->ambient.colour, w->ambient.ratio);
	ambient = blend_colours(ambient, ((t_object *)comps.obj)->m.c);
	light_sum = ft_colour(0, 0, 0);
	i = 0;
	while (i < w->light_count)
	{
		light_sum = add_colours(light_sum,
				process_light(w, comps, i, ignore_shadows));
		i++;
	}
	if (w->light_count > 0)
		light_sum = mult_colour(light_sum, 1.0 / w->light_count);
	final_color = add_colours(ambient, light_sum);
	return (clamp_colour(final_color));
}
