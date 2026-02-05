/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:03:39 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 09:05:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

// File: srcs/make_engine/handle_keys.c

#include "minirt.h"
#include "../../includes/engine.h"

/**
 * @brief Copies a single pixel from the source image to the destination image,
 * adjusting for zoom level.
 *
 * Converts a pixel coordinate based on the zoom level and
 * assigns the corresponding color in the new zoomed image.
 *
 * @param engine The rendering engine containing the source image.
 * @param p The pixel coordinate in the destination image.
 * @param info Metadata containing zoom factor and destination image information.
 */
void	copy_pixel(t_engine *engine, t_point p, t_scale_info info)
{
	int				orig_x;
	int				orig_y;
	unsigned int	color;
	char			*src_pixel;
	char			*dst_pixel;

	orig_x = (int)(p.x / info.zoom);
	orig_y = (int)(p.y / info.zoom);
	src_pixel = engine->image.addr_ptr
		+ (orig_y * engine->image.line_len + orig_x
			* (engine->image.pixel_bits / 8));
	color = *(unsigned int *)src_pixel;
	dst_pixel = info.dst_addr + (p.y * info.dst_line_len
			+ p.x * (info.dst_bits / 8));
	*(unsigned int *)dst_pixel = color;
}

/**
 * @brief Scales the original image to a new zoomed size.
 *
 * For each pixel in the destination image, computes which pixel
 * in the original image corresponds to it and copies its color.
 *
 * @param engine The rendering engine containing the original image.
 * @param zoomed_img Pointer to the newly created zoomed image.
 * @param zoom Zoom factor to apply.
 */
void	scale_image(t_engine *engine, void *zoomed_img, float zoom)
{
	t_point			p;
	t_scale_info	info;
	int				dst_endian;

	info.dst_addr = mlx_get_data_addr(zoomed_img,
			&info.dst_bits, &info.dst_line_len, &dst_endian);
	info.zoom = zoom;
	p.y = 0;
	while (p.y < (int)(WIN_SIZE * zoom))
	{
		p.x = 0;
		while (p.x < (int)(WIN_SIZE * zoom))
		{
			copy_pixel(engine, p, info);
			p.x++;
		}
		p.y++;
	}
}

/**
 * @brief Redraws the entire scene with the current zoom and offset applied.
 *
 * Recreates a new zoomed image, scales the scene appropriately,
 * clears the window, and places the image at the correct offset.
 * Also draws the zoom bar at the bottom.
 *
 * @param engine The rendering engine containing scene state.
 */
void	redraw_image(t_engine *engine)
{
	int		new_width;
	int		new_height;
	void	*zoomed_img;

	if (engine->zoom > 5.0f)
		engine->zoom = 5.0f;
	if (engine->zoom < 0.1f)
		engine->zoom = 0.1f;
	new_width = (int)(WIN_SIZE * engine->zoom);
	new_height = (int)(WIN_SIZE * engine->zoom);
	if (new_width <= 0 || new_height <= 0)
		return ;
	zoomed_img = mlx_new_image(engine->mlx, new_width, new_height);
	scale_image(engine, zoomed_img, engine->zoom);
	mlx_clear_window(engine->mlx, engine->window);
	mlx_put_image_to_window(engine->mlx, engine->window,
		zoomed_img, engine->offset_x, engine->offset_y);
	mlx_destroy_image(engine->mlx, zoomed_img);
	draw_zoom_bar(engine);
}

/**
 * @brief Sets up all necessary event hooks for the application.
 *
 * Connects keyboard, mouse click, mouse movement, and window close events
 * to their corresponding handler functions.
 *
 * @param engine The rendering engine containing the MLX window.
 */
void	setup_hooks(t_engine *engine)
{
	mlx_hook(engine->window, 2, 1L << 0, key_hook, engine);
	mlx_hook(engine->window, 4, 1L << 2, mouse_press, engine);
	mlx_hook(engine->window, 5, 1L << 3, mouse_release, engine);
	mlx_hook(engine->window, 6, 1L << 6, mouse_move, engine);
	mlx_hook(engine->window, 17, 0, on_destroy_event, engine);
}
