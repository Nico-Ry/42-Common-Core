/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:14:01 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:14:01 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

void	set_transf(void *obj, t_matrix *trans)
{
	t_object	*o;

	o = (t_object *)obj;
	if (o->transf && o->transf != trans)
	{
		free_matrix(o->transf);
		o->transf = NULL;
	}
	((t_object *)obj)->transf = trans;
}

t_ray	*transform(t_ray *r, t_matrix *inverse)
{
	t_ray		*new;
	t_matrix	*temp;
	t_matrix	*ray_mtx;

	new = malloc(sizeof(t_ray));
	if (!new)
		malloc_err("transform");
	temp = tuple_to_matrix(r->direction);
	ray_mtx = multiply_matrices(inverse, temp);
	new->direction = matrix_to_tuple(ray_mtx);
	new->direction.w = VECTOR;
	free_matrix(temp);
	free_matrix(ray_mtx);
	temp = tuple_to_matrix(r->origin);
	ray_mtx = multiply_matrices(inverse, temp);
	new->origin = matrix_to_tuple(ray_mtx);
	new->origin.w = POINT;
	free_matrix(temp);
	free_matrix(ray_mtx);
	return (new);
}
