/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_simple_cone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:39:54 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:40:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

// t_world	*simple_cone_capped(void)
// {
// 	t_world		*w;
// 	t_plane		*floor;
// 	t_plane		*left_wall;
// 	t_plane		*right_wall;
// 	t_patt	*floor_pat;
// 	t_patt	*wall_pat_left;
// 	t_patt	*wall_pat_right;

// 	t_matrix	*transform;
// 	t_matrix	*left_rot;
// 	t_matrix	*right_rot;
// 	t_cone		*cone1;
// 	t_cone		*cone2;
// 	t_cone		*cone3;
// 	int			object_count;
// 	object_count = 0;
// 	// Floor — UV checkers
// 	floor = ft_plane();
// 	floor->base.m = ft_material();
// 	floor->base.m.specular = 0;
// 	floor_pat = malloc(sizeof(t_patt));
// 	*floor_pat = uv_checkers_patt(
// 		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 2, 2);
// 	floor_pat->transform = create_identity_matrix(4);
// 	floor->base.m.patt = floor_pat;
// 	object_count++;
// 	// Left wall — UV gradient
// 	left_wall = ft_plane();
// 	left_wall->base.m = ft_material();
// 	left_wall->base.m.specular = 0;
// 	wall_pat_left = malloc(sizeof(t_patt));
// 	*wall_pat_left = uv_gradient_patt(
// 		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 0, 0);
// 	wall_pat_left->transform = multiply_matrices(
// 		rotate_y(-M_PI / 4), multiply_matrices(rotate_x(M_PI / 2),
								// scale(1, 1, 1)));
// 	left_wall->base.m.patt = wall_pat_left;
// 	left_rot = multiply_matrices(rotate_y(-M_PI / 4), rotate_x(M_PI / 2));
// 	set_transf(left_wall, multiply_matrices(translate(-5, 0, 0), left_rot));
// 	free_matrix(left_rot);
// 	object_count++;

// 	// Right wall — UV stripes
// 	right_wall = ft_plane();
// 	right_wall->base.m = ft_material();
// 	right_wall->base.m.specular = 0;
// 	wall_pat_right = malloc(sizeof(t_patt));
// 	*wall_pat_right = uv_stripe_patt(
// 		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 10, 1);
// 	wall_pat_right->transform = multiply_matrices(
// 		rotate_y(M_PI / 4), multiply_matrices(rotate_x(M_PI / 2),
								// scale(1, 1, 1)));
// 	right_wall->base.m.patt = wall_pat_right;
// 	right_rot = multiply_matrices(rotate_y(M_PI / 4), rotate_x(M_PI / 2));
// 	set_transf(right_wall, multiply_matrices(translate(5, 0, 0), right_rot));
// 	free_matrix(right_rot);
// 	object_count++;

// 	//red cone1
// 	cone1 = ft_cone();
// 	cone1->base.m.c = ft_colour(1, 0.3, 0.5);
// 	cone1->base.m.diffuse = 0.7;
// 	cone1->base.m.specular = 0.3;
// 	cone1->min = -3;
// 	cone1->max = 0;
// 	cone1->closed = true;
// 	transform = multiply_matrices(scale(1, 1, 1), translate(3, 1, -0.5));

// 	set_transf((t_object *)cone1, transform);
// 	printf("[cone-transformed] min: %.2f max: %.2f\n", cone1->min, cone1->max);
// 	object_count++;

// 	//blue cone2
// 	cone2 = ft_cone();
// 	cone2->base.m.c = ft_colour(0.2, 0.7, 1);
// 	cone2->base.m.diffuse = 0.7;
// 	cone2->base.m.specular = 0.3;
// 	cone2->min = -2;
// 	cone2->max = 0;
// 	cone2->closed = true;
// 	transform =  multiply_matrices(multiply_matrices(
					// translate(-3, 1, -2),rotate_z(M_PI/4)), scale(1, 1, 1));
// 	set_transf(cone2, transform);
// 	object_count++;

// 	//green cone3
// 	cone3 = ft_cone();
// 	cone3->base.m.c = ft_colour(0.1, 1, 0.6);
// 	cone3->base.m.diffuse = 0.7;
// 	cone3->base.m.specular = 0.3;
// 	cone3->min = -3;
// 	cone3->max = 3;
// 	cone3->closed = true;
// 	transform = multiply_and_free(translate(0, 2, -3), scale(1 , 1, 1));
// 	set_transf(cone3, transform);
// 	object_count++;

// 	// World and light
// 	w = ft_world();
// 	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
			// ft_colour(1, 1, 1), 1.0));

// 	w->objects = malloc(sizeof(t_object *) * object_count);
// 	if (!w->objects)
// 		return (NULL);

// 	w->objects[0] = &floor->base;
// 	w->objects[1] = &left_wall->base;
// 	w->objects[2] = &right_wall->base;

// 	w->objects[3] = &cone1->base;
// 	w->objects[4] = &cone2->base;
// 	w->objects[5] = &cone3->base;

// 	w->object_count = object_count;

// 	return (w);
// }

// void	draw_simple_cone(t_engine *engine)
// {
// 	t_world		*w;
// 	t_camera	cam;
// 	t_tuple		n;

// 	w = simple_cone_capped();
// 	n = normal_at((t_object *)w->objects[3], ft_tuple(1, 3, 0, POINT));
// 	printf("Side normal: (%.2f, %.2f, %.2f)\n", n.x, n.y, n.z);
// 	cam = ft_camera(WIN_SIZE, WIN_SIZE, 70);//try to not change
// 	cam.transf = view_transform(
// 		ft_tuple(0, 5, -15, POINT),     // camera up and back
// 		ft_tuple(0, 0, 0, POINT),      // looking at the center
// 		ft_tuple(0, 1, 0, VECTOR));//up vector
// 	printf("render\n");
// 	render(cam, w, &engine->image);
// 	mlx_put_image_to_window(engine->mlx, engine->window,
// 		engine->image.img_ptr, 0, 0);
// 	free_world(w);
// 	free_matrix(cam.transf);
// }
