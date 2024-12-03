/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:14:44 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:14:54 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

// /**
//  * @brief Initializes the philosopher simulation.
//  *
//  * Parses command-line arguments, allocates memory for philosopher data, and
//  * sets up all necessary structures for the simulation.
//  *
//  * @param argc Number of command-line arguments.
//  * @param argv Array of command-line arguments.
//  * @return Pointer to the array of philosopher structures or NULL on failure.
//  */
t_philo	*initialize_simulation(int argc, char **argv)
{
	t_philo	*philo_info;              // Temporary storage for simulation parameters.
	t_philo	*philosophers_initialized; // Pointer to the array of philosopher structures.

	// Allocate memory for the simulation parameters structure.
	philo_info = malloc(sizeof(t_philo));
	if (!philo_info)
		return (NULL);

	// Parse and validate command-line arguments.
	if (!parse_arguments(argc, argv, philo_info))
	{
		free(philo_info);
		return (NULL);
	}

	// Initialize all philosopher data structures.
	philosophers_initialized = initialize_philosophers(philo_info);
	if (!philosophers_initialized)
	{
		free(philo_info);
		return (NULL);
	}
	return (philosophers_initialized);
}

// /**
//  * @brief Allocates and initializes data for all philosophers.
//  *
//  * Creates and initializes an array of philosopher structures with their
//  * respective properties.
//  *
//  * @param philo_info Pointer to the simulation parameters.
//  * @return Pointer to the array of philosopher structures or NULL on failure.
//  */
t_philo	*initialize_philosophers(t_philo *philo_info)
{
	t_philo			*philos_initialized; // Array of philosopher structures.
	pthread_mutex_t	*forks;             // Array of mutexes for forks.
	long long		*last_meal_time;    // Array tracking the last meal time of each philosopher.

	// Allocate memory for philosophers.
	philos_initialized = malloc(sizeof(t_philo) * philo_info->num_philosophers);
	if (!philos_initialized)
		return (NULL);

	// Initialize forks and last meal time arrays.
	forks = initialize_forks(philo_info->num_philosophers);
	if (!forks)
	{
		free(philos_initialized);
		return (NULL);
	}
	last_meal_time = initialize_last_meal_time(philo_info->num_philosophers);
	if (!last_meal_time)
	{
		free(philos_initialized);
		free(forks);
		return (NULL);
	}

	// Assign data to each philosopher.
	initialize_philos_data(philos_initialized, philo_info, forks, last_meal_time);
	return (philos_initialized);
}

// /**
//  * @brief Initializes mutexes for forks.
//  *
//  * Creates an array of mutexes, one for each fork.
//  *
//  * @param num_philosophers Number of philosophers (and forks).
//  * @return Pointer to the array of mutexes or NULL on failure.
//  */
pthread_mutex_t	*initialize_forks(int num_philosophers)
{
	int				i;
	pthread_mutex_t	*forks;

	// Allocate memory for fork mutexes.
	forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);
	if (!forks)
		return (NULL);

	// Initialize each mutex.
	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

// /**
//  * @brief Initializes the last meal time for each philosopher.
//  *
//  * Allocates and sets the initial value for the last meal time array.
//  *
//  * @param num_philosophers Number of philosophers.
//  * @return Pointer to the array of timestamps or NULL on failure.
//  */
long long	*initialize_last_meal_time(int num_philosophers)
{
	int			i;
	long long	*last_meal_time;

	// Allocate memory for the last meal time array.
	last_meal_time = malloc(sizeof(long long) * num_philosophers);
	if (!last_meal_time)
		return (NULL);

	// Set the initial time for each philosopher.
	i = 0;
	while (i < num_philosophers)
	{
		last_meal_time[i] = ft_get_time();
		i++;
	}
	return (last_meal_time);
}

// /**
//  * @brief Assigns data to each philosopher structure.
//  *
//  * Sets the properties of each philosopher, including IDs, mutexes, and shared
//  * arrays for forks and meals.
//  *
//  * @param philosophers_initialized Array of philosopher structures.
//  * @param philo Pointer to the simulation parameters.
//  * @param num_forks Pointer to the array of fork mutexes.
//  * @param last_meal_time Pointer to the array of last meal times.
//  */
void	initialize_philos_data(t_philo *philosophers_initialized,
		t_philo *philo, pthread_mutex_t *num_forks,
		long long *last_meal_time)
{
	int	i;
	int	*meals;

	// Allocate memory for the meals eaten array.
	meals = malloc(sizeof(int) * philo->num_philosophers);
	if (!meals)
		return ;

	// Initialize the meals eaten array to zero.
	memset(meals, 0, sizeof(int) * philo->num_philosophers);

	// Set individual philosopher data.
	i = 0;
	while (i < philo->num_philosophers)
	{
		philosophers_initialized[i].id = i + 1;
		philosophers_initialized[i].meals_eaten = meals;
		philosophers_initialized[i].time_to_die = philo->time_to_die;
		philosophers_initialized[i].time_to_eat = philo->time_to_eat;
		philosophers_initialized[i].time_to_sleep = philo->time_to_sleep;
		philosophers_initialized[i].num_must_eat = philo->num_must_eat;
		philosophers_initialized[i].last_meal_time = last_meal_time;
		philosophers_initialized[i].num_forks = philo->num_philosophers;
		philosophers_initialized[i].num_philosophers = philo->num_philosophers;
		philosophers_initialized[i].fork_mutex = num_forks;
		i++;
	}

	// Free temporary simulation parameter structure.
	free(philo);
}
