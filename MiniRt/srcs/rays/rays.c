/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:12:29 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:12:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_ray	*ft_ray(t_tuple origin, t_tuple direction)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		malloc_err("ray");
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

/**
 * @brief Finds the point at the given distance `t` along `ray`
 */
t_tuple	get_point(t_ray *ray, double t)
{
	t_tuple	point;
	t_tuple	mult_tup;

	mult_tup = mult_tuple(ray->direction, t);
	point = add_tuple(ray->origin, mult_tup);
	return (point);
}
