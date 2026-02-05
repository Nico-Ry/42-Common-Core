/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uv_patterns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:42:30 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:42:40 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_patt	uv_stripe_patt(t_colour a, t_colour b, int width, int height)
{
	t_patt	p;

	p.type = PATTERN_UV_STRIPE;
	p.a = a;
	p.b = b;
	p.a_patt = NULL;
	p.b_patt = NULL;
	p.transform = create_identity_matrix(4);
	p.width = width;
	p.height = height * 0 + 1;
	p.frequency = 0.0;
	return (p);
}

t_patt	uv_gradient_patt(t_colour a, t_colour b, int width, int height)
{
	t_patt	p;

	p.type = PATTERN_UV_GRADIENT;
	p.a = a;
	p.b = b;
	p.a_patt = NULL;
	p.b_patt = NULL;
	p.transform = create_identity_matrix(4);
	p.width = width * 0;
	p.height = height * 0;
	p.frequency = 0.0;
	return (p);
}

t_patt	uv_checkers_patt(t_colour a, t_colour b, int width, int height)
{
	t_patt	p;

	p.type = PATTERN_UV_CHECKERS;
	p.a = a;
	p.b = b;
	p.a_patt = NULL;
	p.b_patt = NULL;
	p.transform = create_identity_matrix(4);
	p.width = width;
	p.height = height;
	p.frequency = 0.0;
	return (p);
}
