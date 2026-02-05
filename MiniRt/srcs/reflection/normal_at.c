/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:32:11 by nryser            #+#    #+#             */
/*   Updated: 2026/02/05 16:14:57 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_tuple	ft_world_normal(t_matrix *inverse, t_tuple local_normal)
{
	t_matrix	*transposed_inverse;
	t_matrix	*local_n_mtx;
	t_matrix	*world_normal_mtx;
	t_tuple		world_normal;

	local_n_mtx = tuple_to_matrix(local_normal);
	transposed_inverse = transpose_matrix(inverse);
	world_normal_mtx = multiply_matrices(transposed_inverse, local_n_mtx);
	world_normal = matrix_to_tuple(world_normal_mtx);
	world_normal.w = 0;
	free_matrix(transposed_inverse);
	free_matrix(local_n_mtx);
	free_matrix(world_normal_mtx);
	return (normalize(world_normal));
}

t_tuple	ft_local_point(t_matrix *inverse, t_tuple world_point)
{
	t_matrix	*local_point_mtx;
	t_matrix	*object_point_mtx;
	t_tuple		local_p;

	local_point_mtx = tuple_to_matrix(world_point);
	object_point_mtx = multiply_matrices(inverse, local_point_mtx);
	local_p = matrix_to_tuple(object_point_mtx);
	local_p.w = POINT;
	free_matrix(local_point_mtx);
	free_matrix(object_point_mtx);
	return (local_p);
}

t_tuple	normal_at(void *shape, t_tuple world_p)
{
	t_tuple		local_normal;
	t_tuple		local_p;
	t_tuple		world_normal;
	t_matrix	*inverse;

	inverse = invert_matrix(((t_object *)shape)->transf);
	local_p = ft_local_point(inverse, world_p);
	local_normal = local_normal_at(shape, local_p);
	world_normal = ft_world_normal(inverse, local_normal);
	free_matrix(inverse);
	return (world_normal);
}

static t_tuple	local_normal_at_cyl(t_cylinder *cyl, t_tuple p)
{
	double	dist;

	dist = ft_sqr(p.x) + ft_sqr(p.z);
	if ((dist < 1) && (p.y >= cyl->max - EPSILON))
		return (ft_tuple(0, 1, 0, VECTOR));
	else if ((dist < 1) && (p.y <= cyl->min + EPSILON))
		return (ft_tuple(0, -1, 0, VECTOR));
	else
		return (ft_tuple(p.x, 0, p.z, VECTOR));
}

t_tuple	local_normal_at(void *shape, t_tuple local_p)
{
	t_tuple		normal = ft_tuple(0, 0, 0, VECTOR);
	t_object	*obj;

	obj = (t_object *)shape;
	if (obj->type == SPHERE)
		normal = (diff_tuple(local_p, ((t_sphere *)shape)->centre));
	else if (obj->type == PLANE)
		normal = ft_tuple(0, 1, 0, VECTOR);
	else if (obj->type == CYLINDER)
		normal = local_normal_at_cyl((t_cylinder *)shape, local_p);
	else if (obj->type == CONE)
		normal = normal_at_cone((t_object *)shape, local_p);
	return (normal);
}
