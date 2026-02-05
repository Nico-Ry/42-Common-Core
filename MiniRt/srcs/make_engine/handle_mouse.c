/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:05:27 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 09:05:41 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../../includes/engine.h"

/**
 * @brief Handles mouse release events.
 *
 * If the left mouse button is released, stops dragging the image.
 *
 * @param button The mouse button released.
 * @param x X coordinate of the mouse at release (unused).
 * @param y Y coordinate of the mouse at release (unused).
 * @param engine The rendering engine structure.
 * @return Always returns 0.
 */
int	mouse_release(int button, int x, int y, t_engine *engine)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_CLK)
		engine->mouse_pressed = 0;
	return (0);
}

/**
 * @brief Applies a zoom transformation centered on the mouse position.
 *
 * Updates the zoom level and recalculates offsets so that the zoom
 * is centered around the given (x, y) point.
 *
 * @param engine The rendering engine containing the image and window.
 * @param x The x coordinate where zoom is centered.
 * @param y The y coordinate where zoom is centered.
 * @param zoom Structure containing zoom factor, limit and direction.
 */
void	apply_zoom(t_engine *engine, int x, int y, t_zoom_data zoom)
{
	float	new_zoom;

	new_zoom = engine->zoom * zoom.zoom_factor;
	if ((zoom.is_zoom_in == 1 && new_zoom > zoom.limit)
		|| (zoom.is_zoom_in == -1 && new_zoom < zoom.limit))
		return ;
	engine->zoom = new_zoom;
	engine->offset_x = (int)(zoom.zoom_factor * (engine->offset_x - x) + x);
	engine->offset_y = (int)(zoom.zoom_factor * (engine->offset_y - y) + y);
}

/**
 * @brief Handles mouse press events (left click or scroll).
 *
 * - Left click: starts dragging.
 * - Scroll up: zooms in centered on mouse position.
 * - Scroll down: zooms out centered on mouse position.
 *
 * @param button The button pressed.
 * @param x X coordinate of the mouse.
 * @param y Y coordinate of the mouse.
 * @param engine The rendering engine structure.
 * @return Always returns 0.
 */
int	mouse_press(int button, int x, int y, t_engine *engine)
{
	t_zoom_data	zoom;

	if (button == MOUSE_LEFT_CLK)
	{
		engine->mouse_pressed = 1;
		engine->last_mouse_x = x;
		engine->last_mouse_y = y;
	}
	else if (button == MOUSE_SCRL_UP)
	{
		zoom.zoom_factor = 1.1f;
		zoom.limit = 5.0f;
		zoom.is_zoom_in = 1;
		apply_zoom(engine, x, y, zoom);
	}
	else if (button == MOUSE_SCRL_DOWN)
	{
		zoom.zoom_factor = 1.0f / 1.1f;
		zoom.limit = 0.1f;
		zoom.is_zoom_in = -1;
		apply_zoom(engine, x, y, zoom);
	}
	redraw_image(engine);
	return (0);
}

/**
 * @brief Handles mouse movement events while dragging.
 *
 * Updates the offset of the image based on mouse movement
 * if dragging is currently active.
 *
 * @param x Current mouse x coordinate.
 * @param y Current mouse y coordinate.
 * @param engine The rendering engine structure.
 * @return Always returns 0.
 */
int	mouse_move(int x, int y, t_engine *engine)
{
	if (engine->mouse_pressed)
	{
		engine->offset_x += x - engine->last_mouse_x;
		engine->offset_y += y - engine->last_mouse_y;
		engine->last_mouse_x = x;
		engine->last_mouse_y = y;
		redraw_image(engine);
	}
	return (0);
}

/**
 * @brief Handles basic mouse events (scroll) separately.
 *
 * This fallback zooms without clamping via zoom_data structure.
 * (Mostly legacy, not main zoom method anymore.)
 *
 * @param button The button pressed.
 * @param x X coordinate of the mouse.
 * @param y Y coordinate of the mouse.
 * @param engine The rendering engine structure.
 * @return Always returns 0.
 */
int	mouse_hook(int button, int x, int y, t_engine *engine)
{
	float	zoom_factor;

	if (button == MOUSE_SCRL_UP)
	{
		zoom_factor = 1.1f;
		engine->zoom *= zoom_factor;
		engine->offset_x = (int)(zoom_factor * (engine->offset_x - x) + x);
		engine->offset_y = (int)(zoom_factor * (engine->offset_y - y) + y);
	}
	else if (button == MOUSE_SCRL_DOWN)
	{
		zoom_factor = 1.0f / 1.1f;
		engine->zoom *= zoom_factor;
		engine->offset_x = (int)(zoom_factor * (engine->offset_x - x) + x);
		engine->offset_y = (int)(zoom_factor * (engine->offset_y - y) + y);
	}
	if (engine->zoom > 5.0f)
		engine->zoom = 5.0f;
	if (engine->zoom < 0.2f)
		engine->zoom = 0.2f;
	redraw_image(engine);
	return (0);
}
