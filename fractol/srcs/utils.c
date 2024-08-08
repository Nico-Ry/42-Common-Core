/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:39:13 by nryser            #+#    #+#             */
/*   Updated: 2024/08/07 21:24:43 by nryser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

void	ft_strlower(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void	print(char *str, int fd)
{
	ft_putstr_fd(str, fd);
}

void	show_help(void)
{
	print("\n", 1);
	print(" +------------------------ MANUAL -------------------------+\n", 1);
	print(" |                                                         |\n", 1);
	print(" | Usage: ./fractol [mandelbrot / julia / burning_ship ]   |\n", 1);
	print(" |                                                         |\n", 1);
	print(" |                                                         |\n", 1);
	print(" |                                                         |\n", 1);
	print(" | e.g: ./fractol mandelbrot                               |\n", 1);
	print(" |                                                         |\n", 1);
	print(" |----------------------- KEYBOARD ------------------------|\n", 1);
	print(" |                                                         |\n", 1);
	print(" | Press ESC to close the window                           |\n", 1);
	print(" | Press one of [1-3] to move to another fractal           |\n", 1);
	print(" | Press one of [Q-Y] keys to change the color of fractal  |\n", 1);
	print(" | Press one of [A-H] keys to change the color of fractal  |\n", 1);
	print(" | Use mouse scroll to zoom in and out of the fractal      |\n", 1);
	print(" | Press the arrow keys to change the viewpoint            |\n", 1);
	print(" | Press L to lock Julia's fractal                         |\n", 1);
	print(" | Press Zero to reset the fractal                         |\n", 1);
	print(" +---------------------------------------------------------+\n", 1);
	print("\n", 1);
	exit(EXIT_SUCCESS);
}
