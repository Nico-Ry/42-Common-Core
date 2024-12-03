/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:10:51 by nryser            #+#    #+#             */
/*   Updated: 2024/12/03 20:10:51 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

// /**
//  * @brief Checks if a string contains only numeric characters.
//  *
//  * This function ensures that the string represents a valid integer.
//  *
//  * @param str The string to validate.
//  * @return true if the string is numeric, false otherwise.
//  */
bool	is_numeric(const char *str)
{
	// Iterate through each character in the string.
	while (*str)
	{
		// Return false if a non-digit character is found.
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true); // The string is numeric.
}

// /**
//  * @brief Validates the number of philosophers argument.
//  *
//  * Ensures the input is numeric and greater than 0.
//  *
//  * @param arg The string argument to validate.
//  * @return true if valid, false otherwise.
//  */
bool	validate_num_philosophers(const char *arg)
{
	// Check if the argument is numeric and greater than 0.
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid number of philosophers argument\n", 2);
		return (false);
	}
	return (true);
}

// /**
//  * @brief Validates time-related arguments (e.g., time_to_die).
//  *
//  * Ensures the input is numeric and greater than 0.
//  *
//  * @param arg The string argument to validate.
//  * @return true if valid, false otherwise.
//  */
bool	validate_time_argument(const char *arg)
{
	// Check if the argument is numeric and greater than 0.
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid time argument\n", 2);
		return (false);
	}
	return (true);
}

// /**
//  * @brief Validates the optional number of times each philosopher must eat.
//  *
//  * Ensures the input is numeric and greater than 0.
//  *
//  * @param arg The string argument to validate.
//  * @return true if valid, false otherwise.
//  */
bool	validate_num_must_eat(const char *arg)
{
	// Check if the argument is numeric and greater than 0.
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid number of times to eat argument\n", 2);
		return (false);
	}
	return (true);
}
