/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:11:00 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:11:00 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philosopher.h"

// /**
//  * @brief Initializes the health monitor for the philosophers.
//  *
//  * The health monitor tracks the state of all philosophers, ensuring that no
//  * philosopher dies of starvation.
//  *
//  * @param philosopher Pointer to the first philosopher's data structure.
//  * @return Pointer to the health monitor structure or NULL if initialization fails.
//  */
t_philo	*setup_health_monitor(t_philo *philosopher)
{
	t_philo	*monitor;

	// Allocate memory for the monitor structure.
	monitor = malloc(sizeof(t_philo));
	if (!monitor)
		return (NULL);

	// Copy relevant philosopher data to the monitor.
	monitor->id = 0;
	monitor->meals_eaten = philosopher->meals_eaten;
	monitor->time_to_die = philosopher->time_to_die;
	monitor->time_to_eat = philosopher->time_to_eat;
	monitor->time_to_sleep = philosopher->time_to_sleep;
	monitor->num_must_eat = philosopher->num_must_eat;
	monitor->last_meal_time = philosopher->last_meal_time;
	monitor->num_forks = philosopher->num_philosophers;
	monitor->num_philosophers = philosopher->num_philosophers;

	// Initialize protection mutex for the monitor.
	monitor->fork_mutex = NULL;
	monitor->protection_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(monitor->protection_mutex, NULL);
	return (monitor);
}

// /**
//  * @brief Links all philosophers to the health monitor.
//  *
//  * This function assigns the monitor's protection mutex to each philosopher.
//  *
//  * @param philosophers Array of philosopher structures.
//  * @param monitor Pointer to the health monitor structure.
//  */
void	link_philosophers_to_monitor(t_philo *philosophers, t_philo *monitor)
{
	int	i;

	i = 0;
	// Assign the monitor's protection mutex to all philosophers.
	while (i < monitor->num_philosophers)
	{
		philosophers[i].protection_mutex = monitor->protection_mutex;
		i++;
	}
	// Set the simulation start time.
	monitor->start_time = ft_get_time();
}

// /**
//  * @brief Checks if all philosophers have eaten the required number of times.
//  *
//  * The function uses the monitor's shared data to verify meal counts.
//  *
//  * @param monitor Pointer to the health monitor structure.
//  * @return true if the simulation should continue, false if all conditions are met.
//  */
bool	check_meals_eaten(t_philo *monitor)
{
	int	i;

	i = 0;
	// If no meal count limit is set, return true immediately.
	if (monitor->num_must_eat == -1)
		return (true);

	// Check each philosopher's meal count.
	while (i < monitor->num_philosophers)
	{
		pthread_mutex_lock(monitor->protection_mutex);
		if (monitor->meals_eaten[i] < monitor->num_must_eat)
		{
			// Unlock mutex and continue simulation if the requirement isn't met.
			return (pthread_mutex_unlock(monitor->protection_mutex), true);
		}
		pthread_mutex_unlock(monitor->protection_mutex);
		i++;
	}
	// Return false if all meal requirements are met.
	pthread_mutex_lock(monitor->protection_mutex);
	return (false);
}

// /**
//  * @brief Monitors philosopher health and stops the simulation on starvation.
//  *
//  * Checks if any philosopher exceeds the time-to-die interval without eating.
//  *
//  * @param philosopher Pointer to the monitor structure.
//  * @return NULL when the simulation terminates.
//  */
void	*check_philosopher_health(void *philosopher)
{
	t_philo		*monitor;
	int			i;
	long long	time;

	monitor = (t_philo *)philosopher;
	i = 0;

	// Initial delay to allow philosophers to start.
	ft_sleep(10);

	// Continuously check health and meal counts.
	while (i < monitor->num_philosophers && check_meals_eaten(monitor))
	{
		pthread_mutex_lock(monitor->protection_mutex);
		time = ft_get_time() - monitor->last_meal_time[i];
		pthread_mutex_unlock(monitor->protection_mutex);

		// Check if a philosopher has exceeded time_to_die without eating.
		if (time >= monitor->time_to_die)
		{
			pthread_mutex_lock(monitor->protection_mutex);
			rest_in_peace(i + 1, ft_get_time() - monitor->start_time);
			return (NULL);
		}
		if (i + 1 == monitor->num_philosophers)
			i = -1; // Loop back to the first philosopher.
		i++;
	}
	return (NULL);
}
