/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:59 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:54:04 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract = 8;

Fixed::Fixed(void)
{
	_value = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	_value = copy.getRawBits();
}

Fixed::Fixed(const int number)
{
	_value = number * (1 << _fract);
}

Fixed::Fixed(const float number)
{
	_value = roundf(number * (1 << _fract));
}

Fixed& Fixed::operator=(const Fixed& original)
{
	this->setRawBits(original.getRawBits());
	return *this;
}

bool Fixed::operator>(const Fixed& number)
{
	return _value > number.getRawBits();
}

bool Fixed::operator<(const Fixed& number)
{
	return _value < number.getRawBits();
}

bool Fixed::operator>=(const Fixed& number)
{
	return _value >= number.getRawBits();
}

bool Fixed::operator<=(const Fixed& number)
{
	return _value <= number.getRawBits();
}

bool Fixed::operator==(const Fixed& number)
{
	return _value == number.getRawBits();
}

bool Fixed::operator!=(const Fixed& number)
{
	return _value != number.getRawBits();
}

Fixed Fixed::operator+(const Fixed& number)
{
	return Fixed(toFloat() + number.toFloat());
}

Fixed Fixed::operator-(const Fixed& number)
{
	return Fixed(toFloat() - number.toFloat());
}

Fixed Fixed::operator*(const Fixed& number)
{
	return Fixed(toFloat() * number.toFloat());
}

Fixed Fixed::operator/(const Fixed& number)
{
	return Fixed(toFloat() / number.toFloat());
}

Fixed& Fixed::operator++(void)
{
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(_value * toFloat());
	_value += 1;
	return tmp;
}

Fixed& Fixed::operator--(void)
{
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(_value * toFloat());
	_value -= 1;
	return tmp;
}

Fixed::~Fixed(void) {}

int    Fixed::getRawBits(void) const
{
	return (_value);
}

void    Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float   Fixed::toFloat(void) const
{
	return (float)_value / (float)(1 << _fract);
}

int     Fixed::toInt(void) const
{
	return _value >> _fract;
}

Fixed&  Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return n1;
	return n2;
}

const Fixed&  Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return n1;
	return n2;
}

Fixed&  Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return n1;
	return n2;
}

const Fixed&  Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return n1;
	return n2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
	os << number.toFloat();
	return os;
}
