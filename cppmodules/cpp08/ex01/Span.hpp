/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:49:45 by nryser            #+#    #+#             */
/*   Updated: 2026/01/21 13:49:52 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>        // std::vector<int> (our internal storage)
#include <algorithm>     // std::sort, std::min_element, std::max_element (later in .cpp)
#include <stdexcept>     // std::exception base + std::runtime_error (or custom exceptions)
#include <limits>        // std::numeric_limits<int> (useful for shortestSpan, optional)

/*
	Exercise 01: Span

	Goal:
	- Store up to N integers.
	- Provide:
		- addNumber(int)                 -> add 1 number (throws if full)
		- shortestSpan()                 -> min distance between any 2 numbers (throws if size < 2)
		- longestSpan()                  -> max distance between any 2 numbers (throws if size < 2)
		- addNumber(range of iterators)  -> add many numbers at once (throws if it would exceed capacity)

	Why std::vector<int>?
	- Works well with sorting (std::sort) and iteration.
	- Compact and efficient for storing many ints.

	Important rule:
	- I DO NOT sort on every insertion (too expensive).
	- I sort only when I need to compute shortestSpan.
*/

class Span
{
private:
	/*
		_n is the maximum capacity (fixed at construction).
		- It is unsigned because the subject uses an unsigned int.
	*/
	unsigned int		_n;

	/*
		_storage holds the actual integers the user adds.
		- I must never store more than _n elements.
	*/
	std::vector<int>	_storage;

public:
	/* ================= Orthodox Canonical Form ================= */

	Span();                         // default constructor
	Span(unsigned int n);           // main constructor required by subject
	Span(const Span& other);        // copy constructor
	Span& operator=(const Span& other); // copy assignment operator
	~Span();                        // destructor

	/* ================= Core API required by subject ================= */

	/*
		Add one number.
		Throws if the Span is already full (size == _n).
	*/
	void	addNumber(int value);

	/*
		Compute the minimum span (minimum difference between any 2 numbers).
		Throws if there are fewer than 2 stored numbers.
	*/
	int		shortestSpan() const;

	/*
		Compute the maximum span.
		Throws if there are fewer than 2 stored numbers.
		Typical logic: max(element) - min(element)
	*/
	int		longestSpan() const;

	/* ================= Bonus / required extension: range insertion ================= */

	/*
		Add many numbers at once using an iterator range.

		This is the "range of iterators" requirement:
		- Containers often provide member functions that accept [first, last).
	*/
	template <typename InputIt>
	void	addNumber(InputIt first, InputIt last);

	/* ================= Optional helpers (for tests) ================= */

	/*
		Return how many numbers are currently stored.
		Useful for debugging and tests.
	*/
	unsigned int	size() const;

	/*
		Return capacity (N).
	*/
	unsigned int	capacity() const;

	/* ================= Custom exceptions (cleaner than std::runtime_error strings) ================= */

	class FullSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#include "Span.tpp"

#endif

