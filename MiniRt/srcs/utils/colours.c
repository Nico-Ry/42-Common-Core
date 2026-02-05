/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:10:56 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:10:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_colour	ft_colour(double r, double g, double b)
{
	t_colour	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_colour	add_colours(t_colour	a, t_colour b)
{
	t_colour	new;

	new.r = a.r + b.r;
	new.g = a.g + b.g;
	new.b = a.b + b.b;
	return (new);
}

t_colour	diff_colours(t_colour a, t_colour b)
{
	t_colour	result;

	result.r = a.r - b.r;
	result.g = a.g - b.g;
	result.b = a.b - b.b;
	return (result);
}

t_colour	mult_colour(t_colour c, double num)
{
	t_colour	new;

	new.r = c.r * num;
	new.g = c.g * num;
	new.b = c.b * num;
	return (new);
}

t_colour	blend_colours(t_colour c1, t_colour c2)
{
	t_colour	new;

	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
	return (new);
}
