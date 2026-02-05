/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:10:48 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:10:48 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * Converts a t_colour (with float RGB values in range [0.0, 1.0])
 * into a 24-bit packed integer in 0xRRGGBB format.
 *
 * Steps:
 * 1. Each component (r, g, b) is
 *  multiplied by 255 to scale from [0,0–1,0] to [0–255].
 * 2. Values are clamped to stay within 0–255.
 * 3. Components are shifted into their proper byte positions:
 *      - Red   << 16 (high byte)
 *      - Green << 8  (middle byte)
 *      - Blue       (low byte)
 * 4. The final integer is returned as: 0xRRGGBB.
 * Example:
 * colour(1.0, 0.5, 0.25) → (255, 128, 64)
 * → (255 << 16 | 128 << 8 | 64) = 0xFF8040 = 16744448
 * because:   16711680  // red
 *          +    32768 // green
 *          +       64 // blue
 *           ---------
 *          = 16744448
 */
int	convert_colour_to_int(t_colour col)
{
	int	r;
	int	g;
	int	b;

	r = fmin(fmax(col.r * 255, 0), 255);
	g = fmin(fmax(col.g * 255, 0), 255);
	b = fmin(fmax(col.b * 255, 0), 255);
	return (r << 16 | g << 8 | b);
}

t_colour	clamp_colour(t_colour c)
{
	t_colour	clamped;

	clamped.r = fmin(fmax(c.r, 0.0), 1.0);
	clamped.g = fmin(fmax(c.g, 0.0), 1.0);
	clamped.b = fmin(fmax(c.b, 0.0), 1.0);
	return (clamped);
}
