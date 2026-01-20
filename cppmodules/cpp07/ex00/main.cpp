/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:46:11 by nryser            #+#    #+#             */
/*   Updated: 2026/01/20 11:49:18 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main( void ) {
	int a = 3;
	int b = 2;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// ------------------------------------------------------------
	// EXTRA TEST: equality case must return the SECOND argument
	// (We test identity by comparing addresses of references)
	// ------------------------------------------------------------

	std::cout << "\n=== Equality tests (must return SECOND) ===\n";

	// int equality test
	int e = 10;
	int f = 10;

	int const& minEF = ::min(e, f);
	int const& maxEF = ::max(e, f);

	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) value = " << minEF << std::endl;
	std::cout << "max(e, f) value = " << maxEF << std::endl;

	std::cout << "&e = " << &e << ", &f = " << &f << std::endl;
	std::cout << "&min(e,f) = " << &minEF << " (should equal &f)\n";
	std::cout << "&max(e,f) = " << &maxEF << " (should equal &f)\n";

	if (&minEF == &f)
		std::cout << "[OK] min(e,f) returns SECOND when equal\n";
	else
		std::cout << "[FAIL] min(e,f) did NOT return SECOND when equal\n";

	if (&maxEF == &f)
		std::cout << "[OK] max(e,f) returns SECOND when equal\n";
	else
		std::cout << "[FAIL] max(e,f) did NOT return SECOND when equal\n";

	// std::string equality test
	std::string g = "same";
	std::string h = "same";

	std::string const& minGH = ::min(g, h);
	std::string const& maxGH = ::max(g, h);

	std::cout << "\ng = \"" << g << "\", h = \"" << h << "\"\n";
	std::cout << "&g = " << &g << ", &h = " << &h << std::endl;
	std::cout << "&min(g,h) = " << &minGH << " (should equal &h)\n";
	std::cout << "&max(g,h) = " << &maxGH << " (should equal &h)\n";

	if (&minGH == &h)
		std::cout << "[OK] min(g,h) returns SECOND when equal\n";
	else
		std::cout << "[FAIL] min(g,h) did NOT return SECOND when equal\n";

	if (&maxGH == &h)
		std::cout << "[OK] max(g,h) returns SECOND when equal\n";
	else
		std::cout << "[FAIL] max(g,h) did NOT return SECOND when equal\n";

	return (0);
}

