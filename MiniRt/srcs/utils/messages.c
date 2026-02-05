/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:23:03 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:24:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

void	help_text(t_engine *engine, int *y, char *text)
{
	mlx_string_put(engine->mlx, engine->window, 20, *y, 0xFFFFFF, text);
	*y += 30;
}

void	display_help_message(t_engine *engine)
{
	int	y;

	y = 20;
	help_text(engine, &y, "MiniRT - Usage Guide");
	y += 10;
	help_text(engine, &y, "Usage: ./miniRT <scene.rt>");
	help_text(engine, &y, "Example: ./miniRT scene.rt");
	y += 20;
	help_text(engine, &y, "Ambient Light: A <ratio> <R,G,B>");
	help_text(engine, &y, "Camera: C <x,y,z> <dir_x,dir_y,dir_z> <FOV>");
	help_text(engine, &y, "Light: L <x,y,z> <brightness> <R,G,B>");
	help_text(engine, &y, "Sph: sp <x,y,z> <diameter> <R,G,B>");
	help_text(engine, &y, "Pl: pl <x,y,z> <norm_x,norm_y,norm_z> <R,G,B>");
	help_text(engine, &y, "Cyl: cy < x, y, z> < x, y, z> <diam> <h> <R,G,B>");
	y += 20;
	help_text(engine, &y, "Press ESC to close the window.");
}

void	malloc_err(char *func_name)
{
	printf(R_B"Error:"RES" [%s] -> failed to allocate memory\n", func_name);
	exit(1);
}

void	print_tuple(t_tuple tuple, char *name)
{
	if (is_vector(tuple))
		printf(G_B"tuple `"YEL"%s"G_B"` is VECTOR:\n"RES, name);
	else if (is_point(tuple))
		printf(G_B"tuple `"YEL"%s"G_B"` is POINT:\n"RES, name);
	else
		printf(R_B"ERROR:"RES" tuple type undefined\n");
	printf(YEL"\tx:"RES" %.5f\n", tuple.x);
	printf(YEL"\ty:"RES" %.5f\n", tuple.y);
	printf(YEL"\tz:"RES" %.5f\n", tuple.z);
	printf(YEL"\tw:"RES" %d\n", tuple.w);
}
