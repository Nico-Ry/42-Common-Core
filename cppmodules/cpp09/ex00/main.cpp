/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:01:09 by nryser            #+#    #+#             */
/*   Updated: 2026/02/02 19:01:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try {
		if (argc < 2)
			throw std::string("could not open file.");
		if (argc > 2)
			throw std::string("too many arguments.");

		BitcoinExchange bitcoin;
		bitcoin.handleInputFile(std::string(argv[1]));

	} catch (const std::string &error)
	{
		std::cerr << "Error: " << error << std::endl;
		return (1);
	}

	return (0);
}
