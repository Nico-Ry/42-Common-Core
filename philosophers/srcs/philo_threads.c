/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:13:44 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:13:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

// /**
//  * @brief Executes the lifecycle of a philosopher.
//  *
//  * Each philosopher alternates between taking forks, eating, sleeping, and
//  * thinking in a loop. The thread continues until the simulation ends.
//  *
//  * @param philo Pointer to the philosopher's data structure.
//  * @return NULL when the thread terminates.
//  */
void	*philo_lifecycle(void *philo)
{
	t_philo	*philosopher;

	// Cast the input pointer to the philosopher structure.
	philosopher = (t_philo *)philo;

	// Introduce a small delay for even-numbered philosophers to prevent contention.
	if (philosopher->id % 2 == 0)
		ft_sleep(10);

	// Infinite loop for the philosopher's actions until the simulation ends.
	while (1)
	{
		// Philosopher takes forks and eats.
		get_fork(philosopher);
		start_eating(philosopher);

		// Philosopher releases forks and starts sleeping.
		release_forks(philosopher);
		start_sleeping(philosopher);

		// Philosopher starts thinking.
		start_thinking(philosopher);
	}
}

// /**
//  * @brief Starts threads for all philosophers in the simulation.
//  *
//  * Creates and detaches a thread for each philosopher, which executes their
//  * lifecycle function.
//  *
//  * @param philosophers Array of philosopher structures.
//  */
void	start_philosopher_threads(t_philo *philosophers)
{
	int	i;

	i = 0;
	// Create and detach a thread for each philosopher.
	while (i < philosophers->num_philosophers)
	{
		// Record the start time for each philosopher.
		philosophers[i].start_time = ft_get_time();

		// Create the thread for the philosopher's lifecycle.
		// Check for thread creation success.
		if (pthread_create(&philosophers[i].philo_thread, NULL,
			philo_lifecycle, &philosophers[i]) != 0)
		{
			ft_putstr_fd("Error: Failed to create philosopher thread\n", 2);
			exit(1); // Terminate simulation on error.
		}
		// Detach the thread to allow independent execution.
		pthread_detach(philosophers[i].philo_thread);
		i++;
	}
}
