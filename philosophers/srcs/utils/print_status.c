/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:10:29 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:10:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

// /**
//  * @brief Logs the current status of a philosopher.
//  *
//  * This function prints the philosopher's action with a timestamp and their ID,
//  * using different colors for each philosopher based on their ID.
//  *
//  * @param philo Pointer to the philosopher structure.
//  * @param action The action to log (e.g., "is eating").
//  */
void	print_status(t_philo *philo, char *action)
{
	char	*color[6]; // Array of colors to distinguish philosophers.

	// Initialize color array for different IDs.
	color[0] = RED;
	color[1] = GREEN;
	color[2] = YELLOW;
	color[3] = BLUE;
	color[4] = MAGENTA;
	color[5] = CYAN;

	// Print action in a specific color corresponding to the philosopher's ID.
	write(1, color[philo->id % 6], ft_strlen(color[philo->id % 6]));

	// Print the time since the simulation started.
	ft_putnbr_fd(ft_get_time() - philo->start_time, 1);
	write(1, "\t", 1);

	// Print the philosopher's ID.
	ft_putnbr_fd(philo->id, 1);
	write(1, "\t", 1);

	// Print the action string (e.g., "is eating").
	write(1, action, ft_strlen(action));

	// Reset the color back to default.
	write(1, RESET, ft_strlen(RESET));
	write(1, "\n", 1);
}

// /**
//  * @brief Logs the death of a philosopher.
//  *
//  * This function prints a message indicating a philosopher has died, along with
//  * their ID and the timestamp.
//  *
//  * @param id The ID of the philosopher who died.
//  * @param time The timestamp of the death relative to simulation start.
//  */
void	rest_in_peace(int id, long long time)
{
	// Print the timestamp of the philosopher's death.
	ft_putnbr_fd(time, 1);
	write(1, "\t", 1);

	// Print the ID of the philosopher who died.
	ft_putnbr_fd(id, 1);
	write(1, "\t", 1);

	// Print the death message.
	write(1, "died", 4);
	write(1, "\n", 1);
}
