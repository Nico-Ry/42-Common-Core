/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:32:47 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

// Exercise 02 only needs a polymorphic base class.
// A single virtual destructor is enough to enable RTTI for dynamic_cast.

class Base {
	public:
		virtual ~Base();
};

#endif
