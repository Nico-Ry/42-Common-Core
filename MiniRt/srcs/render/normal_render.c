/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:46:39 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:47:25 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

t_image	*render(t_camera cam, t_world *world, t_image *img)
{
	int			x;
	int			y;
	t_ray		*ray;
	t_colour	col;

	y = 0;
	while (y < (int)cam.vsize)
	{
		print_progress_bar(y, WIN_SIZE - 1);
		x = 0;
		while (x < (int)cam.hsize)
		{
			ray = ray_for_pixel(cam, x, y);
			col = color_at(world, ray, false);
			put_pixel(img, x, y, convert_colour_to_int(col));
			free_ray(ray);
			x++;
		}
		y++;
	}
	return (img);
}
