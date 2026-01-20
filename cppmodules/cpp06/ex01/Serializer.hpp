/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:32:17 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

// struct Data {
// 	std::string name;
// 	int age;
// 	std::string city;
// };

struct Data {
	int			id;
	float		value;
	std::string	name;
};

class Serializer {
	public:
		/* ---------------------------------------------------------------------
			serialize:
			Takes a pointer to Data (memory address) and converts it into
			an integer type (uintptr_t) that can store that address.

			This is a "raw" reinterpretation of bits: no actual conversion
			of the object content happens.
		-------------------------------------------------------------------------*/
		static uintptr_t serialize(Data* ptr);

		/* ---------------------------------------------------------------------
			deserialize:
			Takes the integer produced by serialize and converts it back
			into a Data* pointer.

			If the raw value originally came from serialize(ptr),
			then deserialize(raw) should equal ptr.
		-------------------------------------------------------------------------*/
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer& original);
		Serializer& operator=(const Serializer& original);
		~Serializer();
};

#endif
