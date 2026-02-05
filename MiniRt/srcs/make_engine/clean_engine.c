/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:26:52 by nryser            #+#    #+#             */
/*   Updated: 2025/04/29 20:29:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../../includes/engine.h"

void	error_message(t_engine *engine, char *text, int mode)
{
	if (engine)
		cleanup(engine);
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

int	on_destroy_event(t_engine *engine)
{
	cleanup(engine);
	exit(EXIT_SUCCESS);
}

void	cleanup(t_engine *engine)
{
	if (engine->image.img_ptr)
	{
		printf("Destroying image\n");
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		engine->image.img_ptr = NULL;
	}
	if (engine->window)
	{
		printf("Destroying window\n");
		mlx_destroy_window(engine->mlx, engine->window);
		engine->window = NULL;
	}
	if (engine->mlx)
	{
		printf("Destroying MLX display\n");
		mlx_destroy_display(engine->mlx);
		free(engine->mlx);
		engine->mlx = NULL;
	}
}
