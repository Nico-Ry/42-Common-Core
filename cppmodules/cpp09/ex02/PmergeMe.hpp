/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:26:26 by nryser            #+#    #+#             */
/*   Updated: 2026/02/08 17:26:57 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <climits>
# include <iomanip>

/*
	PmergeMe (CPP09 ex02)

	Goal:
	- Sort the input using the Ford–Johnson algorithm (merge-insert sort).
	- Do it twice: once with std::vector and once with std::deque.
	- Measure and print time for each container.

	Constraints / evaluation:
	- Must use at least 2 containers.
	- Must use Ford–Johnson (pairs + Jacobsthal insertion + binary search).
*/


class	PmergeMe
{
	private:
		/*
			Store each pair as (small, large).
			Ford–Johnson sorts the "large" elements recursively,
			then inserts the "small" elements in Jacobsthal order.
		*/
		struct Pair
		{
			int	small;
			int	large;
		};

		/* ---------------- Ford–Johnson for std::vector ---------------- */

		static void	fordJohnsonVector(std::vector<int> &out, const std::vector<int> &in);
		static void	buildPairsVector(std::vector<Pair> &pairs, bool &hasStraggler, int &straggler,
						const std::vector<int> &in);

		static void	buildJacobsthalOrderVector(std::vector<size_t> &order, size_t n);

		static void	boundedInsertVector(std::vector<int> &mainChain,
						int value, size_t upperBoundIndex);

		// Rebuild the list of pairs to match the order of the sorted "large" values.
		// Kept as a private helper because it manipulates Pair directly.
		static void	buildSortedPairsVector(std::vector<Pair> &sortedPairs,
						const std::vector<Pair> &pairs,
						const std::vector<int> &sortedLargers);

		/* ---------------- Ford–Johnson for std::deque ----------------- */

		static void	fordJohnsonDeque(std::deque<int> &out, const std::deque<int> &in);
		static void	buildPairsDeque(std::deque<Pair> &pairs, bool &hasStraggler, int &straggler,
						const std::deque<int> &in);

		static void	buildJacobsthalOrderDeque(std::deque<size_t> &order, size_t n);

		static void	boundedInsertDeque(std::deque<int> &mainChain,
						int value, size_t upperBoundIndex);
						
		static void	buildSortedPairsDeque(std::deque<Pair> &sortedPairs,
							const std::deque<Pair> &pairs,
							const std::deque<int> &sortedLargers);

	public:

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		// Public entry points
		static void		sortVector(std::vector<int> &v);
		static void		sortDeque(std::deque<int> &d);

		// Timing helpers (microseconds)
		static double	timeVector(std::vector<int> &v);
		static double	timeDeque(std::deque<int> &d);

		// printing helper
		static void	printSequence(const std::string &label, const std::vector<int> &v);
};

#endif
