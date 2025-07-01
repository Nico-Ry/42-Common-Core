/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/07/2025 15:51:47 by nryser            #+#    #+#             */
/*   Updated: 01/07/2025 15:54:46 by nryser           ###   ########.ch       */
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
		bool operator>(const Fixed& number);
		bool operator<(const Fixed& number);
		bool operator>=(const Fixed& number);
		bool operator<=(const Fixed& number);
		bool operator==(const Fixed& number);
		bool operator!=(const Fixed& number);
		Fixed operator+(const Fixed& number);
		Fixed operator-(const Fixed& number);
		Fixed operator*(const Fixed& number);
		Fixed operator/(const Fixed& number);
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);


		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;
		static Fixed&  min(Fixed& n1, Fixed& n2);
		static const Fixed&  min(const Fixed& n1, const Fixed& n2);
		static Fixed&  max(Fixed& n1, Fixed& n2);
		static const Fixed&  max(const Fixed& n1, const Fixed& n2);

};

std::ostream &operator<<(std::ostream &os, const Fixed &number);

#endif
