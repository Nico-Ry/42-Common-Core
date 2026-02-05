/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:01:35 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 09:03:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../../includes/engine.h"

/**
 * @brief Draws the filled part of the zoom bar.
 *
 * Fills the bottom area of the window with a colored bar
 * representing the current zoom level.
 *
 * @param engine The rendering engine containing the MLX context.
 * @param bar_width Width of the filled bar based on zoom.
 * @param bar_height Height of the zoom bar.
 * @param color The color to fill the zoom bar with.
 */
static void	draw_bar_fill(t_engine *engine, int bar_width, int bar_h, int color)
{
	int	x;
	int	y;

	y = WIN_SIZE - bar_h;
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < bar_width)
		{
			mlx_pixel_put(engine->mlx, engine->window, x, y, color);
			x++;
		}
		y++;
	}
}

/**
 * @brief Draws the border around the zoom bar.
 *
 * Adds a simple black rectangle border around the zoom bar
 * to separate it visually from the rest of the window.
 *
 * @param engine The rendering engine containing the MLX context.
 * @param bar_height Height of the zoom bar.
 */
static void	draw_bar_border(t_engine *engine, int bar_h)
{
	int	x;
	int	y;

	y = WIN_SIZE - bar_h;
	while (y < WIN_SIZE)
	{
		mlx_pixel_put(engine->mlx, engine->window, 0, y, BLACK);
		mlx_pixel_put(engine->mlx, engine->window, WIN_SIZE - 1, y, BLACK);
		y++;
	}
	x = 0;
	while (x < WIN_SIZE)
	{
		mlx_pixel_put(engine->mlx, engine->window, x, WIN_SIZE - bar_h, BLACK);
		mlx_pixel_put(engine->mlx, engine->window, x, WIN_SIZE - 1, BLACK);
		x++;
	}
}

/**
 * @brief Draws the current zoom percentage as text above the zoom bar.
 *
 * Converts the current zoom factor to a percentage string
 * and displays it at the bottom-left of the window.
 *
 * @param engine The rendering engine containing the MLX context.
 * @param bar_height Height of the zoom bar.
 */
static void	draw_zoom_text(t_engine *engine, int bar_height)
{
	char	*zoom_str;
	char	final_str[32];
	int		zoom_percent;

	zoom_percent = (int)(engine->zoom * 100.0f);
	zoom_str = ft_itoa(zoom_percent);
	if (!zoom_str)
		return ;
	ft_strcpy(final_str, "Zoom: ");
	ft_strlcat(final_str, zoom_str, sizeof(final_str));
	ft_strlcat(final_str, "%", sizeof(final_str));
	mlx_string_put(engine->mlx, engine->window, 10, WIN_SIZE - bar_height
		- 15, WHITE, final_str);
	free(zoom_str);
}

/**
 * @brief Draws the full zoom bar UI element.
 *
 * Calculates the current zoom normalized to a scale,
 * draws the colored zoom bar fill, adds a border around it,
 * and writes the current zoom percentage above the bar.
 *
 * @param engine The rendering engine containing the MLX context and zoom value.
 */
void	draw_zoom_bar(t_engine *engine)
{
	int		bar_width;
	int		bar_height;
	float	zoom_normalized;
	int		color;

	bar_height = 10;
	color = GREEN;
	if (engine->zoom > 5.0f)
		zoom_normalized = 5.0f;
	else if (engine->zoom < 0.2f)
		zoom_normalized = 0.2f;
	else
		zoom_normalized = engine->zoom;
	if (zoom_normalized > 3.0f)
		color = RED;
	bar_width = (int)(WIN_SIZE * (zoom_normalized / 5.0f));
	draw_bar_fill(engine, bar_width, bar_height, color);
	draw_bar_border(engine, bar_height);
	draw_zoom_text(engine, bar_height);
}
