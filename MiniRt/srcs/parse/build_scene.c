/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:48:42 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 19:48:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"
#include "tests.h"

t_object	**alloc_objects_array(t_parsed_scene *scene, int *total)
{
	t_object	**objects;
	int			count;
	int			i;

	count = scene->sphere_count
		+ scene->plane_count
		+ scene->cylinder_count
		+ scene->cone_count;
	objects = malloc(sizeof(t_object *) * count);
	if (!objects)
		malloc_err("Failed to allocate objects");
	i = 0;
	while (i < count)
	{
		objects[i] = NULL;
		i++;
	}
	*total = count;
	return (objects);
}

t_world	*convert_scene_to_world(t_parsed_scene *scene)
{
	t_world		*w;
	t_object	**objects;
	int			count;
	int			i;

	w = ft_world();
	if (!w)
		malloc_err("Failed to allocate world");
	objects = alloc_objects_array(scene, &count);
	i = 0;
	i = add_spheres(objects, scene, i);
	i = add_planes(objects, scene, i);
	i = add_cylinders(objects, scene, i);
	i = add_cones(objects, scene, i);
	add_lights(w, scene);
	w->ambient.ratio = scene->ambient_ratio;
	w->ambient.colour = scene->ambient_color;
	w->objects = (void **)objects;
	w->object_count = count;
	return (w);
}

t_parsed_scene	init_parsed_scene(void)
{
	t_parsed_scene	scene;

	scene.ambient_ratio = 0;
	scene.ambient_color = ft_colour(0, 0, 0);
	scene.has_ambient = 0;
	scene.has_camera = 0;
	scene.fov = 0;
	scene.camera_pos = ft_point(0, 0, 0);
	scene.camera_dir = ft_vector(0, 0, 1);
	scene.light_count = 0;
	scene.sphere_count = 0;
	scene.plane_count = 0;
	scene.cylinder_count = 0;
	scene.cone_count = 0;
	return (scene);
}

void	dispatch_token(t_tokens *current, t_parsed_scene *scene, bool bonus)
{
	if (current->type == A)
		load_ambient(current->tokens, scene);
	else if (current->type == C)
		load_camera(current->tokens, scene);
	else if (current->type == L)
		load_light(current->tokens, scene, bonus);
	else if (current->type == PL)
		load_plane(current->tokens, scene);
	else if (current->type == SP)
		load_sphere(current->tokens, scene);
	else if (current->type == CY)
		load_cylinder(current->tokens, scene);
	else if (current->type == CO)
		load_cone(current->tokens, scene);
}

t_parsed_scene	build_scene_from_tokens(t_tokens *head, bool bonus)
{
	t_parsed_scene	scene;
	t_tokens		*current;

	scene = init_parsed_scene();
	current = head;
	while (current)
	{
		dispatch_token(current, &scene, bonus);
		current = current->next;
	}
	return (scene);
}
