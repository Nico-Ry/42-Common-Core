/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:32:11 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

// -----------------------------------------------------------------------------
// These are the private constructors/destructor.
// They exist only to satisfy canonical form in a C++98 way.
//
// (void)original is used to avoid "unused parameter" warnings, since the
// object can’t realistically be copied anyway.
// -----------------------------------------------------------------------------
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& original) { (void)original; }
Serializer& Serializer::operator=(const Serializer& original) { (void)original; return *this; }
Serializer::~Serializer() {}

// -----------------------------------------------------------------------------
// serialize(Data* ptr) -> uintptr_t
//
// What ptr is:
// - A pointer is an address in memory.
// - Example: ptr might equal 0x7ffee3b2a9c0.
//
// What uintptr_t is:
// - An unsigned integer type guaranteed to be able to store a pointer value.
// - It is specifically made for this kind of pointer-to-integer conversion.
//
// Why reinterpret_cast:
// - Because we do NOT want numeric conversion (like static_cast does).
// - We want to reinterpret the bits of the pointer as an integer.
// - This is exactly what reinterpret_cast is intended for.
//
// Important:
// - This does NOT copy the Data object.
// - It only converts the address itself into an integer.
// -----------------------------------------------------------------------------
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

// -----------------------------------------------------------------------------
// deserialize(uintptr_t raw) -> Data*
//
// raw is expected to be an integer that originally came from serialize(ptr).
//
// Why reinterpret_cast again:
// - We're doing the inverse operation: integer bits -> pointer bits.
// - No transformation of content, only reinterpretation.
//
// Result:
// - If raw came from serialize(ptr), then the returned Data* points to the
//   exact same memory location as ptr.
//
// Warning / safety note:
// - If raw is NOT from serialize, the pointer could be invalid.
// - Dereferencing an invalid pointer is undefined behavior.
// - For the exercise, you only test round-trip from serialize.
// -----------------------------------------------------------------------------
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
