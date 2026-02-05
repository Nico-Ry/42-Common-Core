/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:57:37 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:58:06 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

t_colour	secondary_colour(t_colour c)
{
	return (ft_colour(c.r * 0.5, c.g * 0.5, c.b * 0.5));
}

t_patt	*create_patt_for_sphere(int type, t_colour base)
{
	t_colour	alt;
	t_uvsize	size;

	alt = secondary_colour(base);
	if (type == PATTERN_STRIPE)
		return (create_simple_pattern(type, base, alt, 10.0));
	else if (type == PATTERN_GRADIENT)
		return (create_simple_pattern(type, base, alt, 4.0));
	else if (type == PATTERN_RING)
		return (create_simple_pattern(type, base, alt, 12.0));
	else if (type == PATTERN_CHECKERS)
		return (create_simple_pattern(type, base, alt, 1.0));
	else if (type == PATTERN_UV_STRIPE)
		size = (t_uvsize){10, 1};
	else if (type == PATTERN_UV_GRADIENT)
		size = (t_uvsize){0, 0};
	else if (type == PATTERN_UV_CHECKERS)
		size = (t_uvsize){8, 8};
	else
		return (NULL);
	return (create_uv_pattern(type, base, alt, size));
}

t_patt	*create_patt_for_plane(int type, t_colour base)
{
	t_colour	alt;
	t_uvsize	size;

	alt = secondary_colour(base);
	if (type == PATTERN_STRIPE)
		return (create_simple_pattern(type, base, alt, 3.0));
	else if (type == PATTERN_GRADIENT)
		return (create_simple_pattern(type, base, alt, 2.0));
	else if (type == PATTERN_RING)
		return (create_simple_pattern(type, base, alt, 4.0));
	else if (type == PATTERN_CHECKERS)
		return (create_simple_pattern(type, base, alt, 0.5));
	else if (type == PATTERN_UV_STRIPE)
		size = (t_uvsize){4, 1};
	else if (type == PATTERN_UV_GRADIENT)
		size = (t_uvsize){0, 0};
	else if (type == PATTERN_UV_CHECKERS)
		size = (t_uvsize){4, 4};
	else
		return (NULL);
	return (create_uv_pattern(type, base, alt, size));
}

t_patt	*create_patt_for_cylinder(int type, t_colour base)
{
	t_colour	alt;
	t_uvsize	size;

	alt = secondary_colour(base);
	if (type == PATTERN_STRIPE)
		return (create_simple_pattern(type, base, alt, 15.0));
	else if (type == PATTERN_GRADIENT)
		return (create_simple_pattern(type, base, alt, 5.0));
	else if (type == PATTERN_RING)
		return (create_simple_pattern(type, base, alt, 8.0));
	else if (type == PATTERN_CHECKERS)
		return (create_simple_pattern(type, base, alt, 1.0));
	else if (type == PATTERN_UV_STRIPE)
		size = (t_uvsize){12, 1};
	else if (type == PATTERN_UV_GRADIENT)
		size = (t_uvsize){0, 0};
	else if (type == PATTERN_UV_CHECKERS)
		size = (t_uvsize){12, 6};
	else
		return (NULL);
	return (create_uv_pattern(type, base, alt, size));
}

t_patt	*create_patt_for_cone(int type, t_colour base)
{
	t_colour	alt;
	t_uvsize	size;

	alt = secondary_colour(base);
	if (type == PATTERN_STRIPE)
		return (create_simple_pattern(type, base, alt, 20.0));
	else if (type == PATTERN_GRADIENT)
		return (create_simple_pattern(type, base, alt, 6.0));
	else if (type == PATTERN_RING)
		return (create_simple_pattern(type, base, alt, 14.0));
	else if (type == PATTERN_CHECKERS)
		return (create_simple_pattern(type, base, alt, 2.0));
	else if (type == PATTERN_UV_STRIPE)
		size = (t_uvsize){40, 40};
	else if (type == PATTERN_UV_GRADIENT)
		size = (t_uvsize){0, 0};
	else if (type == PATTERN_UV_CHECKERS)
		size = (t_uvsize){50, 50};
	else
		return (NULL);
	return (create_uv_pattern(type, base, alt, size));
}
