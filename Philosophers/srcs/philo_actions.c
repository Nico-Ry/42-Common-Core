/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:16:54 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 16:17:11 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

/**
 * @brief Locks the required forks for the philosopher to eat.
 *
 * Uses mutexes to ensure that only one philosopher can use a fork at a time.
 * The philosopher must acquire two forks to begin eating.
 *
 * @param philosopher Pointer to the philosopher's data structure.
 */
void	get_fork(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 1]);
	if (philosopher->id == 1)
		pthread_mutex_lock(&philosopher
			->fork_mutex[philosopher->num_philosophers - 1]);
	else
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 2]);
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "has taken a fork");
	pthread_mutex_unlock(philosopher->protection_mutex);
}

/**
 * @brief Initiates the eating process for a philosopher.
 *
 * Updates the philosopher's last meal time and tracks the number of meals
 * eaten. The function also ensures proper synchronization.
 *
 * @param philosopher Pointer to the philosopher's data structure.
 */
void	start_eating(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is eating");
	philosopher->last_meal_time[philosopher->id - 1] = ft_get_time();
	philosopher->meals_eaten[philosopher->id - 1]++;
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_eat);
}

/**
 * @brief Releases the forks held by a philosopher.
 *
 * Unlocks the mutexes for the philosopher's left and right forks,
 * making them available for others.
 *
 * @param philosopher Pointer to the philosopher's data structure.
 */
void	release_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 1]);
	if (philosopher->id == 1)
		pthread_mutex_unlock(&philosopher
			->fork_mutex[philosopher->num_philosophers - 1]);
	else
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 2]);
}
