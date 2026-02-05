/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:38:01 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:35:22 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// t_tuple	compute_wall_point(int x, int y, double px_size, double half)
// {
// 	double	world_x;
// 	double	world_y;

// 	world_x = -half + px_size * x;
// 	world_y = half - px_size * y;
// 	return (ft_tuple(world_x, world_y, WALL_Z, POINT));
// }
// t_ray	*create_ray_to_point(t_tuple origin, t_tuple target)
// {
// 	t_tuple	diff;
// 	t_tuple	direction;

// 	diff = diff_tuple(target, origin);
// 	direction = normalize(diff);
// 	return (ft_ray(origin, direction));
// }
