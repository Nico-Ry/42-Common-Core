/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:08 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:53:13 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = copy.getRawBits();
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	_value = number * (1 << _fract);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(number * (1 << _fract));
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

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

std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
	os << number.toFloat();
	return os;
}
