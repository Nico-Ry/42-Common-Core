/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:11:08 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:11:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

// /**
//  * @brief Entry point for the philosopher simulation program.
//  *
//  * Initializes the simulation, sets up the health monitor, and starts the
//  * philosopher threads. Cleans up resources upon termination.
//  *
//  * @param argc Number of command-line arguments.
//  * @param argv Array of command-line arguments.
//  * @return 0 if the simulation completes successfully, 1 on failure.
//  */
int	main(int argc, char **argv)
{
	t_philo	*philosophers;   // Pointer to the philosophers' data structures.
	t_philo	*health_monitor; // Pointer to the health monitor structure.

	// Initialize the simulation and philosophers.
	philosophers = initialize_simulation(argc, argv);
	if (!philosophers)
	{
		// Log error if simulation initialization fails.
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Simulation initialization failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1); // Exit with failure status.
	}

	// Set up the health monitor to oversee philosopher states.
	health_monitor = setup_health_monitor(philosophers);
	if (!health_monitor)
	{
		// Log error if health monitor initialization fails.
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Health monitor initialization failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1); // Exit with failure status.
	}

	// Link philosophers to the shared health monitor.
	link_philosophers_to_monitor(philosophers, health_monitor);

	// Start all philosopher threads.
	start_philosopher_threads(philosophers);

	// Start the health monitor thread to check for starvation.
	pthread_create(&health_monitor->philo_thread, NULL,
		check_philosopher_health, health_monitor);

	// Wait for the health monitor thread to finish (end of simulation).
	pthread_join(health_monitor->philo_thread, NULL);

	// Clean up resources after the simulation ends.
	return (clean_garbage(philosophers, health_monitor), 0);
}
