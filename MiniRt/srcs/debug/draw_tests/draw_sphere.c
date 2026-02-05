/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:53:59 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:54:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// static int	compute_color(void *sph, t_ray *ray, t_light *l)
// {
// 	t_hitlist	**xs;
// 	t_hit		*hit;
// 	t_tuple		pt;
// 	t_colour	c;
// 	t_shading	shad;

// 	xs = new_hitlist();
// 	intersect(sph, ray, xs);
// 	hit = find_visible_hit(xs);
// 	if (hit && hit->t >= 0)
// 	{
// 		pt = get_point(ray, hit->t);
// 		shad.m = ((t_object *)sph)->m;
// 		shad.l = l;
// 		shad.point = pt;
// 		shad.eyev = ft_negate(ray->direction);
// 		shad.normalv = normal_at(sph, pt);
// 		c = ft_shading(shad, false);
// 	}
// 	else
// 		c = ft_colour(0, 0, 0);
// 	free_hitlist(xs);
// 	return (convert_colour_to_int(c));
// }

// static void	render_sphere_loop(t_render_ctx *ctx,
					// t_image *img, t_light *light)
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
// 			wall_point = compute_wall_point(x, y,
				// ctx->pixel_size, ctx->half);
// 			ray = create_ray_to_point(ctx->ray_origin, wall_point);
// 			color = compute_color(ctx->sph, ray, light);
// 			put_pixel(img, x, y, color);
// 			free_ray(ray);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_sphere(t_engine *engine)
// {
// 	t_render_ctx	ctx;
// 	t_light			*light;

// 	ctx.ray_origin = ft_tuple(0, 0, -5, POINT);
// 	ctx.sph = ft_sphere(1.0);
// 	ctx.sph->centre = ft_tuple(0, 0, 0, POINT);
// 	ctx.sph->base.m = ft_material();
// 	ctx.sph->base.m.c = ft_colour(1, 0.2, 1);
// 	ctx.sph->base.m.ambient = 0.1;
// 	ctx.sph->base.m.diffuse = 0.9;
// 	ctx.sph->base.m.specular = 0.9;
// 	ctx.sph->base.m.shininess = 200.0;
// 	ctx.pixel_size = WALL_SIZE / (double)CANVAS_SIZE;
// 	ctx.half = WALL_SIZE / 2.0;

// 	light = ft_light(ft_tuple(-10, 10, -10, POINT),
			// ft_colour(1, 1, 1), 1.0);
// 	render_sphere_loop(&ctx, &engine->image, light);
// 	free_sphere(ctx.sph);
// 	free(light);
// }
