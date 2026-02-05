/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:58:04 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:58:25 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

// static t_tuple	compute_wall_point(int x, int y,
						// double px_size, double half)
// {
// 	double	world_x;
// 	double	world_y;

// 	world_x = -half + px_size * x;
// 	world_y = half - px_size * y;
// 	return (ft_tuple(world_x, world_y, WALL_Z, POINT));
// }

// static t_ray	*create_ray_to_point(t_tuple origin, t_tuple target)
// {
// 	t_tuple	diff;
// 	t_tuple	direction;

// 	diff = diff_tuple(target, origin);
// 	direction = normalize(diff);
// 	return (ft_ray(origin, direction));
// }

// static t_world	*simple_world(void)
// {
// 	t_world		*w;
// 	t_sphere	*s1;
// 	t_sphere	*floor;
// 	t_sphere	*left_wall;
// 	t_sphere	*right_wall;
// 	t_matrix	*transform;

// 	w = ft_world();
// 	s1 = ft_sphere(1);
// 	s1->base.m.c = ft_colour(1, 0.2, 0.4);
// 	s1->base.m.diffuse = 0.7;
// 	s1->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.9, 0.9, 0.9),
					// translate(-0.5, -0.5, 0.5));
// 	set_transf(s1, transform);

// 	//floor
// 	floor = ft_sphere(1);
// 	floor->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	floor->base.m.specular = 0;
// 	transform = multiply_matrices(translate(0, -1.5, -1), scale(10, 0.01, 10));
// 	set_transf(floor, transform);

// 	//left wall
// 	left_wall = ft_sphere(1);
// 	left_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	left_wall->base.m.specular = 0;
// 	transform = multiply_matrices(translate(0, 0, 5),
// 		multiply_matrices( rotate_y(-M_PI / 4),
// 			multiply_matrices(rotate_x(M_PI / 2),scale(10, 0.01, 10))));
// 	set_transf(left_wall, transform);

// 	//right wall
// 	right_wall = ft_sphere(1);
// 	right_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	right_wall->base.m.specular = 0;
// 	transform = multiply_matrices(translate(0, 0, 5),
// 		multiply_matrices(
// 			multiply_matrices( rotate_y(M_PI / 4),
				// rotate_x(M_PI / 2)),scale(10, 0.01, 10)));
// 	set_transf(right_wall, transform);

// 	w->objects = malloc(sizeof(t_object *) * 4);
// 	w->objects[0] = s1;
// 	w->objects[1] = floor;
// 	w->objects[2] = left_wall;
// 	w->objects[3] = right_wall;
// 	w->object_count = 4;

// 	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
					// ft_colour(1, 1, 1), 1.0));
// 	return (w);
// }

// static void	render_world_loop(t_render_ctx *ctx, t_image *img)
// {
// 	int		x;
// 	int		y;
// 	int		color;
// 	t_ray	*ray;
// 	t_tuple	pt;

// 	y = 0;
// 	while (y < CANVAS_SIZE)
// 	{
// 		print_progress_bar(y, CANVAS_SIZE - 1);
// 		x = 0;
// 		while (x < CANVAS_SIZE)
// 		{
// 			pt = compute_wall_point(x, y, ctx->pixel_size, ctx->half);
// 			ray = create_ray_to_point(ctx->ray_origin, pt);
// 			color = convert_colour_to_int(color_at(ctx->world, ray, 1));
// 			put_pixel(img, x, y, color);
// 			free_ray(ray);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_world(t_engine *engine)
// {
// 	t_render_ctx	ctx;

// 	ctx.world = simple_world();
// 	ctx.ray_origin = ft_tuple(0, 0, -7, POINT);
// 	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
// 	ctx.half = WALL_SIZE / 2.0;
// 	render_world_loop(&ctx, &engine->image);
// 	free_world(ctx.world);
// }

/*(Eye-level View)
cam.transf = view_transform(
	ft_tuple(0, 0, -5, POINT),     // from: camera position
	ft_tuple(0, 0, 0, POINT),      // to: where camera is looking
	ft_tuple(0, 1, 0, VECTOR));    // up: camera's "up" direction

	(Top-down View)
	cam.transf = view_transform(
	ft_tuple(0, 10, 0, POINT),     // from: camera placed 10 units "above"
	ft_tuple(0, 0, 0, POINT),      // to: looking at the origin
	ft_tuple(0, 0, -1, VECTOR));   // up: z-axis now defines camera's "up"

	(from above and behind)
	cam.transf = view_transform(
	ft_tuple(5, 5, -5, POINT),     // camera up and back
	ft_tuple(0, 0, 0, POINT),      // looking at the center
	ft_tuple(0, 1, 0, VECTOR));    // standard up
	*/
