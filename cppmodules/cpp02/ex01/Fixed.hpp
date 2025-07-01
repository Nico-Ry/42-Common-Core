/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/07/2025 15:51:25 by nryser            #+#    #+#             */
/*   Updated: 01/07/2025 15:53:26 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int                 _value;
		static const int    _fract;

	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed(const int number);
		Fixed(const float number);
		Fixed& operator=(const Fixed& original);
		~Fixed(void);

		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &number);

#endif
