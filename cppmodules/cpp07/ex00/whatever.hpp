/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:33:24 by nryser            #+#    #+#             */
/*   Updated: 2026/01/20 11:33:24 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*
	swap:
	- Uses T& because we NEED to modify the original variables.
	- Passing by reference avoids copies and allows real swapping.
*/
template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

/*
	min:
	- Parameters are const T& because:
		1) min must NOT modify its inputs (read-only operation)
		2) const references can bind to literals and temporaries (min(3, 5))
	- Returns const T& to:
		1) avoid copying
		2) prevent modification of the result (min(a, b) = x is forbidden)
	- If values are equal, returns the SECOND parameter (subject requirement)
*/
template <typename T>
T const& min(T const& a, T const& b) {
	return (a < b) ? a : b;
}

/*
	max:
	- Same const logic as min (read-only, safe, no copies)
	- Returns const T& to prevent accidental modification
	- If values are equal, returns the SECOND parameter (subject requirement)
*/
template <typename T>
T const& max(T const& a, T const& b) {
	return (a > b) ? a : b;
}

#endif
