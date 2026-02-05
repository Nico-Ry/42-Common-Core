/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:32:27 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:32:27 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_tuple	ft_reflect(t_tuple in, t_tuple normal)
{
	double	dot_product;
	t_tuple	temp;
	t_tuple	reflect;

	dot_product = dot(in, normal);
	temp = mult_tuple(normal, 2 * dot_product);
	reflect = diff_tuple(in, temp);
	return (reflect);
}

t_light	*ft_light(t_tuple position, t_colour lum, double brightness)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		malloc_err("ft_light");
	light->pos = position;
	light->lum = lum;
	light->brightness = brightness;
	return (light);
}
