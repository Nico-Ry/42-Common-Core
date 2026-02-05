/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:49:58 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:49:58 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIN_SIZE && y >= 0 && y < WIN_SIZE)
	{
		pixel = img->addr_ptr + (y * img->line_len + x * (img->pixel_bits / 8));
		*(unsigned int *)pixel = color;
	}
}

void	ft_swap(t_hit **a, t_hit **b)
{
	t_hit	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_progress_bar(int y, int total)
{
	int		percent;
	int		filled;
	int		i;

	percent = (y * 100) / total;
	filled = (percent * 50) / 100;
	i = 0;
	printf("\r[");
	while (i < filled)
	{
		printf("\033[32m=\033[0m");
		i++;
	}
	while (i < 50)
	{
		printf(" ");
		i++;
	}
	printf("] %3d%% (%d/%d)", percent, y, total);
	if (y == total)
		printf("\n");
}
