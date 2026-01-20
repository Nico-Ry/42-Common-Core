/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:06:24 by nryser            #+#    #+#             */
/*   Updated: 2026/01/20 12:06:24 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

/*
	iter applies a function to each element of an array.

	Key const rules:
	- Non-const array (T*) can be passed to functions that take T& (modifiable).
	- Const array (T const*) must be passed to functions that take T const& (read-only).
	- We implement 2 overloads to support both safely.
*/

template <typename T>
void iter(T* array, unsigned int len, void (*f)(T&)) {
	unsigned int i = 0;
	while (i < len) {
		f(array[i]);
		++i;
	}
}

template <typename T>
void iter(T const* array, unsigned int len, void (*f)(T const&)) {
	unsigned int i = 0;
	while (i < len) {
		f(array[i]);
		++i;
	}
}

#endif
