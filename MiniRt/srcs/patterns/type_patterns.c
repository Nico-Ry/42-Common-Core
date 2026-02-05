/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:42:04 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 13:42:19 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Creates a stripe pattern alternating between two colors.
 *
 * @param a The first color of the stripe pattern.
 * @param b The second color of the stripe pattern.
 * @return A t_pattern struct with type STRIPE and identity transform.
 *
 * The frequency field is initialized to 10.0 and determines how many
 * stripes appear per unit distance along the x-axis.
 */
t_patt	stripe_patt(t_colour a, t_colour b)
{
	t_patt	p;

	p.type = PATTERN_STRIPE;
	p.a = a;
	p.b = b;
	p.a_patt = NULL;
	p.b_patt = NULL;
	p.transform = create_identity_matrix(4);
	p.frequency = 10.0;
	return (p);
}

t_patt	gradient_patt(t_colour a, t_colour b)
{
	t_patt	p;

	p.type = PATTERN_GRADIENT;
	p.a = a;
	p.b = b;
	p.a_patt = NULL;
	p.b_patt = NULL;
	p.transform = create_identity_matrix(4);
	p.frequency = 4.0;
	return (p);
}

t_patt	ring_patt(t_colour a, t_colour b)
{
	t_patt	p;

	p.type = PATTERN_RING;
	p.a = a;
	p.b = b;
	p.a_patt = NULL;
	p.b_patt = NULL;
	p.transform = create_identity_matrix(4);
	p.frequency = 12.0;
	return (p);
}

t_patt	checkers_patt(t_colour a, t_colour b)
{
	t_patt	p;

	p.type = PATTERN_CHECKERS;
	p.a = a;
	p.b = b;
	p.a_patt = NULL;
	p.b_patt = NULL;
	p.transform = create_identity_matrix(4);
	p.frequency = 1.0;
	return (p);
}
