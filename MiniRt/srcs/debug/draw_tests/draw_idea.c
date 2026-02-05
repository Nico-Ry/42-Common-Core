/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_idea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:56:50 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:56:50 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

// t_patt *make_uv_pattern(t_patt (*fn)(t_colour, t_colour, int, int),
// 						   t_colour a, t_colour b, int width, int height)
// {
// 	t_patt *pat = malloc(sizeof(t_patt));
// 	if (!pat)
// 		return (NULL);
// 	*pat = fn(a, b, width, height);
// 	pat->transform = create_identity_matrix(4);
// 	return (pat);
// }

// t_plane *make_wall(double x_offset, double y_rot_angle, t_patt *pat)
// {
// 	t_plane *wall = ft_plane();
// 	wall->base.m = ft_material();
// 	wall->base.m.specular = 0;
// 	wall->base.m.patt = pat;
// 	t_matrix *rot = multiply_matrices(rotate_y(y_rot_angle),
						// rotate_x(M_PI / 2));
// 	set_transf(wall, multiply_matrices(translate(x_offset, 0, 0), rot));
// 	free_matrix(rot);
// 	return wall;
// }

// t_cylinder *make_column(t_colour a, t_colour b,
				// double tx, double ty, double tz)
// {
// 	t_cylinder *col = ft_cylinder();
// 	col->base.m = ft_material();
// 	col->base.m.patt = make_uv_pattern(uv_checkers_patt, a, b, 6, 6);
// 	col->min = 0;
// 	col->max = 2.5;
// 	col->closed = true;
// 	t_matrix *m = multiply_matrices(scale(0.3, 1.5, 0.3),
					// translate(tx, ty, tz));
// 	set_transf(col, m);
// 	free_matrix(m);
// 	return col;
// }

// t_cone *make_cone_obj(t_colour a, t_colour b, int check_w, int check_h,
// 					  double min, double max, bool closed,
// 					  t_matrix *scale_m, t_matrix *trans_m)
// {
// 	t_cone *cone = ft_cone();
// 	cone->base.m = ft_material();
// 	cone->base.m.patt = make_uv_pattern(uv_checkers_patt,
							// a, b, check_w, check_h);
// 	cone->min = min;
// 	cone->max = max;
// 	cone->closed = closed;
// 	t_matrix *m = multiply_matrices(scale_m, trans_m);
// 	set_transf(cone, m);
// 	free_matrix(m);
// 	return cone;
// }

// t_sphere *make_scoop(t_patt *pat, double sx, double sy,
					// double sz, double tx, double ty, double tz)
// {
// 	t_sphere *s = ft_sphere(1);
// 	s->base.m = ft_material();
// 	s->base.m.patt = pat;
// 	t_matrix *m = multiply_matrices(scale(sx, sy, sz), translate(tx, ty, tz));
// 	set_transf(s, m);
// 	free_matrix(m);
// 	return s;
// }
// #include "minirt.h"

// static void	add_object(t_object **arr, void *obj, int *index)
// {
// 	arr[*index] = obj;
// 	(*index)++;
// }

// static t_patt	*make_pattern(t_patt (*func)(t_colour,t_colour),
						// t_colour a, t_colour b)
// {
// 	t_patt *pat = malloc(sizeof(t_patt));
// 	*pat = func(a, b);
// 	pat->transform = create_identity_matrix(4);
// 	return pat;
// }

// static void	set_object(t_object *obj, t_patt *pat, t_matrix *tr)
// {
// 	obj->m = ft_material();
// 	obj->m.patt = pat;
// 	set_transf(obj, tr);
// }

// t_world	*scene_idea(void)
// {
// 	t_world		*w;
// 	t_object	**objs = malloc(sizeof(t_object *) * 10);
// 	int			idx = 0;

// 	t_plane *floor = ft_plane();
// 	set_object(&floor->base, make_uv_pattern(uv_checkers_patt,
// 		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 2, 2),
// 		create_identity_matrix(4));
// 	floor->base.m.specular = 0;
// 	add_object(objs, &floor->base, &idx);

// 	t_matrix *left_rot = multiply_matrices(rotate_y(-M_PI / 4),
							// rotate_x(M_PI / 2));
// 	t_plane *left_wall = ft_plane();
// 	set_object(&left_wall->base, make_uv_pattern(uv_gradient_patt,
// 		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 0, 0),
// 		multiply_matrices(translate(-5, 0, 0), left_rot));
// 	left_wall->base.m.specular = 0;
// 	free_matrix(left_rot);
// 	add_object(objs, &left_wall->base, &idx);

// 	t_matrix *right_rot = multiply_matrices(rotate_y(M_PI / 4),
							// rotate_x(M_PI / 2));
// 	t_plane *right_wall = ft_plane();
// 	set_object(&right_wall->base, make_uv_pattern(uv_stripe_patt,
// 		ft_colour(0.5, 0, 0.9), ft_colour(0, 0.8, 0.8), 10, 1),
// 		multiply_matrices(translate(5, 0, 0), right_rot));
// 	right_wall->base.m.specular = 0;
// 	free_matrix(right_rot);
// 	add_object(objs, &right_wall->base, &idx);

// 	t_cylinder *col1 = ft_cylinder();
// 	col1->min = 0; col1->max = 2.5; col1->closed = true;
// 	set_object(&col1->base, make_uv_pattern(uv_checkers_patt,
// 		ft_colour(0, 0, 0.7), ft_colour(0, 0.3, 0.7), 6, 6),
// 		multiply_matrices(scale(0.3, 1.5, 0.3), translate(-5, 0, -10)));
// 	add_object(objs, &col1->base, &idx);

// 	t_cylinder *col2 = ft_cylinder();
// 	col2->min = 0; col2->max = 2.5; col2->closed = true;
// 	set_object(&col2->base, make_uv_pattern(uv_checkers_patt,
// 		ft_colour(0, 0, 0.7), ft_colour(0, 0.3, 0.7), 6, 6),
// 		multiply_matrices(scale(0.3, 1.5, 0.3), translate(5, 0, -9)));
// 	add_object(objs, &col2->base, &idx);

// 	t_cone *roof = ft_cone();
// 	roof->min = -2; roof->max = 0; roof->closed = true;
// 	set_object(&roof->base, make_uv_pattern(uv_checkers_patt,
// 		ft_colour(0.8, 0.3, 0.1), ft_colour(0.9, 0.6, 0.3), 10, 10),
// 		multiply_matrices(scale(1, 0.8, 1), translate(-0.1, 3.5, -1)));
// 	add_object(objs, &roof->base, &idx);

// 	t_cone *ice_cone = ft_cone();
// 	ice_cone->min = 0; ice_cone->max = 2; ice_cone->closed = false;
// 	set_object(&ice_cone->base, make_uv_pattern(uv_checkers_patt,
// 		ft_colour(0.9, 0.6, 0.3), ft_colour(0.9, 0.5, 0.2), 35, 35),
// 		multiply_matrices(scale(0.5, 1.0, 0.5), translate(-1.3, -0.2, -4.5)));
// 	add_object(objs, &ice_cone->base, &idx);

// 	t_sphere *s1 = ft_sphere(1);
// 	set_object(&s1->base, make_uv_pattern(uv_checkers_patt,
// 		ft_colour(1, 0.2, 1), ft_colour(1, 1, 0), 6, 6),
// 		multiply_matrices(scale(0.4, 0.4, 0.4), translate(-1.5, 4.6, -8.5)));
// 	add_object(objs, &s1->base, &idx);

// 	t_sphere *s2 = ft_sphere(1);
// 	set_object(&s2->base, make_pattern(ring_patt,
// 		ft_colour(0.3, 1, 0.3), ft_colour(0.9, 0.9, 0.3)),
// 		multiply_matrices(scale(0.4, 0.4, 0.4), translate(-3.5, 4.6, -8.5)));
// 	add_object(objs, &s2->base, &idx);

// 	t_sphere *s3 = ft_sphere(1);
// 	set_object(&s3->base, make_uv_pattern(uv_stripe_patt,
// 		ft_colour(0.8, 0.8, 1), ft_colour(1, 0.7, 0.7), 2, 2),
// 		multiply_matrices(scale(0.4, 0.4, 0.4), translate(-2.5, 6.3, -8.5)));
// 	add_object(objs, &s3->base, &idx);

// 	w = ft_world();
// 	add_light_to_world(w, ft_light(ft_tuple(-10, 10, -10, POINT),
						// ft_colour(1, 1, 1), 1.0));
// 	w->objects = (void **)objs;
// 	w->object_count = idx;
// 	return (w);
// }

// void	draw_idea(t_engine *engine)
// {
// 	t_world		*w;
// 	t_camera	cam;
// 	t_tuple		n;

// 	w = scene_idea();
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
