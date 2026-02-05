/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:36:10 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:36:13 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Maps a point on a sphere to UV coordinates.
 *
 * The UV coordinates wrap around like a world globe:
 * - U goes from 0 to 1 horizontally (longitude)
 * - V goes from 0 to 1 vertically (latitude)
 *
 * @param point A point on the surface of a sphere (in object space).
 * @return A t_uv struct with u and v in [0,1] (longitude, latitude).
 */
t_uv	uv_spherical(t_tuple point)
{
	double	theta;
	double	radius;
	double	phi;
	t_uv	uv;

	theta = atan2(point.x, point.z);
	radius = sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
	phi = acos(point.y / radius);
	uv.u = 1.0 - (theta + M_PI) / (2 * M_PI);
	uv.v = 1.0 - phi / M_PI;
	return (uv);
}

/**
 * @brief Maps a point on a plane (typically on Y=0) to UV coordinates.
 *
 * The X and Z coordinates wrap around to [0,1] using modulo logic.
 */
t_uv	uv_planar(t_tuple point)
{
	t_uv	uv;

	uv.u = point.x - floor(point.x);
	uv.v = point.z - floor(point.z);
	return (uv);
}

/**
 * @brief Maps a point on a cylinder to UV coordinates.
 *
 * U wraps around the Y axis, V runs from min to max along the Y axis.
 */
t_uv	uv_cylindrical(t_tuple point)
{
	t_uv	uv;
	double	theta;

	theta = atan2(point.x, point.z);
	uv.u = 1.0 - (theta + M_PI) / (2.0 * M_PI);
	uv.v = point.y - floor(point.y);
	return (uv);
}

t_uv	uv_conical(t_tuple point, double min, double max)
{
	t_uv	uv;
	double	theta;

	theta = atan2(point.x, point.z);
	uv.u = 1.0 - (theta + M_PI) / (2.0 * M_PI);
	uv.v = (point.y - min) / (max - min);
	return (uv);
}

t_colour	uv_patt_at(t_patt *patt, t_tuple point, t_object *obj)
{
	t_uv	uv;
	t_cone	*cone;

	if (obj->type == PLANE)
		uv = uv_planar(point);
	else if (obj->type == SPHERE)
		uv = uv_spherical(point);
	else if (obj->type == CYLINDER)
		uv = uv_cylindrical(point);
	else if (obj->type == CONE)
	{
		cone = (t_cone *)obj;
		uv = uv_conical(point, cone->min, cone->max);
	}
	else
		uv = uv_spherical(point);
	if (patt->type == PATTERN_UV_CHECKERS)
		return (uv_checkers_at(patt, uv));
	if (patt->type == PATTERN_UV_STRIPE)
		return (uv_stripe_at(patt, uv));
	if (patt->type == PATTERN_UV_GRADIENT)
		return (uv_gradient_at(patt, uv));
	return (ft_colour(0, 0, 0));
}
