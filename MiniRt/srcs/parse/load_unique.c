/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_unique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:23:16 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 18:23:16 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

void	load_ambient(char **tokens, t_parsed_scene *scene)
{
	scene->ambient_ratio = ft_atof(tokens[1]);
	scene->ambient_color = parse_color(tokens[2]);
	scene->has_ambient = 1;
}

void	load_camera(char **tokens, t_parsed_scene *scene)
{
	scene->camera_pos = parse_point(tokens[1]);
	scene->camera_dir = parse_tuple(tokens[2], VECTOR);
	scene->fov = ft_atof(tokens[3]);
	scene->has_camera = 1;
}

void	load_light(char **tokens, t_parsed_scene *scene, bool bonus)
{
	if (scene->light_count >= MAX_LIGHTS)
		return ;
	scene->light_positions[scene->light_count] = parse_point(tokens[1]);
	scene->brightness[scene->light_count] = ft_atof(tokens[2]);
	if (!bonus)
		scene->light_colours[scene->light_count] = ft_colour(1, 1, 1);
	else
		scene->light_colours[scene->light_count] = parse_color(tokens[3]);
	scene->light_count++;
}
