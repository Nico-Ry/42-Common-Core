/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:20:03 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 16:20:08 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

/**
 * @brief Simulates the sleeping state for a philosopher.
 *
 * This function puts the philosopher in a sleeping state for the
 * designated time. It ensures synchronization with shared resources.
 *
 * @param philosopher Pointer to the philosopher's data structure.
 */
void	start_sleeping(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is sleeping");
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_sleep);
}

/**
 * @brief Simulates the thinking state for a philosopher.
 *
 * This function transitions the philosopher to a thinking state
 * after sleeping. It prepares them for the next eating cycle.
 *
 * @param philosopher Pointer to the philosopher's data structure.
 */
void	start_thinking(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is thinking");
	pthread_mutex_unlock(philosopher->protection_mutex);
}
