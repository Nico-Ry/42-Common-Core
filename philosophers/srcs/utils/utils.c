/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:10:39 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:10:39 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

// /**
//  * @brief Checks if a character represents a numeric digit.
//  *
//  * @param c Character to check.
//  * @return 1 if the character is a digit, 0 otherwise.
//  */
int	ft_isdigit(int c)
{
	// Check if the character is between '0' and '9'.
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// /**
//  * @brief Gets the current time in milliseconds.
//  *
//  * This function retrieves the current time and converts it into milliseconds
//  * for use in the simulation.
//  *
//  * @return Current time in milliseconds.
//  */
long long	ft_get_time(void)
{
	struct timeval	time;

	// Get the current time.
	gettimeofday(&time, NULL);

	// Convert time from seconds and microseconds to milliseconds.
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// /**
//  * @brief Pauses execution for a specified amount of time.
//  *
//  * Uses a busy wait to simulate sleeping for a precise duration.
//  *
//  * @param time The duration to sleep in milliseconds.
//  */
void	ft_sleep(long long time)
{
	long long	start_time;

	// Record the start time.
	start_time = ft_get_time();

	// Loop until the specified time has passed.
	while (ft_get_time() - start_time < time)
		usleep(100); // Avoid excessive CPU usage with a short delay.
}

// /**
//  * @brief Cleans up and deallocates all allocated resources.
//  *
//  * Frees memory and destroys mutexes associated with the philosophers
//  * and health monitor.
//  *
//  * @param philosophers Array of philosopher structures.
//  * @param health_monitor Pointer to the health monitor structure.
//  */
void	clean_garbage(t_philo *philosophers, t_philo *health_monitor)
{
	int	i;

	i = 0;

	// Wait for all philosophers to finish their last actions.
	ft_sleep(philosophers->time_to_die + philosophers->time_to_eat
		+ philosophers->time_to_sleep + 100);

	// Destroy each philosopher's mutexes.
	while (i < philosophers->num_philosophers)
	{
		pthread_mutex_destroy(&philosophers[i].fork_mutex[i]);
		pthread_mutex_destroy(philosophers[i].protection_mutex);
		i++;
	}

	// Destroy the health monitor's protection mutex.
	pthread_mutex_destroy(health_monitor->protection_mutex);

	// Free all dynamically allocated resources.
	free(philosophers->fork_mutex);
	free(philosophers->meals_eaten);
	free(philosophers->last_meal_time);
	free(philosophers->protection_mutex);
	free(philosophers);
	philosophers = NULL;

	// Free health monitor.
	free(health_monitor);
}
