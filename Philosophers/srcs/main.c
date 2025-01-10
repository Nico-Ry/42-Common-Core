/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:22:52 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 16:24:45 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

/**
 * @brief Entry point for the Philosophers program.
 *
 * Initializes the simulation, parses arguments, and orchestrates the
 * philosopher threads.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return Exit status of the program (0 for success, non-zero for errors).
 */
int	main(int argc, char **argv)
{
	t_philo	*philosophers;
	t_philo	*health_monitor;

	philosophers = initialize_simulation(argc, argv);
	if (!philosophers)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Simulation initialization failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	health_monitor = setup_health_monitor(philosophers);
	if (!health_monitor)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Health monitor initialization failed.\n", 2);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	link_philosophers_to_monitor(philosophers, health_monitor);
	start_philosopher_threads(philosophers);
	pthread_create(&health_monitor->philo_thread, NULL,
		check_philosopher_health, health_monitor);
	pthread_join(health_monitor->philo_thread, NULL);
	return (clean_garbage(philosophers, health_monitor), 0);
}

/*
valgrind --leak-check=full --suppressions=valgrind.supp
./Philosophers 2 1000 200 200 5
should have 1+ free for each philosopher
for valgrind put in a file valgrind.supp :

{
   TLS_suppression
   Memcheck:Leak
   match-leak-kinds: possible
   fun:calloc
   fun:calloc
   fun:allocate_dtv
   fun:_dl_allocate_tls
   fun:allocate_stack
   fun:pthread_create@@GLIBC_2.34
   fun:start_philosopher_threads
   fun:main
}


*/
