/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:49:00 by nryser            #+#    #+#             */
/*   Updated: 2026/01/21 13:49:00 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>   // std::find
#include <stdexcept>   // std::runtime_error

/*
	EasyFind (ex00 - Module 08)

	Goal:
	- Generic function template that searches an int inside a container of ints.
	- Works with standard sequence containers (vector, list, deque, ...).
	- Returns an iterator to the first occurrence.
	- If not found, throws an exception.

	Key concepts:
	- Template: works for many container types T.
	- Iterator: "pointer-like" object used to traverse containers.
	- Algorithm: std::find does the search using iterators:
		std::find(begin, end, value) returns:
			- iterator to found element
			- end iterator if not found
*/

// Overload for NON-CONST containers: returns T::iterator
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	// T::iterator depends on template parameter T, so I must write "typename"
	// to tell the compiler: "this is a type".
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	// If std::find fails, it returns container.end()
	if (it == container.end())
		throw std::runtime_error("easyfind: value not found");

	return it;
}

// Overload for CONST containers: returns T::const_iterator
template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("easyfind: value not found");

	return it;
}

#endif
