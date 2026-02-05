/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:05:59 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 09:05:59 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Moves the image by adjusting the offset based on key input.
 *
 * Arrow keys move the image by a fixed number of pixels horizontally
 * or vertically.
 *
 * @param engine The rendering engine containing the current offset.
 * @param keycode The key pressed (arrow keys).
 */
static void	move_image(t_engine *engine, int keycode)
{
	if (keycode == KEY_LEFT)
		engine->offset_x -= 20;
	else if (keycode == KEY_RIGHT)
		engine->offset_x += 20;
	else if (keycode == KEY_UP)
		engine->offset_y -= 20;
	else if (keycode == KEY_DOWN)
		engine->offset_y += 20;
}

/**
 * @brief Applies zoom in or zoom out based on key input.
 *
 * Zooms in (+ key) or zooms out (- key) centered on the middle
 * of the window. Zoom limits are enforced to avoid extreme values.
 *
 * @param engine The rendering engine containing zoom information.
 * @param keycode The key pressed (+, -, or keypad equivalents).
 */
static void	zoom_image(t_engine *engine, int keycode)
{
	t_zoom_data	zoom;

	if (keycode == KEY_PLUS || keycode == KEY_KP_PLUS)
	{
		zoom.zoom_factor = 1.1f;
		zoom.limit = 5.0f;
		zoom.is_zoom_in = 1;
		apply_zoom(engine, WIN_SIZE / 2, WIN_SIZE / 2, zoom);
	}
	else if (keycode == KEY_MINUS || keycode == KEY_KP_MINUS)
	{
		zoom.zoom_factor = 1.0f / 1.1f;
		zoom.limit = 0.2f;
		zoom.is_zoom_in = -1;
		apply_zoom(engine, WIN_SIZE / 2, WIN_SIZE / 2, zoom);
	}
}

/**
 * @brief Resets the view to default zoom and center position.
 *
 * Sets the zoom back to 1.0 and recenters the image by
 * resetting the offset values.
 *
 * @param engine The rendering engine to reset.
 */
static void	reset_view(t_engine *engine)
{
	engine->offset_x = 0;
	engine->offset_y = 0;
	engine->zoom = 1.0f;
}

/**
 * @brief Main key event handler.
 *
 * Handles key events:
 * - ESC exits the application
 * - Arrow keys move the image
 * - + / - zooms in or out
 * - R resets the view to default
 *
 * Triggers a redraw after any action.
 *
 * @param keycode The key pressed.
 * @param engine The rendering engine.
 * @return Always returns 0.
 */
int	key_hook(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(engine->mlx);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_UP || keycode == KEY_DOWN)
		move_image(engine, keycode);
	else if (keycode == KEY_PLUS || keycode == KEY_KP_PLUS
		|| keycode == KEY_MINUS || keycode == KEY_KP_MINUS)
		zoom_image(engine, keycode);
	else if (keycode == KEY_R)
		reset_view(engine);
	redraw_image(engine);
	return (0);
}
