/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world_shadow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:43:33 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:43:57 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

// static t_world	*shadow_scene(void)
// {
// 	t_world		*w;
// 	t_sphere	*s1;
// 	t_sphere	*s2;
// 	t_sphere	*s3;
// 	t_sphere	*floor;
// 	t_sphere	*left_wall;
// 	t_sphere	*right_wall;
// 	t_matrix	*transform;

// 	w = ft_world();
// 	t_light *l1 = ft_light(ft_tuple(-10, 10, -10, POINT),
					// ft_colour(1, 1, 1), 1.0); // White light on left
// 	t_light *l2 = ft_light(ft_tuple(10, 0, -10, POINT),
					// ft_colour(1, 1, 1), 1.0);  // White light on right

// 	add_light_to_world(w, l1);
// 	add_light_to_world(w, l2);
// 	s1 = ft_sphere(1);
// 	s1->base.m.c = ft_colour(0.1, 1, 0.5);
// 	s1->base.m.diffuse = 0.7;
// 	s1->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.9, 0.9, 0.9),
				// translate(-0.5, -0.5, 0.5));
// 	set_transf(s1, transform);

// 	//s2
// 	s2 = ft_sphere(1);
// 	s2->base.m.c = ft_colour(0.5, 1, 0.1);
// 	s2->base.m.diffuse = 0.7;
// 	s2->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.5, 0.5, 0.5), translate(3, -2, 0.5));
// 	set_transf(s2, transform);

// 	//s3
// 	s3 = ft_sphere(1);
// 	s3->base.m.c = ft_colour(1, 0.8, 1);
// 	s3->base.m.diffuse = 0.7;
// 	s3->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.33, 0.33, 0.33),
					// translate(-5, -3.5, 0.7));
// 	set_transf(s3, transform);

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
// 	w->objects = malloc(sizeof(t_object *) * 6);
// 	if (!w->objects)
// 		return (NULL);
// 	w->objects[0] = s1;
// 	w->objects[1] = s2;
// 	w->objects[2] = s3;
// 	w->objects[3] = floor;
// 	w->objects[4] = left_wall;
// 	w->objects[5] = right_wall;
// 	w->object_count = 6;
// 	return (w);
// }

// void	draw_world_with_shadows(t_engine *engine)
// {
// 	t_camera	cam;
// 	t_world		*w;

// 	w = shadow_scene();
// 	cam = ft_camera(WIN_SIZE, WIN_SIZE, 60);
// 	cam.transf = view_transform(ft_tuple(0, 0, -5, POINT),
// 								ft_tuple(0, 0, 0, POINT),
// 								ft_tuple(0, 1, 0, VECTOR));
// 	render(cam, w, &engine->image);
// 	free_matrix(cam.transf);
// 	free_world(w);
// }
