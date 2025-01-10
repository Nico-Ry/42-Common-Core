/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:21:23 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 16:21:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

/**
 * @brief Prints the current action of a philosopher.
 *
 * Outputs a formatted message describing the philosopher's current
 * state, such as taking a fork, eating, or sleeping.
 *
 * @param philo Pointer to the philosopher's data structure.
 * @param action A string representing the action performed.
 */
void	print_status(t_philo *philo, char *action)
{
	char	*color[6];

	color[0] = RED;
	color[1] = GREEN;
	color[2] = YELLOW;
	color[3] = BLUE;
	color[4] = MAGENTA;
	color[5] = CYAN;
	write(1, color[philo->id % 6], ft_strlen(color[philo->id % 6]));
	ft_putnbr_fd(ft_get_time() - philo->start_time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(philo->id, 1);
	write(1, "\t", 1);
	write(1, action, ft_strlen(action));
	write(1, RESET, ft_strlen(RESET));
	write(1, "\n", 1);
}

/**
 * @brief Announces the death of a philosopher.
 *
 * Outputs a message indicating that a philosopher has died,
 * along with the timestamp of the event.
 *
 * @param id The ID of the deceased philosopher.
 * @param time The time at which the philosopher died.
 */
void	rest_in_peace(int id, long long time)
{
	ft_putnbr_fd(time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(id, 1);
	write(1, "\t", 1);
	write(1, "died", 4);
	write(1, "\n", 1);
}
