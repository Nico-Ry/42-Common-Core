/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:13:26 by ameechan          #+#    #+#             */
/*   Updated: 2025/04/21 23:13:15 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_pl(t_plane *pl, t_ray *ray, t_hitlist **xs)
{
	double	t;
	t_hit	*hit;

	if (fabs(ray->direction.y) < 0.0001)
		return ;
	t = -ray->origin.y / ray->direction.y;
	hit = intersection(t, pl);
	add_hit(xs, hit);
}
