/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cone_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:28:58 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:32:03 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// t_world	*scene_icecream(void)
// {
// 	t_world		*w;
// 	t_plane		*floor, *left_wall, *right_wall;
// 	t_cylinder	*house_col1, *house_col2;
// 	t_cone		*roof_cone, *ice_cone;
// 	t_sphere	*scoop1, *scoop2, *scoop3;
// 	t_patt	*floor_pat, *wall_pat_left, *wall_pat_right;
// 	t_patt	*pat_col1, *pat_col2, *roof_pat;
// 	t_patt	*cone_pat, *scoop1_pat, *scoop2_pat, *scoop3_pat;
// 	t_matrix	*transform, *left_rot, *right_rot;
// 	int			object_count = 0;

// 	// Floor
// 	floor = ft_plane();
// 	floor->base.m = ft_material();
// 	floor->base.m.specular = 0;
// 	floor_pat = malloc(sizeof(t_patt));
// 	*floor_pat = uv_checkers_patt(ft_colour(0.5, 0, 0.9),
					// ft_colour(0, 0.8, 0.8), 2, 2);
// 	floor_pat->transform = create_identity_matrix(4);
// 	floor->base.m.patt = floor_pat;
// 	object_count++;

// 	// Left wall
// 	left_wall = ft_plane();
// 	left_wall->base.m = ft_material();
// 	left_wall->base.m.specular = 0;
// 	wall_pat_left = malloc(sizeof(t_patt));
// 	*wall_pat_left = uv_gradient_patt(ft_colour(0.5, 0, 0.9),
						// ft_colour(0, 0.8, 0.8), 0, 0);
// 	wall_pat_left->transform = multiply_matrices(rotate_y(-M_PI/4),
						// multiply_matrices(rotate_x(M_PI/2), scale(1, 1, 1)));
// 	left_wall->base.m.patt = wall_pat_left;
// 	left_rot = multiply_matrices(rotate_y(-M_PI/4), rotate_x(M_PI/2));
// 	set_transf(left_wall, multiply_matrices(translate(-5, 0, 0), left_rot));
// 	free_matrix(left_rot);
// 	object_count++;

// 	// Right wall
// 	right_wall = ft_plane();
// 	right_wall->base.m = ft_material();
// 	right_wall->base.m.specular = 0;
// 	wall_pat_right = malloc(sizeof(t_patt));
// 	*wall_pat_right = uv_stripe_patt(ft_colour(0.5, 0, 0.9),
						// ft_colour(0, 0.8, 0.8), 10, 1);
// 	wall_pat_right->transform = multiply_matrices(rotate_y(M_PI/4),
				// multiply_matrices(rotate_x(M_PI/2), scale(1, 1, 1)));
// 	right_wall->base.m.patt = wall_pat_right;
// 	right_rot = multiply_matrices(rotate_y(M_PI/4), rotate_x(M_PI/2));
// 	set_transf(right_wall, multiply_matrices(translate(5, 0, 0), right_rot));
// 	free_matrix(right_rot);
// 	object_count++;

// 	// House - Left Column
// 	house_col1 = ft_cylinder();
// 	house_col1->base.m = ft_material();
// 	pat_col1 = malloc(sizeof(t_patt));
// 	*pat_col1 = uv_checkers_patt(ft_colour(0, 0, 0.7),
									// ft_colour(0, 0.3, 0.7), 6, 6);
// 	pat_col1->transform = create_identity_matrix(4);
// 	house_col1->base.m.patt = pat_col1;
// 	house_col1->min = 0;
// 	house_col1->max = 2.5;
// 	house_col1->closed = true;
// 	transform = multiply_matrices(scale(0.3, 1.5, 0.3), translate(-5, 0, -10));
// 	set_transf(house_col1, transform);
// 	object_count++;

// 	// House - Right Column
// 	house_col2 = ft_cylinder();
// 	house_col2->base.m = ft_material();
// 	pat_col2 = malloc(sizeof(t_patt));
// 	*pat_col2 = uv_checkers_patt(ft_colour(0, 0, 0.7),
				// ft_colour(0, 0.3, 0.7), 6, 6);
// 	pat_col2->transform = create_identity_matrix(4);
// 	house_col2->base.m.patt = pat_col2;
// 	house_col2->min = 0;
// 	house_col2->max = 2.5;
// 	house_col2->closed = true;
// 	transform = multiply_matrices(scale(0.3, 1.5, 0.3), translate(5, 0, -9));
// 	set_transf(house_col2, transform);
// 	object_count++;

// 	// House - Roof Cone
// 	roof_cone = ft_cone();
// 	roof_cone->base.m = ft_material();
// 	roof_pat = malloc(sizeof(t_patt));
// 	*roof_pat = uv_checkers_patt(ft_colour(0.8, 0.3, 0.1),
					// ft_colour(0.9, 0.6, 0.3), 10, 10);
// 	roof_pat->transform = create_identity_matrix(4);
// 	roof_cone->base.m.patt = roof_pat;
// 	// roof_cone->base.m.c = ft_colour(0.8, 0.3, 0.1);
// 	roof_cone->min = -2;
// 	roof_cone->max = 0;
// 	roof_cone->closed = true;
// 	transform = multiply_matrices(scale(1, 0.8, 1), translate(-0.1, 3.5, -1));
// 	set_transf(roof_cone, transform);
// 	object_count++;

// 	// Ice Cream - Cone
// 	ice_cone = ft_cone();
// 	ice_cone->base.m = ft_material();
// 	cone_pat = malloc(sizeof(t_patt));
// 	*cone_pat = uv_checkers_patt(ft_colour(0.9, 0.6, 0.3),
					// ft_colour(0.9, 0.5, 0.2), 35, 35);
// 	cone_pat->transform = create_identity_matrix(4);
// 	ice_cone->base.m.patt = cone_pat;

// 	// ice_cone->base.m.c = ft_colour(0.9, 0.6, 0.3);
// 	ice_cone->min = 0;
// 	ice_cone->max = 2;
// 	ice_cone->closed = false;
// 	transform = multiply_matrices(scale(0.5, 1.0, 0.5),
					// translate(-1.3, -0.2, -4.5));
// 	set_transf(ice_cone, transform);
// 	object_count++;

// 	// Ice Cream - Scoop 1 (Bottom)
// 	scoop1 = ft_sphere(1);
// 	scoop1->base.m = ft_material();
// 	scoop1_pat = malloc(sizeof(t_patt));
// 	*scoop1_pat = uv_checkers_patt(ft_colour(1, 0.2, 1),
					// ft_colour(1, 1, 0), 6, 6);
// 	scoop1_pat->transform = create_identity_matrix(4);
// 	scoop1->base.m.patt = scoop1_pat;
// 	transform = multiply_matrices(scale(0.4, 0.4, 0.4),
					// translate(-1.5, 4.6, -8.5));
// 	set_transf(scoop1, transform);
// 	object_count++;

// 	// Ice Cream - Scoop 2 (Middle)
// 	scoop2 = ft_sphere(1);
// 	scoop2->base.m = ft_material();
// 	scoop2_pat = malloc(sizeof(t_patt));
// 	*scoop2_pat = ring_patt(ft_colour(0.3, 1, 0.3),
					// ft_colour(0.9, 0.9, 0.3));
// 	scoop2_pat->transform = create_identity_matrix(4);
// 	scoop2->base.m.patt = scoop2_pat;
// 	transform = multiply_matrices(scale(0.4, 0.4, 0.4),
					// translate(-3.5, 4.6, -8.5));
// 	set_transf(scoop2, transform);
// 	object_count++;

// 	// Ice Cream - Scoop 3 (Top)
// 	scoop3 = ft_sphere(1);
// 	scoop3->base.m = ft_material();
// 	scoop3_pat = malloc(sizeof(t_patt));
// 	*scoop3_pat = uv_stripe_patt(ft_colour(0.8, 0.8, 1),
					// ft_colour(1, 0.7, 0.7), 2, 2);
// 	scoop3_pat->transform = create_identity_matrix(4);
// 	scoop3->base.m.patt = scoop3_pat;
// 	transform = multiply_matrices(scale(0.4, 0.4, 0.4),
					// translate(-2.5, 6.3, -8.5));
// 	set_transf(scoop3, transform);
// 	object_count++;

// 	// Create world
// 	w = ft_world();
// 	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
		// ft_colour(1, 1, 1), 1.0));
// 	w->objects = malloc(sizeof(t_object *) * object_count);
// 	if (!w->objects)
// 		return (NULL);

// 	// Assign all objects
// 	w->objects[0] = &floor->base;
// 	w->objects[1] = &left_wall->base;
// 	w->objects[2] = &right_wall->base;
// 	w->objects[3] = &house_col1->base;
// 	w->objects[4] = &house_col2->base;
// 	w->objects[5] = &roof_cone->base;
// 	w->objects[6] = &ice_cone->base;
// 	w->objects[7] = &scoop1->base;
// 	w->objects[8] = &scoop2->base;
// 	w->objects[9] = &scoop3->base;

// 	w->object_count = object_count;
// 	return (w);
// }

// void	draw_icecream(t_engine *engine)
// {
// 	t_world		*w;
// 	t_camera	cam;
// 	t_tuple		n;

// 	w = scene_icecream();
// 	n = normal_at((t_object *)w->objects[3], ft_tuple(1, 3, 0, POINT));
// 	printf("Side normal: (%.2f, %.2f, %.2f)\n", n.x, n.y, n.z);
// 	cam = ft_camera(WIN_SIZE, WIN_SIZE, 60);//try to not change
// 	cam.transf = view_transform(
// 		ft_tuple(0, 4, -10, POINT),     // camera up and back
// 		ft_tuple(0, 0, 0, POINT),      // looking at the center
// 		ft_tuple(0, 1, 0, VECTOR));//up vector
// 	printf("render\n");
// 	render(cam, w, &engine->image);
// 	mlx_put_image_to_window(engine->mlx, engine->window,
// 		engine->image.img_ptr, 0, 0);
// 	free_world(w);
// 	free_matrix(cam.transf);
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
