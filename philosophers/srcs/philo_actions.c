/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:11:16 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:11:16 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

// /**
//  * @brief Locks the required forks for the philosopher to eat.
//  *
//  * The function uses mutexes to ensure that only one philosopher can use a fork
//  * at a time. Each philosopher needs two forks to eat.
//  *
//  * @param philosopher Pointer to the philosopher's data structure.
//  */
void	get_fork(t_philo *philosopher)
{
	// Lock the philosopher's right fork (based on their ID).
	pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 1]);

	// Lock the left fork. The first philosopher locks the last fork.
	if (philosopher->id == 1)
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher->num_philosophers - 1]);
	else
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 2]);

	// Log the action of taking a fork.
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "has taken a fork");
	pthread_mutex_unlock(philosopher->protection_mutex);
}

// /**
//  * @brief Updates the philosopher's state to eating and manages meal tracking.
//  *
//  * Locks the protection mutex to safely update shared data, logs the action, and
//  * puts the thread to sleep for the eating duration.
//  *
//  * @param philosopher Pointer to the philosopher's data structure.
//  */
void	start_eating(t_philo *philosopher)
{
	// Log the eating action and update the philosopher's state.
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is eating");

	// Update the last meal time and increment the meal count.
	philosopher->last_meal_time[philosopher->id - 1] = ft_get_time();
	philosopher->meals_eaten[philosopher->id - 1]++;
	pthread_mutex_unlock(philosopher->protection_mutex);

	// Simulate eating by putting the thread to sleep.
	ft_sleep(philosopher->time_to_eat);
}

// /**
//  * @brief Releases the forks after eating.
//  *
//  * Unlocks the mutexes for the left and right forks.
//  *
//  * @param philosopher Pointer to the philosopher's data structure.
//  */
void	release_forks(t_philo *philosopher)
{
	// Unlock the right fork.
	pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 1]);

	// Unlock the left fork. The first philosopher unlocks the last fork.
	if (philosopher->id == 1)
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->num_philosophers - 1]);
	else
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 2]);
}
