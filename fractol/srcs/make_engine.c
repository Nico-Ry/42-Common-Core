/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:39:09 by nryser            #+#    #+#             */
/*   Updated: 2024/08/08 15:46:25 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_engine.h"
#include "utils.h"
#include "mlx.h"

void	change_fractal(int key, t_engine *engine)
{
	reset_engine(engine, MANDELBROT);
	if (key == KEY_TWO)
		engine->fractal.type = JULIA;
	else if (key == KEY_THREE)
		engine->fractal.type = BURNING_SHIP;
}

void	set_fractal_type(t_engine *engine, char *str)
{
	if (!engine || !str)
		return ;
	ft_strlower(str);
	if (ft_strncmp(str, MANDELBROT_STR, ft_strlen(MANDELBROT_STR)+1) == 0)
		engine->fractal.type = MANDELBROT;
	else if (ft_strncmp(str, JULIA_STR, ft_strlen(JULIA_STR)+1) == 0)
		engine->fractal.type = JULIA;
	else if (ft_strncmp(str, BURNING_SHIP_STR,
			ft_strlen(BURNING_SHIP_STR)+1) == 0)
		engine->fractal.type = BURNING_SHIP;
	else
		show_help();
}

void	reset_engine(t_engine *engine, int fractal_type)
{
	engine->fractal.type = fractal_type;
	engine->fractal.zoom = WIN_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.is_julia_lock = false;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.iterations = MIN_ITERATIONS;
}

//Initializes the engine with command-line arguments.
void	init_engine(t_engine *engine, char *arg)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine || !arg)
		return ;
	reset_engine(engine, MANDELBROT);
	set_fractal_type(engine, arg);
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, \
												"Fractol project");
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->window || !engine->image.img_ptr)
	{
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		mlx_destroy_window(engine->mlx, engine->window);
		error_message("[MLX ERROR]: can't handle object creation!\n", 1);
	}
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr, \
								&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
}

/*
image.addr_ptr:
This is a pointer to the memory location where the image's
pixel data is stored. After creating an image with mlx_new_image, 
use mlx_get_data_addr to get this pointer.

(pixel_bits): Number of bits used to represent each
pixel (e.g., 32 bits for RGBA).
(line_len): Number of bytes used to store a single line of the image.
(Endian): Endianness of the image data, which determines the byte order
 (e.g., whether the least significant byte is stored first)
*/