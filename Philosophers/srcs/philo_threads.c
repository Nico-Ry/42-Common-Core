/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:17:30 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 16:17:36 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

/**
 * @brief Simulates the lifecycle of a philosopher.
 *
 * The function handles the philosopher's repeated cycle of thinking,
 * eating, and sleeping. It ensures synchronization for fork usage.
 *
 * @param philo Pointer to the philosopher's data structure.
 * @return NULL upon completion of the lifecycle.
 */
void	*philo_lifecycle(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 == 0)
		ft_sleep(10);
	while (1)
	{
		get_fork(philosopher);
		start_eating(philosopher);
		release_forks(philosopher);
		start_sleeping(philosopher);
		start_thinking(philosopher);
	}
}

/**
 * @brief Creates and manages threads for all philosophers.
 *
 * The function initializes and starts threads for each philosopher, ensuring
 * proper execution of their lifecycle.
 *
 * @param philosophers Pointer to the array of philosophers.
 */
void	start_philosopher_threads(t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers->num_philosophers)
	{
		philosophers[i].start_time = ft_get_time();
		pthread_create(&philosophers[i].philo_thread, NULL,
			philo_lifecycle, &philosophers[i]);
		i++;
	}
	while (i < philosophers->num_philosophers)
	{
		pthread_join(philosophers[i].philo_thread, NULL);
		i++;
	}
}
