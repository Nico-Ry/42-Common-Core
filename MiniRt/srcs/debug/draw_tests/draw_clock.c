/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:27:38 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 16:27:38 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

// #define CLOCK_RADIUS (WIN_SIZE / 4)
// #define CENTER_X (WIN_SIZE / 2)
// #define CENTER_Y (WIN_SIZE / 2)
// #define HOUR_COUNT 12
// #define ROTATION_STEP (M_PI / 6)

// //function for debug * comment it out after//
// void	draw_marker(t_image *img, int x, int y, int color, int marker_size)
// {
// 	int	i;
// 	int	j;

// 	i = -marker_size / 2;
// 	while (i <= marker_size / 2)
// 	{
// 		j = -marker_size / 2;
// 		while (j <= marker_size / 2)
// 		{
// 			put_pixel(img, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	compute_hour_position(int hour, t_tuple *transformed)
// {
// 	t_matrix	*rotation;
// 	t_matrix	*hour_matrix;
// 	t_matrix	*result_matrix;
// 	t_tuple		hour_pos;

// 	hour_pos = ft_tuple(0, 0, 1, POINT);
// 	hour_matrix = tuple_to_matrix(hour_pos);
// 	rotation = rotate_y(hour * ROTATION_STEP);
// 	result_matrix = multiply_matrices(rotation, hour_matrix);
// 	*transformed = matrix_to_tuple(result_matrix);
// 	free_matrix(rotation);
// 	free_matrix(result_matrix);
// 	free_matrix(hour_matrix);
// }

// static void	draw_clock_loop(t_image *img)
// {
// 	t_tuple	transformed;
// 	int		hour;
// 	int		screen_x;
// 	int		screen_y;

// 	hour = 0;
// 	while (hour < HOUR_COUNT)
// 	{
// 		compute_hour_position(hour, &transformed);
// 		screen_x = CENTER_X + (int)(transformed.x * CLOCK_RADIUS);
// 		screen_y = CENTER_Y - (int)(transformed.z * CLOCK_RADIUS);
// 		draw_marker(img, screen_x, screen_y, COLOR_X, MARKER_SIZE);
// 		hour++;
// 	}
// }

// void	draw_clock_scene(t_engine *engine)
// {
// 	draw_clock_loop(&engine->image);
// }

// int	draw_hour_markers(int run)
// {
// 	if (run == 0)
// 		return (0);
// 	return (1);
// }
