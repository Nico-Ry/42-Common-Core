/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:11:00 by nryser            #+#    #+#             */
/*   Updated: 2025/04/26 06:11:46 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "engine.h"

/**
 * @brief Retrieves the number of available CPU cores.
 *
 * This function queries the operating system to determine how many
 * logical processors are available for multithreading.
 *
 * @return The number of CPU cores detected.
 */
int	get_cpu_count(void)
{
	return ((int)sysconf(_SC_NPROCESSORS_ONLN));
}

/**
 * @brief Determines an optimal block size based on the image height.
 *
 * This function returns a suitable block size for dynamic workload
 * distribution, balancing between fine-grained and coarse-grained
 * thread scheduling.
 *
 * @param image_height The vertical resolution of the rendered image.
 * @return The chosen block size (in number of rows).
 */
int	auto_block_size(int image_height)
{
	if (image_height <= 500)
		return (1);
	if (image_height <= 1000)
		return (2);
	return (4);
}

/**
 * @brief Initializes and starts all rendering threads.
 *
 * This function sets up the thread contexts and creates each thread,
 * assigning them the rendering workload through the render_section function.
 *
 * @param threads An array to store thread identifiers.
 * @param args An array of thread argument structures.
 * @param ctx A pointer to the render launch context containing shared data.
 */
void	create_threads(pthread_t *threads, t_render_thread *args,
	t_render_launch *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->thread_count)
	{
		args[i].cam = ctx->cam;
		args[i].world = ctx->world;
		args[i].image = ctx->img;
		args[i].progress = ctx->progress;
		pthread_create(&threads[i], NULL, render_section, &args[i]);
		i++;
	}
}

/**
* @brief Waits for all rendering threads to complete.
*
* This function calls pthread_join() on each rendering thread to ensure
* that the main thread does not proceed until all work is finished.
*
* @param threads An array containing the thread identifiers.
* @param thread_count The total number of threads launched.
*/
void	join_threads(pthread_t *threads, int thread_count)
{
	int	i;

	i = 0;
	while (i < thread_count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
