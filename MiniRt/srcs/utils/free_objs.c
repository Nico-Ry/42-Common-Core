/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:14:56 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:14:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

void	free_material(t_material *m)
{
	if (m && m->patt)
		free_patt(m->patt);
}

void	free_sphere(t_sphere *sphere)
{
	if (!sphere)
		return ;
	if (sphere->base.transf)
		free_matrix(sphere->base.transf);
	free_material(&sphere->base.m);
	free(sphere);
}

void	free_plane(t_plane *plane)
{
	if (!plane)
		return ;
	if (plane->base.transf)
		free_matrix(plane->base.transf);
	free_material(&plane->base.m);
	free(plane);
}

void	free_cylinder(t_cylinder *cyl)
{
	if (!cyl)
		return ;
	if (cyl->base.transf)
		free_matrix(cyl->base.transf);
	free_material(&cyl->base.m);
	free(cyl);
}

void	free_cone(t_cone *cone)
{
	if (!cone)
		return ;
	if (cone->base.transf)
		free_matrix(cone->base.transf);
	free_material(&cone->base.m);
	free(cone);
}
