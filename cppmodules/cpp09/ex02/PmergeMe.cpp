/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:17:21 by nryser            #+#    #+#             */
/*   Updated: 2026/02/08 18:17:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"

/* ************************************************************************** */
/*                         File-local helper functions                        */
/* ************************************************************************** */

/*
	These helpers live only in this .cpp file:
	- They do NOT change the public API of PmergeMe.
	- They keep the main Ford–Johnson functions readable.
	- They avoid putting non-template implementations in the header.

	The subject asks for a Ford–Johnson (merge-insert) sort. The high-level idea:
	1) Split into pairs (small, large)
	2) Sort the "large" values (recursively)
	3) Build the "main chain" from the sorted larges
	4) Insert the "small" values in a special order (Jacobsthal)
	   using bounded binary search (each small must be inserted before its large)
	5) Insert the possible leftover element ("straggler")


	-----------------------------------------------------------------------
	Mini example to visualize:
		in = [7 3 9 1 5]

	STEP 1: pairs + straggler
		(7,3) -> (3,7)
		(9,1) -> (1,9)
		straggler = 5

	STEP 2: larges = [7,9]
		recursively sorted -> [7,9] (already)

	STEP 3: sortedPairs in larges order
		sortedPairs = [(3,7), (1,9)]

	STEP 4: mainChain = [7,9]

	STEP 5: insert smalls with Jacobsthal order
		pend = [3,1] (paired to 7 and 9)
		Jacobsthal order for n=2 -> [1,2]
		insert 3 before its large (7): mainChain becomes [3,7,9]
		insert 1 before its large (9): bounded search only in [0..index(9))
			mainChain becomes [1,3,7,9]

	STEP 6: insert straggler 5 (full-range)
		mainChain becomes [1,3,5,7,9]

	Result: sorted.
*/

namespace
{
	// Find the current index of `value` inside mainChain.
	// Use it to compute the bound "insert before this paired large".
	static size_t	findIndexVector(const std::vector<int> &mainChain, int value)
	{
		for (size_t i = 0; i < mainChain.size(); ++i)
		{
			if (mainChain[i] == value)
				return (i);
		}
		return (mainChain.size());
	}

	static size_t	findIndexDeque(const std::deque<int> &mainChain, int value)
	{
		for (size_t i = 0; i < mainChain.size(); ++i)
		{
			if (mainChain[i] == value)
				return (i);
		}
		return (mainChain.size());
	}

	// Full-range binary insertion: insert `value` into the sorted container.
	// This is used for the "straggler" (the element that had no pair).
	static void	binaryInsertFullVector(std::vector<int> &mainChain, int value)
	{
		size_t	lo = 0;
		size_t	hi = mainChain.size();

		while (lo < hi)
		{
			size_t mid = lo + (hi - lo) / 2;
			if (mainChain[mid] < value)
				lo = mid + 1;
			else
				hi = mid;
		}
		mainChain.insert(mainChain.begin() + lo, value);
	}

	static void	binaryInsertFullDeque(std::deque<int> &mainChain, int value)
	{
		size_t	lo = 0;
		size_t	hi = mainChain.size();

		while (lo < hi)
		{
			size_t mid = lo + (hi - lo) / 2;
			if (mainChain[mid] < value)
				lo = mid + 1;
			else
				hi = mid;
		}
		mainChain.insert(mainChain.begin() + lo, value);
	}

}

/* ************************************************************************** */
/*                     Pair reordering helpers (private)                      */
/* ************************************************************************** */

/*
	After sorting only the "large" values, need to rebuild the full list of
	pairs (small, large) in that exact order.

	Example:
	pairs: (2,9) (1,5) (3,5)
	sorted larges: 5 5 9
	Must rebuild sortedPairs so the 2 pairs with large==5 are both used exactly once.
*/

void	PmergeMe::buildSortedPairsVector(std::vector<Pair> &sortedPairs,
							const std::vector<Pair> &pairs,
							const std::vector<int> &sortedLargers)
{
	sortedPairs.clear();
	sortedPairs.reserve(pairs.size());

	std::vector<bool>	used(pairs.size(), false);
	for (size_t i = 0; i < sortedLargers.size(); ++i)
	{
		int L = sortedLargers[i];
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (used[j] == false && pairs[j].large == L)
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
}

void	PmergeMe::buildSortedPairsDeque(std::deque<Pair> &sortedPairs,
						const std::deque<Pair> &pairs,
						const std::deque<int> &sortedLargers)
{
	sortedPairs.clear();
	std::deque<bool>	used(pairs.size(), false);

	for (size_t i = 0; i < sortedLargers.size(); ++i)
	{
		int L = sortedLargers[i];
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (used[j] == false && pairs[j].large == L)
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
}

/* ************************************************************************** */
/*                                 Canonical                                  */
/* ************************************************************************** */

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe	&PmergeMe::operator=(const PmergeMe &other) { (void)other; return (*this); }
PmergeMe::~PmergeMe() {}

/* ************************************************************************** */
/*                               Printing helper                              */
/* ************************************************************************** */

void	PmergeMe::printSequence(const std::string &label, const std::vector<int> &v)
{
	std::cout << label;
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                          Jacobsthal order (vector)                          */
/* ************************************************************************** */

/*
	Jacobsthal sequence:
		J(0)=0, J(1)=1
		J(n)=J(n-1) + 2*J(n-2)

		0, 1, 1, 3, 5, 11, 21, 43, ...
	Generate a 1-based insertion order for "pend" elements.
	pend #1, pend #2, pend #3, pend #4, pend #5
	Jacobsthal tells you in which order to insert them.
	Meaning:
		Insert small from pair #1 first
		Then pair #3
		Then pair #2
		Then pair #5
		Then pair #4

	Goal:
	- Not sequential insertion
	- Each index inserted exactly once
	- Jacobsthal grouped insertion (descending blocks)
*/
void	PmergeMe::buildJacobsthalOrderVector(std::vector<size_t> &order, size_t n)
{
	order.clear();
	if (n == 0)
		return ;

	std::vector<bool>	used(n + 1, false);

	order.push_back(1);
	used[1] = true;

	//Generate Jacobsthal jumps
	size_t	j0 = 0;
	size_t	j1 = 1;

	/*
		Same Jacobsthal schedule as the vector version.
		I keep 2 implementations because the module asks for 2 different containers.
	*/

	/*
		Generate Jacobsthal numbers until I reach (or pass) n.
		For each new Jacobsthal value J(k) = j1, I add indices in a descending
		block: j1, j1-1, ..., j0+1.

		Why descending blocks?
		- It's a common way to reproduce the Ford–Johnson insertion schedule.
		- It reduces the number of comparisons compared to naive sequential insertion.
	*/
	while (true)
	{
		size_t j2 = j1 + 2 * j0;
		j0 = j1;
		j1 = j2;

		if (j1 >= n)
			break;

		size_t start = j1;
		size_t end = j0 + 1;

		/*
			Careful: k is size_t (unsigned).
			When k reaches 0, "--k" would underflow and become a huge number.
			So break explicitly when k == 0.
		*/
		/*
			Careful: k is unsigned (size_t).I must prevent underflow at 0.
		*/
		for (size_t k = start; k >= end; --k)
		{
			if (k <= n && used[k] == false)
			{
				order.push_back(k);
				used[k] = true;
			}
			if (k == 0)
				break;
		}
	}

	/*
		Finally, add any indices that were never inserted by the Jacobsthal blocks.
		Start at 2 because 1 is always inserted first.
	*/
	for (size_t i = 2; i <= n; ++i)
	{
		if (used[i] == false)
			order.push_back(i);
	}
}

/* ************************************************************************** */
/*                          Jacobsthal order (deque)                           */
/* ************************************************************************** */

void	PmergeMe::buildJacobsthalOrderDeque(std::deque<size_t> &order, size_t n)
{
	order.clear();
	if (n == 0)
		return ;

	std::deque<bool>	used(n + 1, false);

	order.push_back(1);
	used[1] = true;

	size_t	j0 = 0;
	size_t	j1 = 1;

	while (true)
	{
		size_t j2 = j1 + 2 * j0;
		j0 = j1;
		j1 = j2;

		if (j1 >= n)
			break;

		size_t start = j1;
		size_t end = j0 + 1;

		for (size_t k = start; k >= end; --k)
		{
			if (k <= n && used[k] == false)
			{
				order.push_back(k);
				used[k] = true;
			}
			if (k == 0)
				break;
		}
	}

	for (size_t i = 2; i <= n; ++i)
	{
		if (used[i] == false)
			order.push_back(i);
	}
}

/* ************************************************************************** */
/*                     Bounded binary insertion (vector)                      */
/* ************************************************************************** */

/*
	Insert value into mainChain using binary search, but only inside:
		[0 .. upperBoundIndex)
	upperBoundIndex is the index of the paired "large" element.
	So the "small" must be inserted before that large.
*/
void	PmergeMe::boundedInsertVector(std::vector<int> &mainChain,
			int value, size_t upperBoundIndex)
{
	size_t	lo = 0;
	size_t	hi = upperBoundIndex;

	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (mainChain[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	mainChain.insert(mainChain.begin() + lo, value);
}

/* ************************************************************************** */
/*                      Bounded binary insertion (deque)                      */
/* ************************************************************************** */

void	PmergeMe::boundedInsertDeque(std::deque<int> &mainChain,
			int value, size_t upperBoundIndex)
{
	size_t	lo = 0;
	size_t	hi = upperBoundIndex;

	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (mainChain[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	mainChain.insert(mainChain.begin() + lo, value);
}

/* ************************************************************************** */
/*                        Pair building (vector / deque)                       */
/* ************************************************************************** */

void	PmergeMe::buildPairsVector(std::vector<Pair> &pairs, bool &hasStraggler, int &straggler,
			const std::vector<int> &in)
{
	pairs.clear();
	hasStraggler = (in.size() % 2 != 0);
	straggler = 0;

	for (size_t i = 0; i + 1 < in.size(); i += 2)
	{
		int a = in[i];
		int b = in[i + 1];

		if (a <= b)
		{
			Pair p;
			p.small = a;
			p.large = b;
			pairs.push_back(p);
		}
		else
		{
			Pair p;
			p.small = b;
			p.large = a;
			pairs.push_back(p);
		}
	}

	if (hasStraggler)
		straggler = in.back();
}

void	PmergeMe::buildPairsDeque(std::deque<Pair> &pairs, bool &hasStraggler, int &straggler,
			const std::deque<int> &in)
{
	pairs.clear();
	hasStraggler = (in.size() % 2 != 0);
	straggler = 0;

	for (size_t i = 0; i + 1 < in.size(); i += 2)
	{
		int a = in[i];
		int b = in[i + 1];

		if (a <= b)
		{
			Pair p;
			p.small = a;
			p.large = b;
			pairs.push_back(p);
		}
		else
		{
			Pair p;
			p.small = b;
			p.large = a;
			pairs.push_back(p);
		}
	}

	if (hasStraggler)
		straggler = in.back();
}

/* ************************************************************************** */
/*                    Ford–Johnson (merge-insert) for vector                  */
/* ************************************************************************** */

void	PmergeMe::fordJohnsonVector(std::vector<int> &out, const std::vector<int> &in)
{
	out.clear();
	if (in.size() <= 1)
	{
		out = in;
		return ;
	}

	/*
		STEP 1: Make (small, large) pairs + optional straggler.
	*/
	std::vector<Pair>	pairs;
	bool				hasStraggler;
	int					straggler;

	buildPairsVector(pairs, hasStraggler, straggler, in);

	/*
		STEP 2: Recursively sort the "larges" only.
	*/
	std::vector<int>	largers;
	largers.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].large);

	std::vector<int>	sortedLargers;
	fordJohnsonVector(sortedLargers, largers);

	/*
		STEP 3: Rebuild sortedPairs in the exact order of sortedLargers.
		Why I need this extra step:
		- I sorted only the "large" values.
		- I now need the full pair (small, large) in that same order.
		- There can be duplicates, so I mark pairs as used.
	*/
	std::vector<Pair>	sortedPairs;
	buildSortedPairsVector(sortedPairs, pairs, sortedLargers);

	/*
		STEP 4: Main chain starts with all larges in sorted order.
	*/
	std::vector<int>	mainChain;
	mainChain.reserve(sortedPairs.size() + (hasStraggler ? 1 : 0));

	for (size_t i = 0; i < sortedPairs.size(); ++i)
		mainChain.push_back(sortedPairs[i].large);

	/*
		STEP 5: Insert the small elements (pend) using Jacobsthal order.
		Bound for each small is the current index of its paired large.
	*/
	size_t pendCount = sortedPairs.size();
	if (pendCount > 0)
	{
		std::vector<size_t>	order;
		buildJacobsthalOrderVector(order, pendCount);

		for (size_t t = 0; t < order.size(); ++t)
		{
			size_t idx = order[t] - 1;
			int small = sortedPairs[idx].small;
			int large = sortedPairs[idx].large;

			// Find the current position of the paired large in mainChain.
			// (After previous insertions, the large has moved to the right.)
			size_t bound = findIndexVector(mainChain, large);

			boundedInsertVector(mainChain, small, bound);
		}
	}

	/*
		STEP 6: Insert the straggler (if any).
		The straggler was not paired, so it has no "must be before large" constraint.
		I can insert it into the full sorted range.
	*/
	if (hasStraggler)
		binaryInsertFullVector(mainChain, straggler);

	out = mainChain;
}

/* ************************************************************************** */
/*                    Ford–Johnson (merge-insert) for deque                   */
/* ************************************************************************** */

void	PmergeMe::fordJohnsonDeque(std::deque<int> &out, const std::deque<int> &in)
{
	out.clear();
	if (in.size() <= 1)
	{
		out = in;
		return ;
	}

	/*
		Same algorithm as the vector version, but implemented for std::deque.
		The goal of the module is to compare timings between 2 different containers.
	*/

	/*
		STEP 1: Make (small, large) pairs + optional straggler.
	*/
	std::deque<Pair>	pairs;
	bool				hasStraggler;
	int					straggler;

	buildPairsDeque(pairs, hasStraggler, straggler, in);

	/*
		STEP 2: Recursively sort the "larges" only (deque version).
	*/
	std::deque<int>	largers;
	for (size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].large);

	std::deque<int>	sortedLargers;
	fordJohnsonDeque(sortedLargers, largers);

	/*
		STEP 3: Rebuild sortedPairs (deque) in the order of sortedLargers.
		Same "used" technique for duplicates.
	*/
	std::deque<Pair>	sortedPairs;
	buildSortedPairsDeque(sortedPairs, pairs, sortedLargers);

	/*
		STEP 4: Main chain starts with all larges in sorted order.
	*/
	std::deque<int>	mainChain;
	for (size_t i = 0; i < sortedPairs.size(); ++i)
		mainChain.push_back(sortedPairs[i].large);

	/*
		STEP 5: Insert the small elements (pend) using Jacobsthal order (deque).
	*/
	size_t pendCount = sortedPairs.size();
	if (pendCount > 0)
	{
		std::deque<size_t>	order;
		buildJacobsthalOrderDeque(order, pendCount);

		for (size_t t = 0; t < order.size(); ++t)
		{
			size_t idx = order[t] - 1;
			int small = sortedPairs[idx].small;
			int large = sortedPairs[idx].large;

			// Find current position of the paired large in the main chain.
			size_t bound = findIndexDeque(mainChain, large);

			boundedInsertDeque(mainChain, small, bound);
		}
	}

	/*
		STEP 6: Insert the straggler (no bound constraint).
	*/
	if (hasStraggler)
		binaryInsertFullDeque(mainChain, straggler);

	out = mainChain;
}

/* ************************************************************************** */
/*                                Public API                                  */
/* ************************************************************************** */

void	PmergeMe::sortVector(std::vector<int> &v)
{
	std::vector<int>	out;
	fordJohnsonVector(out, v);
	v.swap(out);
}

void	PmergeMe::sortDeque(std::deque<int> &d)
{
	std::deque<int>	out;
	fordJohnsonDeque(out, d);
	d.swap(out);
}

/* ************************************************************************** */
/*                             Timing (microseconds)                          */
/* ************************************************************************** */

double	PmergeMe::timeVector(std::vector<int> &v)
{
	std::clock_t	start;
	std::clock_t	end;

	start = std::clock();
	sortVector(v);
	end = std::clock();

	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}

double	PmergeMe::timeDeque(std::deque<int> &d)
{
	std::clock_t	start;
	std::clock_t	end;

	start = std::clock();
	sortDeque(d);
	end = std::clock();

	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}


/*
===============================================================================
FORD–JOHNSON / MERGE-INSERT SORT (PmergeMe) — FULL WALKTHROUGH EXAMPLE
===============================================================================

Input:
	3 1 5 8 9 10 2 25 95 11 4 62 95 0 65

STEP 1) Build pairs (small, large) + straggler
	Read input two-by-two and normalize each pair so small <= large:

	(3,1)   -> (1,3)
	(5,8)   -> (5,8)
	(9,10)  -> (9,10)
	(2,25)  -> (2,25)
	(95,11) -> (11,95)
	(4,62)  -> (4,62)
	(95,0)  -> (0,95)
	Straggler (odd count) = 65

STEP 2) Sort ONLY the "large" values recursively
	Larges = [3, 8, 10, 25, 95, 62, 95]
	After recursion:
	sortedLargers = [3, 8, 10, 25, 62, 95, 95]

STEP 3) Rebuild sortedPairs in the order of sortedLargers
	Match each large in sortedLargers to its original pair (handling duplicates
	using a "used[]" array):

	sortedPairs (in large order):
	  1: (1,3)
	  2: (5,8)
	  3: (9,10)
	  4: (2,25)
	  5: (4,62)
	  6: (11,95)
	  7: (0,95)

STEP 4) Main chain starts with sorted larges
	mainChain = [3, 8, 10, 25, 62, 95, 95]

STEP 5) Insert all "small" elements (pend) using bounded binary search
	For each pair (small, large), the small MUST be inserted before its paired
	large. Therefore we do a binary search only in:
		[0 .. index_of(large))
	This is the "bounded" part (it preserves correctness).

	IMPORTANT: Insertion order is Jacobsthal-based (optimization).
	We do NOT insert Jacobsthal numbers into the chain. We use them to generate
	an ORDER OF INDICES (which pend element to insert next).

	For pendCount = 7, buildJacobsthalOrder() produces:
		order = [1, 3, 2, 5, 4, 6, 7]

	Why?
	  - Always start with 1
	  - Jacobsthal numbers are: 0,1,1,3,5,11,...
	  - Each time we reach a Jacobsthal value j1 (< n), we insert a descending
		block from j1 down to (previous_j + 1)
		Example for n=7:
		  j=3 -> add [3,2]
		  j=5 -> add [5,4]
	  - Then append remaining unused indices [6,7]

	Apply insertions in that order (bounded before paired large):
	  Insert #1 small=1  before large=3
	  Insert #3 small=9  before large=10
	  Insert #2 small=5  before large=8
	  Insert #5 small=4  before large=62
	  Insert #4 small=2  before large=25
	  Insert #6 small=11 before large=95
	  Insert #7 small=0  before large=95

	Result after all small insertions:
	  [0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 25, 62, 95, 95]

STEP 6) Insert straggler with full-range binary search
	Straggler = 65
	Insert into the fully sorted chain (no bound):
	Final:
	  [0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 25, 62, 65, 95, 95]

Summary:
  - Sort larges recursively to create a sorted "main chain skeleton"
  - Insert smalls with bounded binary search (must be before their paired large)
  - Use Jacobsthal-generated index order to reduce comparisons (performance)
  - Insert the straggler at the end with full-range binary insertion
===============================================================================
*/
