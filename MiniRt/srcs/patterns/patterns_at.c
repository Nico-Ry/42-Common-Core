/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:40:26 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:40:50 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Returns the color of a stripe pattern at a given point.
 *
 * @param pattern The pattern containing stripe colors and frequency.
 * @param point A point in pattern space.
 * @return Color A or B depending on the x-position.
 *
 * The pattern alternates between color A
 *  and B every 1/frequency units along the x-axis.
 */
t_colour	stripe_at(t_patt *patt, t_tuple point, t_object *obj)
{
	double	freq;
	int		stripe_index;

	if (patt->frequency > 0)
		freq = patt->frequency;
	else
		freq = 1.0;
	stripe_index = (int)floor(point.x * freq);
	if (stripe_index % 2 == 0)
	{
		if (patt->a_patt)
			return (patt_colour_at(patt->a_patt, point, obj));
		return (patt->a);
	}
	else
	{
		if (patt->b_patt)
			return (patt_colour_at(patt->b_patt, point, obj));
		return (patt->b);
	}
}

/**
 * @brief Returns a gradient color between two base colors.
 *
 * @param patt The gradient patt.
 * @param point The point in patt space.
 * @return A blended color between patt->a and patt->b based on x-position.
 *
 * The interpolation occurs between floor(x) and x, blending proportionally.
 * Frequency is not used in this patt.
 */
t_colour	gradient_at(t_patt *patt, t_tuple point)
{
	t_colour	distance;
	double		fraction;

	distance = diff_colours(patt->b, patt->a);
	fraction = point.x - floor(point.x);
	return (add_colours(patt->a, mult_colour(distance, fraction)));
}

/**
 * @brief Returns the color of a ring patt at a given point.
 *
 * @param patt The patt with colors and frequency.
 * @param point A point in patt space (typically object-local space).
 * @return Color A or B depending on the ring index.
 *
 * This patt creates concentric rings (circles) using
 * the distance from the origin
 * in the XZ plane. The frequency determines how many rings
 * appear per unit of distance.
 *
 * ring_offset is a small value added to avoid the center always
 * rendering as a solid color.
 * frequency controls the number of rings per unit — higher = more
 * tightly packed rings.
 */
t_colour	ring_at(t_patt *patt, t_tuple point, t_object *obj)
{
	double		dist;
	int			ring_index;
	double		ring_offset;
	double		freq;

	ring_offset = 0.01;
	if (patt->frequency > 0)
		freq = patt->frequency;
	else
		freq = 12.0;
	dist = sqrt(point.x * point.x + point.z * point.z);
	dist += ring_offset;
	ring_index = (int)floor(dist * freq);
	if (ring_index % 2 == 0)
	{
		if (patt->a_patt)
			return (patt_colour_at(patt->a_patt, point, obj));
		return (patt->a);
	}
	else
	{
		if (patt->b_patt)
			return (patt_colour_at(patt->b_patt, point, obj));
		return (patt->b);
	}
}

/**
 * @brief Returns the color for a 3D checkers patt at a given point.
 *
 * @param patt The patt with two alternating colors.
 * @param point The point in patt space.
 * @return Color A or B depending on the parity of the integer position sum.
 *
 * This patt alternates color on every integer step in X, Y, or Z,
 * producing a 3D checkerboard effect. Frequency is not used.
 */
t_colour	checkers_at(t_patt *patt, t_tuple point, t_object *obj)
{
	int			sum;
	double		freq;

	if (patt->frequency > 0)
		freq = patt->frequency;
	else
		freq = 1.0;
	sum = (int)(floor(point.x * freq)
			+ floor(point.y * freq)
			+ floor(point.z * freq));
	if (sum % 2 == 0)
	{
		if (patt->a_patt)
			return (patt_colour_at(patt->a_patt, point, obj));
		return (patt->a);
	}
	else
	{
		if (patt->b_patt)
			return (patt_colour_at(patt->b_patt, point, obj));
		return (patt->b);
	}
}
