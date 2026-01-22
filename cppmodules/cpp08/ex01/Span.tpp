/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:18:41 by nryser            #+#    #+#             */
/*   Updated: 2026/01/21 13:18:50 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

/*
	addNumber(first, last)

	It support even "input iterators" safely by:
	1) copying the range into a temporary vector
	2) checking capacity once
	3) inserting all at the end

	This avoids problems where std::distance would consume single-pass iterators.
*/
template <typename InputIt>
void Span::addNumber(InputIt first, InputIt last)
{
	std::vector<int> tmp;

	for (; first != last; ++first)
		tmp.push_back(*first);

	if (_storage.size() + tmp.size() > _n)
		throw FullSpanException();

	_storage.insert(_storage.end(), tmp.begin(), tmp.end());
}

#endif
