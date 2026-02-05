/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:44:35 by nryser            #+#    #+#             */
/*   Updated: 2025/05/07 15:44:35 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Attempts to acquire the next available block of rows to render.
 *
 * This function locks the progress mutex to safely update and fetch the
 * next starting and ending rows for rendering.
 *
 * @param ctx The thread context containing shared rendering progress.
 * @param y_start Pointer to store the starting y-coordinate.
 * @param y_end Pointer to store the ending y-coordinate.
 * @param block_size The number of rows to acquire at once.
 * @return 1 if a block was successfully acquired, 0 if rendering is complete.
 */
int	grab_next_block(t_render_thread *ctx, int *y_start,
					int *y_end, int block_size)
{
	pthread_mutex_lock(&ctx->progress->mutex);
	if (ctx->progress->current_y >= ctx->cam.vsize)
	{
		pthread_mutex_unlock(&ctx->progress->mutex);
		return (0);
	}
	*y_start = ctx->progress->current_y;
	*y_end = *y_start + block_size;
	ctx->progress->current_y += block_size;
	pthread_mutex_unlock(&ctx->progress->mutex);
	return (1);
}

/**
 * @brief Renders a single row of pixels in the image.
 *
 * For each pixel in the specified row, this function shoots a ray,
 * computes its color, and writes the result into the output image.
 * Also updates the rendering progress safely.
 *
 * @param ctx The thread context containing camera, world, and image pointers.
 * @param y The y-coordinate (row) to render.
 */
void	render_line(t_render_thread *ctx, int y)
{
	int			x;
	t_ray		*ray;
	t_colour	c;

	x = 0;
	while (x < ctx->cam.hsize)
	{
		ray = ray_for_pixel(ctx->cam, x, y);
		c = color_at(ctx->world, ray, false);
		put_pixel(ctx->image, x, y, convert_colour_to_int(c));
		free(ray);
		x++;
	}
	pthread_mutex_lock(&ctx->progress->mutex);
	ctx->progress->lines_rendered++;
	print_progress_bar(ctx->progress->lines_rendered,
		ctx->progress->total_lines);
	pthread_mutex_unlock(&ctx->progress->mutex);
}

/**
 * @brief Main thread worker function for rendering a section of the image.
 *
 * Each thread executes this function, dynamically acquiring blocks of rows
 * and rendering them until the entire image is completed.
 *
 * @param arg A pointer to a t_render_thread structure containing thread context.
 * @return NULL upon completion (required by pthreads).
 */
void	*render_section(void *arg)
{
	t_render_thread	*ctx;
	int				y_start;
	int				y_end;
	int				y;
	int				block_size;

	ctx = (t_render_thread *)arg;
	block_size = auto_block_size(ctx->cam.vsize);
	while (grab_next_block(ctx, &y_start, &y_end, block_size))
	{
		y = y_start;
		while (y < y_end && y < ctx->cam.vsize)
		{
			render_line(ctx, y);
			y++;
		}
	}
	return (NULL);
}
