/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_silhouette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:28:14 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:28:33 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

// static t_tuple	compute_wall_point(int x, int y,
						// double px_size, double half)
// {
// 	double	world_x;
// 	double	world_y;

// 	world_x= -half + px_size * x;
// 	world_y = half - px_size * y;
// 	return (ft_tuple(world_x, world_y, WALL_Z, POINT));
// }

// static t_ray	*create_ray_to_point(t_tuple origin, t_tuple target)
// {
// 	t_tuple	direction;
// 	t_tuple	origin_copy;
// 	t_ray	*ray;
// 	t_tuple	diff;

// 	diff = diff_tuple(target, origin);
// 	direction = normalize(diff);
// 	origin_copy = ft_tuple(origin.x, origin.y, origin.z, origin.w);
// 	ray = ft_ray(origin_copy, direction);
// 	return (ray);
// }

// static int	compute_pixel_color(t_sphere *sphere, t_ray *ray)
// {
// 	t_hitlist	**xs;
// 	t_hit		*hit;
// 	int			color;

// 	xs = new_hitlist();
// 	intersect(sphere, ray, xs);
// 	hit = find_visible_hit(xs);
// 	if (hit && hit->t >= 0)
// 		color = RED;
// 	else
// 		color = BLACK;
// 	free_hitlist(xs);
// 	return (color);
// }

// static void	render_loop(t_render_ctx *ctx, t_image *img)
// {
// 	int		x;
// 	int		y;
// 	t_tuple	wall_point;
// 	t_ray	*ray;
// 	int		color;

// 	y = 0;
// 	while (y < CANVAS_SIZE)
// 	{
// 		print_progress_bar(y, CANVAS_SIZE - 1);
// 		x = 0;
// 		while (x < CANVAS_SIZE)
// 		{
// 			wall_point = compute_wall_point(x, y, ctx->pixel_size, ctx->half);
// 			ray = create_ray_to_point(ctx->ray_origin, wall_point);
// 			color = compute_pixel_color(ctx->sph, ray);
// 			put_pixel(img, x, y, color);
// 			free_ray(ray);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_silhouette(t_engine *engine)
// {
// 	t_render_ctx	ctx;

// 	ctx.ray_origin = ft_tuple(0, 0, -5, POINT);
// 	ctx.sph = ft_sphere(1.0);
// 	ctx.sph->centre.z = 10;
// 	set_transf(ctx.sph, scale(5, 5, 5));
// 	ctx.pixel_size = WALL_SIZE / (double)WIN_SIZE;
// 	ctx.half = WALL_SIZE / 2.0;
// 	render_loop(&ctx, &engine->image);
// 	free_sphere(ctx.sph);
// }
