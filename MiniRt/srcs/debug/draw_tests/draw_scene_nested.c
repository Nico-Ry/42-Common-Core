/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_nested.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:57:00 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:57:47 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// static t_world	*scene_planes()
// {
// 	t_world		*w;
// 	// t_sphere	*s1;
// 	// t_sphere	*s2;
// 	// t_sphere	*s3;
// 	t_plane		*floor;
// 	// t_matrix	*transform;
// 	int			object_count = 0;

// // //Big green sphere
// // 	s1 = ft_sphere(1);
// // 	s1->base.m.c = ft_colour(0.1, 1, 0.5);
// // 	s1->base.m.diffuse = 0.7;
// // 	s1->base.m.specular = 0.3;
// // 	transform = multiply_matrices(scale(0.9, 0.9, 0.9),
						// translate(-0.5, 0.9, 0.5));
// // 	set_transf(s1, transform);
// // 	object_count++;

// // //Small green sphere
// // 	s2 = ft_sphere(1);
// // 	s2->base.m.c = ft_colour(0.5, 1, 0.1);
// // 	s2->base.m.diffuse = 0.7;
// // 	s2->base.m.specular = 0.3;
// // 	transform = multiply_matrices(scale(0.5, 0.5, 0.5),
						// translate(3, 1, -2.8));
// // 	set_transf(s2, transform);
// // 	object_count++;

// // //Lilac sphere
// // 	s3 = ft_sphere(1);
// // 	s3->base.m.c = ft_colour(1, 0.8, 1);
// // 	s3->base.m.diffuse = 0.7;
// // 	s3->base.m.specular = 0.3;
// // 	transform = multiply_matrices(scale(0.33, 0.33, 0.33),
						// translate(-5, 0.8, -2.7));
// // 	set_transf(s3, transform);
// // 	object_count++;

// //Floor
// 	floor = ft_plane();
// 	t_patt *nested_checkers = malloc(sizeof(t_patt));
// 	nested_checkers->type = PATTERN_CHECKERS;
// 	nested_checkers->frequency = 4.0;
// 	nested_checkers->a_patt = make_diagonal_stripe(ft_colour(1, 0.2, 1),
								// ft_colour(0, 0, 0), M_PI / 4);
// 	nested_checkers->b_patt = make_diagonal_stripe(ft_colour(1, 1, 0),
								// ft_colour(0, 0, 0), -M_PI / 4);
// 	nested_checkers->transform = create_identity_matrix(4); // no transform

// 	floor->base.m.patt = nested_checkers;
// 	floor->base.m.ambient = 0.1;
// 	floor->base.m.diffuse = 0.9;
// 	floor->base.m.specular = 0.0;
// 	object_count++;

// // //right wall
// // 	t_plane	*right_wall = ft_plane();
// // 	set_transf(right_wall, multiply_matrices(rotate_y(M_PI/4),
					// rotate_x(M_PI/2)));
// // 	set_transf(right_wall, multiply_matrices(translate(0,0,10),
				// right_wall->base.transf));
// // 	right_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// // 	right_wall->base.m.specular = 0;
// // 	object_count++;

// // //left wall
// // 	t_plane	*left_wall = ft_plane();
// // 	set_transf(left_wall, multiply_matrices(rotate_y(-M_PI/4),
					// rotate_x(M_PI/2)));
// // 	set_transf(left_wall, multiply_matrices(translate(0,0,10),
					// left_wall->base.transf));
// // 	left_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// // 	left_wall->base.m.specular = 0;
// // 	object_count++;

// //World
// 	w = ft_world();
// 	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
				// ft_colour(1, 1, 1), 1.0));
// 	w->objects = malloc(sizeof(t_object *) * object_count);
// 	if (!w->objects)
// 		return (NULL);
// 	w->objects[0] = floor;
// 	// w->objects[1] = s1;
// 	// w->objects[2] = s2;
// 	// w->objects[3] = s3;

// 	// w->objects[4] = right_wall;
// 	// w->objects[5] = left_wall;
// 	w->object_count = object_count;
// 	return (w);
// }

// void	draw_scene_nested(t_engine *engine)
// {
// 	t_world		*w;
// 	t_camera	cam;

// 	w = scene_planes();
// 	cam = ft_camera(WIN_SIZE, WIN_SIZE, 60);//try to not change
// 	cam.transf = view_transform(
// 		ft_tuple(0, 2, -7, POINT),//from camera
// 		ft_tuple(0, 0, 10, POINT),//look at target
// 		ft_tuple(0, 1, 0, VECTOR));//up vector
// 	render(cam, w, &engine->image);
// 	mlx_put_image_to_window(engine->mlx, engine->window,
// 		engine->image.img_ptr, 0, 0);
// 	free_world(w);
// 	free_matrix(cam.transf);
// }
