/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone_caps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:15:53 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:21:45 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

#define CAP_EPSILON 1e-4

/**
 * @brief Determines whether a ray intersects a cone’s cap.
 *
 * This function calculates whether the point on the ray at distance `t`
 * lies within the radius of the cone's circular cap at the specified
 * y-level. This is used for validating cap intersections.
 *
 * @param ray The ray being tested for intersection.
 * @param t The distance along the ray to test.
 * @param y The y-coordinate of the cap being tested.
 * @return true if the point lies within the cap radius, false otherwise.
 */
bool	check_cone_cap(t_ray ray, double t, t_cone *c)
{
	double	x;
	double	z;
	double	y;
	double	radius;

	y = ray.origin.y + t * ray.direction.y;
	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if (fabs(y - c->min) < EPSILON)
		radius = fabs(c->min);
	else
		radius = fabs(c->max);
	return (x * x + z * z <= radius * radius + EPSILON);
}

/**
 * @brief Computes ray intersections with a closed cone’s end caps.
 *
 * This function tests whether a ray intersects the top or bottom circular
 * caps of a cone (if the cone is closed). It computes the intersection
 * point along the ray at each cap’s y-level and verifies if the point
 * lies within the valid radius.
 *
 * Valid intersections are added to the hit list.
 *
 * @param xs The list where valid intersections will be added.
 * @param cone The cone object being tested.
 * @param ray The ray in the cone’s local/object space.
 */
void	intersect_cone_caps(t_hitlist **xs, t_cone *cone, t_ray *ray)
{
	double	t;

	if (!cone->closed || fabs(ray->direction.y) < EPSILON)
		return ;
	t = (cone->min - ray->origin.y) / ray->direction.y;
	if (t >= 0 && check_cone_cap(*ray, t, cone))
		add_hit(xs, intersection(t, cone));
	t = (cone->max - ray->origin.y) / ray->direction.y;
	if (t >= 0 && check_cone_cap(*ray, t, cone))
		add_hit(xs, intersection(t, cone));
}

static t_tuple	transform_normal_to_world(t_object *obj, t_tuple local_normal)
{
	t_matrix	*inv;
	t_matrix	*inv_transp;
	t_tuple		world_normal;

	inv = invert_matrix(obj->transf);
	inv_transp = transpose_matrix(inv);
	world_normal = transform_world_to_object(local_normal, inv_transp);
	free_matrix(inv);
	free_matrix(inv_transp);
	world_normal.w = 0;
	return (normalize(world_normal));
}

static t_tuple	compute_local_cone_normal(t_cone *cone, t_tuple p)
{
	double	dist;
	double	y;

	dist = p.x * p.x + p.z * p.z;
	if (cone->closed)
	{
		if (fabs(p.y - cone->max) < EPSILON
			&& dist <= fabs(cone->max) * fabs(cone->max))
			return (ft_tuple(0, 1, 0, VECTOR));
		if (fabs(p.y - cone->min) < EPSILON
			&& dist <= fabs(cone->min) * fabs(cone->min))
			return (ft_tuple(0, -1, 0, VECTOR));
	}
	y = sqrt(p.x * p.x + p.z * p.z);
	if (p.y > 0)
		y = -y;
	return (ft_tuple(p.x, y, p.z, VECTOR));
}

/**
 * @brief Computes the normal vector at a point on a cone.
 *
 * This function handles surface normals for both the side and caps
 * of a cone, accounting for transformations. The world-space point
 * is transformed to object space, and normals are computed accordingly:
 * - Returns (0, ±1, 0) if the point is on a cap.
 * - Returns (0, 0, 0) if the point is at the tip.
 * - Otherwise, delegates to `cone_side_normal` for the side surface.
 *
 * @param obj The cone object whose normal is being computed.
 * @param world_point The point in world space.
 * @return The normal vector at the given point on the cone.
 */
t_tuple	normal_at_cone(t_object *obj, t_tuple world_point)
{
	t_cone		*cone;
	t_matrix	*inv;
	t_tuple		local_p;
	t_tuple		local_normal;

	cone = (t_cone *)obj;
	inv = invert_matrix(obj->transf);
	local_p = transform_world_to_object(world_point, inv);
	free_matrix(inv);
	local_normal = compute_local_cone_normal(cone, local_p);
	return (transform_normal_to_world(obj, local_normal));
}
