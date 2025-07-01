/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:52:25 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:52:25 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int                 _value;
		static const int    _fract;

	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& original);
		~Fixed(void);

		int     getRawBits(void) const;
		void    setRawBits(int const raw);
};

#endif
