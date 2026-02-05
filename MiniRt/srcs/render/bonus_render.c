/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:30:07 by nryser            #+#    #+#             */
/*   Updated: 2025/04/28 18:30:07 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Renders the entire scene using multithreading.
 *
 * This function initializes the rendering context, dynamically determines
 * the number of threads to use, distributes the workload, and collects
 * the results into the final image.
 *
 * @param cam The camera from which rays are cast.
 * @param world The scene containing objects and lights.
 * @param img The image buffer to write the final render into.
 * @return A pointer to the completed image buffer.
 */
t_image	*render(t_camera cam, t_world *world, t_image *img)
{
	pthread_t		threads[64];
	t_render_thread	args[64];
	t_progress		progress;
	t_render_launch	ctx;
	int				thread_count;

	thread_count = get_cpu_count();
	if (thread_count > 64)
		thread_count = 64;
	progress.lines_rendered = 0;
	progress.current_y = 0;
	progress.total_lines = cam.vsize;
	pthread_mutex_init(&progress.mutex, NULL);
	ctx.cam = cam;
	ctx.world = world;
	ctx.img = img;
	ctx.progress = &progress;
	ctx.thread_count = thread_count;
	create_threads(threads, args, &ctx);
	join_threads(threads, thread_count);
	pthread_mutex_destroy(&progress.mutex);
	return (img);
}
