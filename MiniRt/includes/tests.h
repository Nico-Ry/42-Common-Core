/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:19:33 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:19:38 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <string.h>
# include "minirt.h"
# include "engine.h"

typedef struct s_tuple		t_tuple;
typedef struct s_matrix		t_matrix;
typedef struct s_ray_sphere	t_ray_sphere;
typedef struct s_hit		t_hit;
typedef struct s_light		t_light;
typedef struct s_material	t_material;
typedef struct s_colour		t_colour;
typedef struct s_camera		t_camera;
typedef enum e_obj_type		t_obj;

//#############################################
//################# DEBUG #####################
//#############################################
//print.c

void		print_normal(t_tuple tuple, t_tuple expected, t_obj type);
void		print_reflected(t_tuple tuple, t_tuple expected);
void		print_light(t_light *l, char *name);
void		print_material(t_material m);
int			equal_material(t_material m, t_material expected);
int			equal_colour(t_colour c1, t_colour c2);
int			printable_material(t_material m);
void		print_matrix(t_matrix *matrix);
void		print_test_banner(const char *word);
void		print_test_number(int *i);
void		print_sub_header(const char *word, int *i);
void		print_intersections(t_hit **xs, int count, int sorted);
void		print_hitlist(t_hitlist **xs);

// void		print_rs(t_ray_sphere *rs);//	obsolete
//#############################################
//############### DRAW TESTS ##################
//#############################################
//draw_circle.c
void		draw_circle_scene(t_engine *engine);
int			draw_circle(int run);

//draw_clock.c
void		draw_clock_scene(t_engine *engine);
int			draw_hour_markers(int run);

//draw_cone.c
void		draw_cone(t_engine *engine);

//draw_cone_scene.c
void		draw_icecream(t_engine *engine);

//draw cylinders
void		draw_cyl_infinite(t_engine *engine);
void		draw_cyl_truncated(t_engine *engine);
void		draw_cyl_capped(t_engine *engine);

//draw_planes.c
void		draw_planes(t_engine *engine);

//draw_projectile.c
void		draw_trajectory_scene(t_engine *engine);
int			draw_trajectory(int run);

//draw_scene_pattern.c
void		draw_scene_patterns_full(t_engine *engine);

//draw_silhouette.c
void		draw_silhouette(t_engine *engine);

//draw_sphere_pattern.c
void		draw_sphere_pattern(t_engine *engine);

//draw_spehere_uv.c
void		draw_sphere_uv(t_engine *engine);

//draw_sphere_nested.c
void		draw_sphere_nested(t_engine *engine);

//draw_scene_nested.c
void		draw_scene_nested(t_engine *engine);

//draw_sphere.c
void		draw_sphere(t_engine *engine);

//draw_world_shadow.c
void		draw_world_with_shadows(t_engine *engine);

//draw_world.c
void		draw_world(t_engine *engine);

//draw_utils.c
t_tuple		compute_wall_point(int x, int y, double px_size, double half);
t_ray		*create_ray_to_point(t_tuple origin, t_tuple target);

//draw_idea.c
void		draw_idea(t_engine *engine);

//draw_simple_cone.c
void		draw_simple_cone(t_engine *engine);

//#############################################
//################## TESTS ####################
//#############################################

//test_cone.c
int			cone_intersection_test(int run);
int			cone_cap_intersection_test(int run);
int			cone_normal_vector_test(int run);

//test_normal_at.c
int			normal_at_test(int run);

//test_patterns.c
int			stripe_patt_test(int run);
int			patt_lighting_test(int run);
int			stripe_transform_test(int run);
int			patt_generalization_test(int run);
int			gradient_patt_test(int run);
int			ring_patt_test(int run);
int			checkers_patt_test(int run);

//test_phong.c
int			light_test(int run);
int			material_test(int run);
int			shading_test(int run);

//test_cylinders.c
int			test_intersect_cylinder(int run);
int			test_normal_at_cylinder(int run);
int			test_truncate_cylinder(int run);

//test_planes.c
int			local_normal_plane_test(int run);
int			intersect_plane_test(int run);

//test_ray_for_pixel.c
int			ray_for_pixel_test(int run);

//test_rays.c
/**
 * @brief runs tests for position (p.58)
 * @note tests for `get_point(t_ray *ray, double t)`
 */
int			position_test(int run);
int			sph_unique_id(int run, int num);
int			count_hits(t_hitlist **xs);
int			sph_ray_intersect(int run);
int			intersection_test(int run);
int			ray_transform_test(int run);
int			ray_transform_test2(int run);

//test_shadows.c
int			shadows_test(int run);

//test_transform.c
/**
 * @brief runs all tests for translation, scaling and rotation
 * @param x 1 to run x rotation tests, 0 to skip
 * @param y 1 to run y rotation tests, 0 to skip
 * @param z 1 to run z rotation tests, 0 to skip
 * @return 0 if all tests pass, 1 if any test fails
 */
int			rotate_test(int x, int y, int z);
int			scale_test(int run);
int			translate_test(int run);
int			chained_test(int run);

//test_tuples.c
int			test_matrix_to_tuple(int run);
int			test_tuple_to_matrix(int run);

//test_world.c
int			world_test(int run);
int			default_world_test(int run);
int			intersect_world_test(int run);
int			ft_pre_compute_test(int run);
int			shade_hit_test(int run);
int			color_at_test(int run);

//view_transform_test.c
int			view_transform_test(int run);
int			camera_test(int run);

//#############################################
//################## MAIN #####################
//#############################################
//main_cone.c
int			ft_main_cone(int run);
//main_cyl.c
int			ft_main_cylinder(int run);
//main_patterns.c
int			ft_main_patt(int run);
//main_phong.c
int			ft_main_phong(int run);

//main_rays.c
int			ft_main_rays(int run);

//main_renders.c
int			ft_main_draw_2d(int run);
int			ft_main_draw_silhouette(int run);
int			ft_main_draw_sphere(int run);
int			ft_main_draw_world(int run);
int			ft_main_draw_world_shadows(int run);
int			ft_main_draw_world_shadows(int run);
int			ft_main_draw_world_planes(int run);
int			ft_main_draw_infinite_cylinders(int run);
int			ft_main_draw_truncated_cylinders(int run);
int			ft_main_draw_sphere_pattern(int run);
int			ft_main_draw_sphere_uv(int run);
int			ft_main_draw_sphere_nested(int run);
int			ft_main_draw_scene_nested(int run);
int			ft_main_draw_capped_cylinders(int run);
int			ft_main_draw_scene_patterns_full(int run);
int			ft_main_draw_cone(int run);
int			ft_main_draw_icecream(int run);
int			ft_main_draw_idea(int run);
int			ft_main_draw_simple_cone(int run);

//main_transform.c
int			ft_main_transform(int run);

//main_tuples.c
int			ft_main_tuples(int run);

//main_view.c
int			ft_main_view(int run);
int			ft_main_shadows(int run);
int			ft_main_plane(int run);

//main_world.c
int			ft_main_world(int run);

#endif
