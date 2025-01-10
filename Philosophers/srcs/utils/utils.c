/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:21:49 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 16:22:01 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/**
 * @brief Causes the current thread to sleep for a given duration.
 *
 * Implements a precise sleep function that suspends execution for
 * the specified number of milliseconds.
 *
 * @param time The duration of the sleep in milliseconds.
 */
long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 * @brief Causes the current thread to sleep for a given duration.
 *
 * Implements a precise sleep function that suspends execution for
 * the specified number of milliseconds.
 *
 * @param time The duration of the sleep in milliseconds.
 */
void	ft_sleep(long long time)
{
	long long	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time < time)
		usleep(100);
}

/**
 * @brief Frees all allocated resources in the simulation.
 *
 * Deallocates memory for philosophers, forks, and other dynamically
 * allocated structures. Destroys all mutexes used in the simulation.
 *
 * @param philosophers Pointer to the array of philosopher structures.
 * @param health_monitor Pointer to the shared health monitor structure.
 */
void	clean_garbage(t_philo *philosophers, t_philo *health_monitor)
{
	int	i;

	i = 0;
	ft_sleep(philosophers->time_to_die + philosophers->time_to_eat
		+ philosophers->time_to_sleep + 100);
	while (i < philosophers->num_philosophers)
	{
		pthread_mutex_destroy(&philosophers[i].fork_mutex[i]);
		i++;
	}
	if (health_monitor->protection_mutex != NULL)
	{
		pthread_mutex_destroy(health_monitor->protection_mutex);
		free(health_monitor->protection_mutex);
		health_monitor->protection_mutex = NULL;
	}
	free(philosophers->fork_mutex);
	free(philosophers->last_meal_time);
	free(philosophers->meals_eaten);
	free(philosophers);
	free(health_monitor);
}

/*
printf("Destroying fork_mutex[%d]: %p\n", i,
(void *)&philosophers->fork_mutex[i]);
printf("Freeing health_monitor->protection_mutex: %p\n",
(void *)health_monitor->protection_mutex);
printf("Freeing fork_mutex array: %p\n", (void *)philosophers->fork_mutex);
printf("Freeing last_meal_time: %p\n", (void *)philosophers->last_meal_time);
printf("Freeing meals_eaten: %p\n", (void *)philosophers->meals_eaten);
printf("Freeing philosophers array: %p\n", (void *)philosophers);
printf("Freeing health_monitor: %p\n", (void *)health_monitor);
*/
