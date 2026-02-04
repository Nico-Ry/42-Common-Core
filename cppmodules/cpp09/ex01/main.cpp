/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:15:16 by nryser            #+#    #+#             */
/*   Updated: 2026/02/04 19:15:16 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn;

		rpn.evaluate(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch (const std::string &)
	{
		// Subject example prints exactly "Error"
		std::cerr << "Error" << std::endl;
		return (1);
	}

	return (0);
}
