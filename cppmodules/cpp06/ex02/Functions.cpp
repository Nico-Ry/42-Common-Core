/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:31:18 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>   // std::cout
#include <cstdlib>    // std::rand, std::srand
#include <ctime>      // std::time
#include <exception>  // std::bad_cast

/*
	Exercise 02: Identify real type

	- generate() creates a random instance of A, B, or C and returns it as Base*.
	- identify(Base*) prints the dynamic type using dynamic_cast (NULL on failure).
	- identify(Base&) prints the dynamic type using dynamic_cast (throws on failure).

	NOTE: std::typeinfo / typeid are forbidden by the subject.
*/

Base* generate(void) {
	// Seed once. If we seed every call with time(0), multiple calls inside the same
	// second can produce the same result.
	static bool seeded = false;
	if (!seeded) {
		// Mix wall-clock and CPU-clock to avoid repeated seeds when launching multiple
		// runs inside the same second.
		std::srand(static_cast<unsigned int>(std::time(0) ^ std::clock()));
		seeded = true;
	}

	const int r = std::rand() % 3;
	// Return a new derived instance as Base* (polymorphism).
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

void identify(Base* p) {
	// Pointer dynamic_cast:
	// - returns NULL if cast fails
	// - never throws = check-based
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;// defensive, should not happen here
}

void identify(Base& p) {
	// Pointer usage is forbidden in this overload by the subject.
	// Reference dynamic_cast:
	// - returns a reference if success
	// - throws std::bad_cast if it fails =exception-based
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception& e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception& e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception& e) {
		(void)e;
	}

	std::cout << "Unknown" << std::endl;
}

// runtime type information (RTTI)
