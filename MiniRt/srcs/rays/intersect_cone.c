/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:46:55 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 19:46:55 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Swaps the values of two doubles.
 *
 * This helper is used to ensure `t0 <= t1` when comparing
 * ray intersection distances. This ordering is needed for
 * consistent intersection validation and rendering.
 *
 * @param a Pointer to the first value.
 * @param b Pointer to the second value.
 */
static void	swap_vals(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief Validates ray hits against the cone's vertical bounds.
 *
 * This function takes the raw intersection t-values and checks if the
 * corresponding y-positions fall within the cone's `min` and `max` height.
 * Valid hits are converted to `t_hit` objects and added to the hit list.
 *
 * If necessary, t0 and t1 are swapped to ensure correct ordering.
 *
 * @param xs The hit list to which valid intersections will be added.
 * @param cone The cone object being intersected.
 * @param ray The ray in object space used for the intersection.
 * @param d The t0 and t1 values from the cone’s quadratic intersection.
 */
void	validate_cone_hits(t_hitlist **xs, t_cone *c, t_ray *r, t_cone_vals d)
{
	double	y0;
	double	y1;
	t_hit	*h0;
	t_hit	*h1;

	h0 = NULL;
	h1 = NULL;
	if (d.t0 > d.t1)
		swap_vals(&d.t0, &d.t1);
	y0 = r->origin.y + d.t0 * r->direction.y;
	y1 = r->origin.y + d.t1 * r->direction.y;
	if (c->min < y0 && y0 < c->max)
		h0 = intersection(d.t0, c);
	if (c->min < y1 && y1 < c->max)
		h1 = intersection(d.t1, c);
	if (h1)
		add_hit(xs, h1);
	if (h0)
		add_hit(xs, h0);
}

/**
 * @brief Handles quadratic intersection logic for a cone.
 *
 * This static helper computes the intersection of a ray with a cone's
 * side surface by solving the quadratic equation. It adds valid hits
 * and delegates cap intersection to another function.
 *
 * @param cone The cone object being tested.
 * @param ray The ray in the cone’s object space.
 * @param xs The hit list to store valid intersections.
 */
static void	cone_quadratic_intersections(t_cone *cone, t_ray *r, t_hitlist **xs)
{
	t_cone_vals	d;
	double		a;
	double		b;
	double		c;
	double		disc;

	a = pow(r->direction.x, 2) - pow(r->direction.y, 2)
		+ pow(r->direction.z, 2);
	b = 2 * (r->origin.x * r->direction.x
			- r->origin.y * r->direction.y
			+ r->origin.z * r->direction.z);
	c = pow(r->origin.x, 2) - pow(r->origin.y, 2) + pow(r->origin.z, 2);
	if (fabs(a) < EPSILON && fabs(b) >= EPSILON)
	{
		d.t0 = -c / (2 * b);
		add_hit(xs, intersection(d.t0, cone));
		return ;
	}
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return ;
	d.t0 = (-b - sqrt(disc)) / (2 * a);
	d.t1 = (-b + sqrt(disc)) / (2 * a);
	validate_cone_hits(xs, cone, r, d);
}

/**
 * @brief Computes the intersections of a ray with a cone (side and caps).
 *
 * Transforms the ray into object space, handles all valid intersections
 * with the cone’s body and end caps. Adds hits to the intersection list.
 *
 * @param shape The cone as a generic object.
 * @param ray The ray in world space.
 * @param xs The list of intersections to populate.
 */
void	intersect_cone(t_object *shape, t_ray *ray, t_hitlist **xs)
{
	t_cone		*cone;
	t_ray		*local_ray;
	t_matrix	*inverse;

	cone = (t_cone *)shape;
	inverse = invert_matrix(cone->base.transf);
	local_ray = transform(ray, inverse);
	if (!(fabs(local_ray->direction.x) < EPSILON
			&& fabs(local_ray->direction.y) < EPSILON
			&& fabs(local_ray->direction.z) < EPSILON))
		cone_quadratic_intersections(cone, local_ray, xs);
	intersect_cone_caps(xs, cone, local_ray);
	free_matrix(inverse);
	free(local_ray);
}
