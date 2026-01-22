/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:49:25 by nryser            #+#    #+#             */
/*   Updated: 2026/01/21 13:49:25 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */



#include "Span.hpp"

/* ================= Orthodox Canonical Form ================= */

Span::Span() : _n(0), _storage()
{
}

// Main constructor (required)
Span::Span(unsigned int n) : _n(n), _storage()
{
	// Optional micro-optimization: reserve capacity for fewer reallocations.
	// (reserve exists in C++98 and does not change vector size)
	_storage.reserve(_n);
}

// Copy constructor
Span::Span(const Span& other) : _n(other._n), _storage(other._storage)
{
}

// Copy assignment operator
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		_storage = other._storage;
	}
	return *this;
}

// Destructor...Nothing to delete manually. std::vector manages its memory automatically (RAII).
Span::~Span()
{
}

/* ================= Core API ================= */

void Span::addNumber(int value)
{
	// Capacity rule: cannot store more than _n elements.
	if (_storage.size() >= _n)
		throw FullSpanException();

	_storage.push_back(value);
}

int Span::shortestSpan() const
{
	// Need at least 2 numbers to define a span.
	if (_storage.size() < 2)
		throw NotEnoughNumbersException();

	/*
		Key idea:
		- I do NOT want to sort the original storage (it’s the user’s data).
		- I make a copy, sort it, then compute adjacent differences.
	*/
	std::vector<int> sorted(_storage);
	std::sort(sorted.begin(), sorted.end());

	/*
		After sorting:
		- The shortest span MUST be between 2 adjacent elements.
	*/
	long long best = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
	if (best < 0)
		best = -best;

	for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
	{
		long long diff = static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1]);
		if (diff < 0)
			diff = -diff;

		if (diff < best)
			best = diff;
	}

	// Subject expects an int. In normal project ranges this fits.
	return static_cast<int>(best);
}

int Span::longestSpan() const
{
	if (_storage.size() < 2)
		throw NotEnoughNumbersException();

	/*
		Longest span is simply:
		max_element - min_element
	*/
	std::vector<int>::const_iterator minIt = std::min_element(_storage.begin(), _storage.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_storage.begin(), _storage.end());

	long long diff = static_cast<long long>(*maxIt) - static_cast<long long>(*minIt);
	if (diff < 0)
		diff = -diff;

	return static_cast<int>(diff);
}

/* ================= Optional helpers  ================= */
/*	clean and encapsulated way to expose state without leaking implementation details.
	They allow external code to query the object safely while
	preserving invariants and future flexibility*/

unsigned int Span::size() const
{
	return static_cast<unsigned int>(_storage.size());
}

unsigned int Span::capacity() const
{
	return _n;
}

/* ================= Exceptions ================= */

const char* Span::FullSpanException::what() const throw()
{
	return ("Span is full: cannot add more numbers");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers stored: need at least 2 to compute a span");
}

