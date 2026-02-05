/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:49:06 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:49:06 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief calculates world_x or world_y for rfp_pixel
 */
static double	w_pt(t_camera cam, int p, char c)
{
	double	offset;

	offset = (p + 0.5) * cam.pixel_size;
	if (c == 'x')
		return (cam.half_width - offset);
	else if (c == 'y')
		return (cam.half_height - offset);
	printf(AKA"Error: w_pt() requires 'x' or 'y'\n"RES);
	return (0);
}

/**
 * @brief calculates the pixel position in world coordinates
 */
static t_tuple	rfp_pixel(t_camera cam, double world_x, double world_y)
{
	t_tuple		pixel;
	t_matrix	*pixel_mtx;
	t_matrix	*point;
	t_matrix	*inverse;

	inverse = invert_matrix(cam.transf);
	point = tuple_to_matrix(ft_tuple(world_x, world_y, -1, POINT));
	pixel_mtx = multiply_matrices(inverse, point);
	pixel = matrix_to_tuple(pixel_mtx);
	pixel.w = POINT;
	free_matrix(pixel_mtx);
	free_matrix(point);
	free_matrix(inverse);
	return (pixel);
}

/**
 * @brief calculates the origin of the ray for ray_for_pixel
 */
static t_tuple	rfp_origin(t_matrix *transf)
{
	t_matrix	*point;
	t_matrix	*inverse;
	t_matrix	*temp;
	t_tuple		res;

	point = tuple_to_matrix(ft_tuple(0, 0, 0, POINT));
	inverse = invert_matrix(transf);
	temp = multiply_matrices(inverse, point);
	res = matrix_to_tuple(temp);
	res.w = POINT;
	free_matrix(point);
	free_matrix(inverse);
	free_matrix(temp);
	return (res);
}

/**
 * @brief calculates the ray that passes through a given pixel
 */
t_ray	*ray_for_pixel(t_camera cam, int px, int py)
{
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	pixel = rfp_pixel(cam, w_pt(cam, px, 'x'), w_pt(cam, py, 'y'));
	origin = rfp_origin(cam.transf);
	direction = normalize(diff_tuple(pixel, origin));
	return (ft_ray(origin, direction));
}
