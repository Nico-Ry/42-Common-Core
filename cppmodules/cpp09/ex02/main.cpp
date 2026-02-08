/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:16:37 by nryser            #+#    #+#             */
/*   Updated: 2026/02/08 18:16:37 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

static bool	parsePositiveInt(const std::string &s, int &out)
{
	/*
		Subject expects positive integers.
		So reject 0 and any non-digit / overflow.
	*/
	if (s.empty())
		return (false);

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}

	long n = std::strtol(s.c_str(), 0, 10);
	if (n <= 0 || n > INT_MAX)
		return (false);

	out = static_cast<int>(n);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int>	vec;
	std::deque<int>	deq;

	for (int i = 1; i < argc; ++i)
	{
		int	value;

		if (!parsePositiveInt(argv[i], value))
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}

		/*
			Duplicates:
			- Subject says duplicates error management is our discretion.
			- ACCEPT duplicates (no filtering, no error).
		*/
		vec.push_back(value);
		deq.push_back(value);
	}

	// Print BEFORE (use vector output as the reference)
	PmergeMe::printSequence("Before: ", vec);

	double vecUs = PmergeMe::timeVector(vec);
	double deqUs = PmergeMe::timeDeque(deq);

	// Print AFTER
	PmergeMe::printSequence("After:  ", vec);

	// Format floating-point output (microseconds with decimals)
	// std::cout << std::fixed << std::setprecision(6);

	// Print timings
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << vecUs << " us" << std::endl;

	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << deqUs << " us" << std::endl;

	return (0);
}
