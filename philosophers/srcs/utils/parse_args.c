/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:17:41 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:17:51 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

// /**
//  * @brief Displays an error message for invalid command-line arguments.
//  *
//  * This function is called when the number or format of arguments passed to the
//  * program is incorrect. It prints the expected usage and an example.
//  */
void	ft_error_parse_msg(void)
{
	// Writes an error in red about invalid arguments
	write(2, RED, ft_strlen(RED));
	ft_putstr_fd("Error: Invalid number of arguments\n", 2);

	// Resets color to default
	write(2, RESET, ft_strlen(RESET));
	write(2, "\n", 1);

	// Writes usage instructions in green
	write(2, GREEN, ft_strlen(GREEN));
	ft_putstr_fd("Usage: ./philo [number_of_philosophers] [time_to_die] ", 2);
	ft_putstr_fd("[time_to_eat] [time_to_sleep] (optional: number_of_meals)\n", 2);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);

	// Resets color to default
	write(2, RESET, ft_strlen(RESET));
	write(2, "\n", 1);

	// Displays an example usage in yellow
	write(2, YELLOW, ft_strlen(YELLOW));
	ft_putstr_fd("Example: ./philo 5 800 200 200 3\n", 2);

	// Resets color to default
	write(2, RESET, ft_strlen(RESET));
	write(2, "\n", 1);
}

// /**
//  * @brief Parses and validates command-line arguments.
//  *
//  * @param argc Number of arguments passed to the program.
//  * @param argv Array of argument strings.
//  * @param philo_info Pointer to a structure holding philosopher simulation data.
//  * @return true if arguments are valid; false otherwise.
//  */
bool	parse_arguments(int argc, char **argv, t_philo *philo_info)
{
	// Check for correct number of arguments
	if (argc < 5 || argc > 6)
	{
		ft_error_parse_msg();
		return (false); // Return false if the count is incorrect
	}

	// Validate each argument using helper functions
	if (!validate_num_philosophers(argv[1])       // Validate the number of philosophers
		|| !validate_time_argument(argv[2])       // Validate time_to_die
		|| !validate_time_argument(argv[3])       // Validate time_to_eat
		|| !validate_time_argument(argv[4])       // Validate time_to_sleep
		|| (argc == 6 && !validate_num_must_eat(argv[5]))) // Optional argument validation
	{
		return (false); // Return false if any validation fails
	}

	// Convert arguments to integers and populate philo_info structure
	philo_info->num_philosophers = ft_atoi(argv[1]);
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);

	// If the optional argument is present, set its value
	if (argc == 6)
		philo_info->num_must_eat = ft_atoi(argv[5]);
	else
		philo_info->num_must_eat = -1; // Default value when not specified

	return (true); // All validations passed successfully
}
