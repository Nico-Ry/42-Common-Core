/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:39:06 by nryser            #+#    #+#             */
/*   Updated: 2024/08/07 20:04:33 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_engine.h"
#include "render.h"
#include "events.h"
#include "utils.h"

void	cleanup(t_engine *engine)
{
	if (engine->image.img_ptr)
	{
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		engine->image.img_ptr = NULL;
	}
	if (engine->window)
	{
		mlx_destroy_window(engine->mlx, engine->window);
		engine->window = NULL;
	}
}

//1L << 6 : PointerMotionMask (Mouse movement). this is a bitwise operation
//that shifts the number 1 to the left by 6 bits
int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc != 2)
		show_help();
	init_engine(&engine, argv[1]);
	draw_fractal(&engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_mouse_hook(engine.window, on_mouse_hook_event, &engine);
	mlx_hook(engine.window, 6, 1L << 6, on_mousemove_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
	cleanup(&engine);
	return (0);
}
