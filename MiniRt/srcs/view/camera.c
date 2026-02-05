/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:35:54 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 19:39:21 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"
#include "tests.h"

t_camera	ft_camera(double hsize, double vsize, double fov_degrees)
{
	t_camera	camera;
	double		half_view;
	double		aspect;
	double		fov_radians;

	camera.hsize = hsize;
	camera.vsize = vsize;
	fov_radians = fov_degrees * M_PI / 180;
	camera.fov = fov_radians;
	camera.transf = create_identity_matrix(4);
	half_view = tan(fov_radians / 2);
	aspect = hsize / vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}
