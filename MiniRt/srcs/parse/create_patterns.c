/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_patterns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:06:56 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 19:07:03 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

t_patt	*create_simple_pattern(int type, t_colour base,
					t_colour alt, double freq)
{
	t_patt	*pat;

	pat = malloc(sizeof(t_patt));
	if (!pat)
		return (NULL);
	if (type == PATTERN_STRIPE)
		*pat = stripe_patt(base, alt);
	else if (type == PATTERN_GRADIENT)
		*pat = gradient_patt(base, alt);
	else if (type == PATTERN_RING)
		*pat = ring_patt(base, alt);
	else if (type == PATTERN_CHECKERS)
		*pat = checkers_patt(base, alt);
	else
		return (free(pat), NULL);
	pat->frequency = freq;
	return (pat);
}

t_patt	*create_uv_pattern(int type, t_colour base,
					t_colour alt, t_uvsize size)
{
	t_patt	*pat;

	pat = malloc(sizeof(t_patt));
	if (!pat)
		return (NULL);
	if (type == PATTERN_UV_STRIPE)
		*pat = uv_stripe_patt(base, alt, size.u, size.v);
	else if (type == PATTERN_UV_GRADIENT)
		*pat = uv_gradient_patt(base, alt, size.u, size.v);
	else if (type == PATTERN_UV_CHECKERS)
		*pat = uv_checkers_patt(base, alt, size.u, size.v);
	else
		return (free(pat), NULL);
	return (pat);
}

t_patt	*create_patt_by_type(int type, t_colour base, int shape_type)
{
	if (shape_type == S_PL)
		return (create_patt_for_plane(type, base));
	else if (shape_type == SHAPE_CYLINDER)
		return (create_patt_for_cylinder(type, base));
	else if (shape_type == SHAPE_CONE)
		return (create_patt_for_cone(type, base));
	else
		return (create_patt_for_sphere(type, base));
}
