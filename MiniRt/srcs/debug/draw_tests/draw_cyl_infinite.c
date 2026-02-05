/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cyl_infinite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:52:03 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:52:34 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// t_world	*scene_cyl_infinite()
// {
// 	t_world		*w;
// 	t_cylinder	*cyl1;
// 	t_cylinder	*cyl2;
// 	t_cylinder	*cyl3;
// 	t_matrix	*transform;
// 	int			object_count = 0;

// //dark green cylinder
// 	cyl1 = ft_cylinder();
// 	cyl1->base.m.c = ft_colour(0.1, 1, 0.5);
// 	cyl1->base.m.diffuse = 0.7;
// 	cyl1->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.9, 0.9, 0.9),
				// translate(-0.5, 0.9, 0.5));
// 	set_transf(cyl1, transform);
// 	object_count++;

// //light green cylinder
// 	cyl2 = ft_cylinder();
// 	cyl2->base.m.c = ft_colour(0.5, 1, 0.1);
// 	cyl2->base.m.diffuse = 0.7;
// 	cyl2->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.5, 0.5, 0.5),
					// translate(4.9, 1, -2.8));
// 	set_transf(cyl2, transform);
// 	object_count++;

// //Lilac cylinder
// 	cyl3 = ft_cylinder();
// 	cyl3->base.m.c = ft_colour(1, 0.8, 1);
// 	cyl3->base.m.diffuse = 0.7;
// 	cyl3->base.m.specular = 0.3;
// 	transform = multiply_matrices(scale(0.33, 0.33, 0.33),
				// translate(-13.2, 0.8, -2.7));
// 	set_transf(cyl3, transform);
// 	object_count++;

// // //Floor
// // 	t_plane	*floor = ft_plane();
// // 	floor->base.m.c = ft_colour(0.8, 0.8, 0.8);
// // 	floor->base.m.specular = 0;
// // 	object_count++;

// //right wall
// 	t_plane	*right_wall = ft_plane();
// 	set_transf(right_wall, multiply_matrices(rotate_y(M_PI/4),
							// rotate_x(M_PI/2)));
// 	set_transf(right_wall, multiply_matrices(translate(0,0,10),
							// right_wall->base.transf));
// 	right_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	right_wall->base.m.specular = 0;
// 	object_count++;

// //left wall
// 	t_plane	*left_wall = ft_plane();
// 	set_transf(left_wall, multiply_matrices(rotate_y(-M_PI/4),
							// rotate_x(M_PI/2)));
// 	set_transf(left_wall, multiply_matrices(translate(0,0,10),
							// left_wall->base.transf));
// 	left_wall->base.m.c = ft_colour(0.8, 0.8, 0.8);
// 	left_wall->base.m.specular = 0;
// 	object_count++;

// //World
// 	w = ft_world();
// 	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
							// ft_colour(1, 1, 1), 1.0));
// 	w->objects = malloc(sizeof(t_object *) * object_count);
// 	if (!w->objects)
// 		return (NULL);
// 	w->objects[0] = cyl1;
// 	w->objects[1] = cyl2;
// 	w->objects[2] = cyl3;
// 	// w->objects[3] = floor;
// 	w->objects[3] = right_wall;
// 	w->objects[4] = left_wall;
// 	w->object_count = object_count;
// 	return (w);
// }

// void	draw_cyl_infinite(t_engine *engine)
// {
// 	t_world		*w;
// 	t_camera	cam;

// 	w = scene_cyl_infinite();
// 	cam = ft_camera(WIN_SIZE, WIN_SIZE, 60);//try to not change
// 	cam.transf = view_transform(
// 		ft_tuple(6, 2, -15, POINT),//from camera
// 		ft_tuple(-2, 0, 20, POINT),//look at target
// 		ft_tuple(0, 1, 0, VECTOR));//up vector
// 	render(cam, w, &engine->image);
// 	mlx_put_image_to_window(engine->mlx, engine->window,
// 		engine->image.img_ptr, 0, 0);
// 	free_world(w);
// 	free_matrix(cam.transf);
// }
