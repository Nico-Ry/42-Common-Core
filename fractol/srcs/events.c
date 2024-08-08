/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:39:01 by nryser            #+#    #+#             */
/*   Updated: 2024/08/07 21:22:34 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "render.h"
#include "make_engine.h"
#include "mlx.h"

int	on_destroy_event(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}

int	on_mouse_hook_event(int key, int x, int y, t_engine *engine)
{
	t_fractal	*fr;

	fr = &engine->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
		if (fr->iterations < MAX_ITERATIONS)
			++fr->iterations;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
		if (fr->iterations > MIN_ITERATIONS)
			--fr->iterations;
	}
	draw_fractal(engine);
	return (0);
}
/* ^= 1 toggle the lock L.The XOR operation (exclusive OR)
outputs 1 only when the inputs differ.
In the context of a boolean value, XOR with 1 effectively toggles the value */

int	on_key_hook_event(int key, t_engine *engine)
{
	if ((key >= KEY_Q && key <= KEY_Y) || (key >= KEY_A && key <= KEY_H))
		change_color(key, engine);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		change_view(key, engine);
	else if (key >= KEY_ONE && key <= KEY_THREE)
		change_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == JULIA)
		engine->fractal.is_julia_lock ^= 1;
	else if (key == KEY_ZERO)
		reset_engine(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		on_destroy_event(engine);
	draw_fractal(engine);
	return (0);
}

// Handles with update the mouse move events for Julia fractal

int	on_mousemove_event(int x, int y, t_engine *engine)
{
	if (!(engine->fractal.type == JULIA) || engine->fractal.is_julia_lock)
		return (0);
	engine->fractal.mouse_x = x;
	engine->fractal.mouse_y = y;
	draw_fractal(engine);
	return (0);
}
