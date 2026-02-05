/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:07:53 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:07:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

double	dot(t_tuple a, t_tuple b)
{
	double	w_product;
	double	x_product;
	double	y_product;
	double	z_product;

	if (a.w == POINT || b.w == POINT)
	{
		printf("[DEBUG] `dot` . Attempting dot product of POINT\n");
		exit(1);
	}
	w_product = a.w * b.w;
	x_product = a.x * b.x;
	y_product = a.y * b.y;
	z_product = a.z * b.z;
	return (w_product + x_product + y_product + z_product);
}

/**
 * @brief Calculates and returns a vector that is perpendicular
 * to both vectors given as arguments
 * @note the order of the arguments is important! `a cross b` is
 * NOT the same as `b cross a`
 */
t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	cross;

	if (a.w == POINT || b.w == POINT)
	{
		printf("[DEBUG] `cross` . Attempting cross product of POINT\n");
		exit(1);
	}
	cross.w = VECTOR;
	cross.x = (a.y * b.z) - (a.z * b.y);
	cross.y = (a.z * b.x) - (a.x * b.z);
	cross.z = (a.x * b.y) - (a.y * b.x);
	return (cross);
}
