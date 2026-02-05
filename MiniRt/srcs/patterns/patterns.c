/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:21:43 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 14:21:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// /**
//  * @brief A pattern used for testing: maps x/y/z to RGB.
//  *
//  * This helps visualize coordinates on surfaces.
//  */
// t_colour	test_pattern_at(t_pattern *pattern, t_tuple point)
// {
// 	(void)pattern;
// 	return (ft_colour(point.x, point.y, point.z));
// }

// /**
//  * @brief Creates a basic test pattern.
//  *
//  * Type is set to 99 for test identification. Colors are unused.
//  */
// t_pattern	test_pattern(void)
// {
// 	t_pattern	p;

// 	p.type = 99;
// 	p.a = ft_colour(0, 0, 0);
// 	p.b = ft_colour(0, 0, 0);
// 	p.transform = create_identity_matrix(4);
// 	return (p);
// }

/**
 * @brief Transforms a world point to object space using the inverse transform.
 */
t_tuple	transform_world_to_object(t_tuple w_point, t_matrix *inverse)
{
	t_matrix	*wm;
	t_matrix	*rm;
	t_tuple		result;

	wm = tuple_to_matrix(w_point);
	rm = multiply_matrices(inverse, wm);
	result = matrix_to_tuple(rm);
	free_matrix(wm);
	free_matrix(rm);
	return (result);
}

/**
 * @brief Transforms a point from object space to pattern space.
 */
static t_tuple	transform_object_to_pattern(t_tuple obj_point, t_matrix *inv)
{
	t_matrix	*objm;
	t_matrix	*resm;
	t_tuple		result;

	objm = tuple_to_matrix(obj_point);
	resm = multiply_matrices(inv, objm);
	result = matrix_to_tuple(resm);
	free_matrix(objm);
	free_matrix(resm);
	return (result);
}

/**
 * @brief Determines the color of a pattern at a point
 * in pattern space or UV space.
 *
 * This dispatches based on the pattern type.
 * For UV patterns, it automatically converts the point to UV coordinates.
 */
t_colour	patt_colour_at(t_patt *patt, t_tuple patt_point,
				t_object *obj)
{
	if (!patt || !obj)
		return (ft_colour(0, 0, 0));
	if (patt->type == PATTERN_UV_CHECKERS
		|| patt->type == PATTERN_UV_STRIPE
		|| patt->type == PATTERN_UV_GRADIENT)
		return (uv_patt_at(patt, patt_point, obj));
	if (patt->type == PATTERN_STRIPE)
		return (stripe_at(patt, patt_point, obj));
	if (patt->type == PATTERN_GRADIENT)
		return (gradient_at(patt, patt_point));
	if (patt->type == PATTERN_RING)
		return (ring_at(patt, patt_point, obj));
	if (patt->type == PATTERN_CHECKERS)
		return (checkers_at(patt, patt_point, obj));
	return (ft_colour(0, 0, 0));
}

/**
 * @brief Computes the pattern color at a world-space point on an object.
 *
 * This function handles all the necessary space transformations:
 * - Transforms the point from world space to object space using the
 * inverse of the object's transform.
 * - Transforms the result into pattern space using the inverse
 * of the pattern's transform.
 *
 * It then delegates to `pattern_colour_at()` to compute the actual
 * color based on the pattern type.
 *
 * @param patt The pattern applied to the object (may be procedural or UV-based).
 * @param obj The object on which the pattern is applied.
 * @param w_point A point in world space to evaluate the pattern at.
 * @return The final color from the pattern at the given point.
 */
t_colour	patt_colour_at_world(t_patt *patt, t_object *obj,
				t_tuple w_point)
{
	t_matrix	*object_inv;
	t_matrix	*pattern_inv;
	t_tuple		object_point;
	t_tuple		pattern_point;

	if (!patt || !patt->transform || !obj || !obj->transf)
		exit(1);
	object_inv = invert_matrix(obj->transf);
	object_point = transform_world_to_object(w_point, object_inv);
	free_matrix(object_inv);
	pattern_inv = invert_matrix(patt->transform);
	pattern_point = transform_object_to_pattern(object_point, pattern_inv);
	free_matrix(pattern_inv);
	return (patt_colour_at(patt, pattern_point, obj));
}
