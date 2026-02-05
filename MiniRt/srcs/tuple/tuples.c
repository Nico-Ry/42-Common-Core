/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:07:01 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:07:33 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_tuple	ft_tuple(double x, double y, double z, t_tpl type)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = type;
	return (tuple);
}

t_tuple	normalize(t_tuple v)
{
	double	len;
	t_tuple	normal;

	len = magnitude(v);
	normal.w = VECTOR;
	normal.x = v.x / len;
	normal.y = v.y / len;
	normal.z = v.z / len;
	return (normal);
}
