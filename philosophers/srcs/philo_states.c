/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:16:40 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:16:47 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

// /**
//  * @brief Updates the philosopher's state to sleeping.
//  *
//  * Logs the sleeping action and puts the thread to sleep for the specified
//  * sleeping duration.
//  *
//  * @param philosopher Pointer to the philosopher's data structure.
//  */
void	start_sleeping(t_philo *philosopher)
{
	// Log the sleeping action.
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is sleeping");
	pthread_mutex_unlock(philosopher->protection_mutex);

	// Simulate sleeping by putting the thread to sleep.
	ft_sleep(philosopher->time_to_sleep);
}

// /**
//  * @brief Updates the philosopher's state to thinking.
//  *
//  * Logs the thinking action. Philosophers typically start thinking after
//  * finishing their sleep.
//  *
//  * @param philosopher Pointer to the philosopher's data structure.
//  */
void	start_thinking(t_philo *philosopher)
{
	// Log the thinking action.
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is thinking");
	pthread_mutex_unlock(philosopher->protection_mutex);

	// Random thinking time between 50 ms and 150 ms.
	/*long long thinking_time = (rand() % 101) + 50;
	ft_sleep(thinking_time);*/
}
