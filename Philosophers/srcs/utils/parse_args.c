/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:21:08 by nryser            #+#    #+#             */
/*   Updated: 2025/01/10 16:21:14 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

/**
 * @brief Displays an error message for argument parsing issues.
 *
 * Prints an error message when invalid or insufficient arguments are
 * provided to the program.
 */
void	ft_error_parse_msg(void)
{
	write(2, RED, ft_strlen(RED));
	ft_putstr_fd("Error: Invalid number of arguments\n", 2);
	write(2, RESET, ft_strlen(RESET));
	write(2, "\n", 1);
	write(2, GREEN, ft_strlen(GREEN));
	ft_putstr_fd("Usage: ./philo [number_of_philosophers] [time_to_die] ", 2);
	ft_putstr_fd("[time_to_eat] [time_to_sleep] (optional)", 2);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);
	write(2, RESET, ft_strlen(RESET));
	write(2, "\n", 1);
	write(2, YELLOW, ft_strlen(YELLOW));
	ft_putstr_fd("Example: ./philo 5 800 200 200 3\n", 2);
	write(2, RESET, ft_strlen(RESET));
	write(2, "\n", 1);
	write(2, RESET, ft_strlen(RESET));
}

/**
 * @brief Parses command-line arguments for the simulation.
 *
 * Validates the arguments and populates the simulation structure with
 * the parsed values.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param philo_info Pointer to the simulation structure to populate.
 * @return True if arguments are valid, false otherwise.
 */
bool	parse_arguments(int argc, char **argv, t_philo *philo_info)
{
	if (argc < 5 || argc > 6)
	{
		ft_error_parse_msg();
		return (false);
	}
	if (!validate_num_philosophers(argv[1])
		|| !validate_time_argument(argv[2])
		|| !validate_time_argument(argv[3])
		|| !validate_time_argument(argv[4])
		|| (argc == 6 && !validate_num_must_eat(argv[5])))
	{
		return (false);
	}
	philo_info->num_philosophers = ft_atoi(argv[1]);
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_info->num_must_eat = ft_atoi(argv[5]);
	else
		philo_info->num_must_eat = -1;
	return (true);
}
