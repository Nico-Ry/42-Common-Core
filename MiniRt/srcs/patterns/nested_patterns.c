/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested_patterns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:41:11 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:41:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_patt	*solid_patt(t_colour c)
{
	t_patt	*p;

	p = malloc(sizeof(t_patt));
	if (!p)
		return (NULL);
	p->type = PATTERN_STRIPE;
	p->a = c;
	p->b = c;
	p->a_patt = NULL;
	p->b_patt = NULL;
	p->transform = create_identity_matrix(4);
	p->frequency = 0;
	p->width = 0;
	p->height = 0;
	return (p);
}

t_patt	*make_diagonal_stripe(t_colour a, t_colour b, double angle)
{
	t_patt	*stripe;

	stripe = malloc(sizeof(t_patt));
	stripe->type = PATTERN_UV_STRIPE;
	stripe->a = a;
	stripe->b = b;
	stripe->width = 16;
	stripe->height = 1;
	stripe->a_patt = NULL;
	stripe->b_patt = NULL;
	stripe->transform = rotate_z(angle);
	return (stripe);
}

// t_patt	*make_diagonal_stripe(t_colour a, t_colour b, double angle)
// {
// 	t_patt	*stripe = malloc(sizeof(t_patt));
// 	stripe->type = patt_UV_STRIPE;
// 	stripe->a = a;
// 	stripe->b = b;
// 	stripe->width = 20;
// 	stripe->height = 1;
// 	stripe->transform = rotate_z(angle);
// 	return (stripe);
// }
