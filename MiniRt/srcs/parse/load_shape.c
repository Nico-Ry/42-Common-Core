/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:29:55 by nryser            #+#    #+#             */
/*   Updated: 2025/05/06 20:30:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "parse.h"

void	load_sphere(char **tokens, t_parsed_scene *scene)
{
	t_sphere_input	sphere;

	sphere.position = parse_point(tokens[1]);
	sphere.diameter = ft_atof(tokens[2]);
	sphere.color = parse_color(tokens[3]);
	sphere.patt_type = 0;
	if (count_split(tokens) == 5)
		sphere.patt_type = ft_atoi(tokens[4]);
	scene->spheres[scene->sphere_count++] = sphere;
}

void	load_plane(char **tokens, t_parsed_scene *scene)
{
	t_plane_input	p;

	p.position = parse_point(tokens[1]);
	p.normal = parse_point(tokens[2]);
	p.color = parse_color(tokens[3]);
	p.patt_type = 0;
	if (count_split(tokens) == 5)
		p.patt_type = ft_atoi(tokens[4]);
	scene->planes[scene->plane_count++] = p;
}

void	load_cylinder(char **tokens, t_parsed_scene *scene)
{
	t_cylinder_input	cy;

	cy.position = parse_point(tokens[1]);
	cy.normal = normalize(parse_point(tokens[2]));
	cy.diameter = ft_atof(tokens[3]);
	cy.height = ft_atof(tokens[4]);
	cy.color = parse_color(tokens[5]);
	cy.patt_type = 0;
	if (count_split(tokens) == 7)
		cy.patt_type = ft_atoi(tokens[6]);
	scene->cylinders[scene->cylinder_count++] = cy;
}

void	load_cone(char **tokens, t_parsed_scene *scene)
{
	t_cone_input	cone;

	cone.position = parse_point(tokens[1]);
	cone.normal = parse_tuple(tokens[2], VECTOR);
	cone.diameter = ft_atof(tokens[3]);
	cone.min = ft_atof(tokens[4]);
	cone.max = ft_atof(tokens[5]);
	cone.color = parse_color(tokens[6]);
	cone.patt_type = 0;
	if (count_split(tokens) == 8)
		cone.patt_type = ft_atoi(tokens[7]);
	scene->cones[scene->cone_count++] = cone;
}
