/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:16:15 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:16:15 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_sphere	*ft_sphere(double radius)
{
	t_sphere	*sphere;
	static int	id;

	if (id == 0)
		id++;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
	{
		printf(R_B"Error:"RES" failed to allocate memory for sphere.\n");
		exit(1);
	}
	sphere->id = id++;
	sphere->centre = ft_tuple(0, 0, 0, POINT);
	sphere->radius = radius;
	sphere->base.type = SPHERE;
	sphere->base.transf = create_identity_matrix(4);
	sphere->base.m = ft_material();
	return (sphere);
}

t_plane	*ft_plane(void)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		malloc_err("ft_plane");
	plane->base.transf = create_identity_matrix(4);
	plane->base.m = ft_material();
	plane->base.type = PLANE;
	plane->base.m.ambient = 0.2;
	plane->base.m.diffuse = 0.7;
	plane->base.m.specular = 0.3;
	return (plane);
}

t_cylinder	*ft_cylinder(void)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cyl)
		malloc_err("ft_cylinder");
	cyl->base.transf = create_identity_matrix(4);
	cyl->base.m = ft_material();
	cyl->base.type = CYLINDER;
	cyl->radius = 1;
	cyl->centre = ft_tuple(0, 0, 0, POINT);
	cyl->min = -INFINITY;
	cyl->max = INFINITY;
	cyl->closed = false;
	return (cyl);
}

t_cone	*ft_cone(void)
{
	t_cone	*cone;

	cone = malloc(sizeof(t_cone));
	if (!cone)
		malloc_err("make_cone");
	cone->base.type = CONE;
	cone->base.transf = create_identity_matrix(4);
	cone->base.m = ft_material();
	cone->min = -INFINITY;
	cone->max = INFINITY;
	cone->closed = false;
	return (cone);
}
