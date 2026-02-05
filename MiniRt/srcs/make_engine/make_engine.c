/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:30:50 by nryser            #+#    #+#             */
/*   Updated: 2025/04/29 20:30:58 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../../includes/engine.h"

/**
 * @brief Initializes the MLX context and creates the application window.
 *
 * Creates a new MLX instance and a new window with a fixed size
 * (WIN_SIZE × WIN_SIZE). If initialization fails, the program exits
 * with an error message.
 *
 * @param engine The rendering engine structure to initialize.
 */
static void	create_mlx_window(t_engine *engine)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message(engine, "[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx,
			WIN_SIZE, WIN_SIZE, "MiniRt project");
	if (!engine->window)
		error_message(engine, "[MLX ERROR]: can't create window!\n", 1);
}

/**
 * @brief Creates the image buffer for rendering and retrieves its metadata.
 *
 * Allocates a new image in MLX memory and retrieves a pointer to its pixel
 * data, along with details like pixel bits, line length, and endianess.
 *
 * @param engine The rendering engine structure containing image information.
 */
static void	create_image(t_engine *engine)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->image.img_ptr)
		error_message(engine, "[MLX ERROR]: can't create image!\n", 1);
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr,
			&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
}

/**
 * @brief Initializes the entire rendering engine.
 *
 * Sets up MLX context, window, image buffer, and initializes control values
 * like zoom level and offsets. Also attaches input event hooks.
 *
 * @param engine The rendering engine structure to initialize.
 */
void	init_engine(t_engine *engine)
{
	if (!engine)
		return ;
	create_mlx_window(engine);
	create_image(engine);
	engine->offset_x = 0;
	engine->offset_y = 0;
	engine->zoom = 1.0f;
	engine->last_mouse_x = 0;
	engine->last_mouse_y = 0;
	engine->mouse_pressed = 0;
	setup_hooks(engine);
}
