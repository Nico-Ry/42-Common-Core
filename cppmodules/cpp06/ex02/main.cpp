/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:33:45 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Functions.hpp"

int main() {
	std::cout << "===== ex02 demo =====" << std::endl;

	for (int i = 0; i < 5; ++i) {
		Base* p = generate();

		std::cout << "\nIteration " << i << std::endl;
		std::cout << "Base* address: " << p << std::endl;

		std::cout << "identify(Base*): ";
		identify(p);

		std::cout << "identify(Base&): ";
		identify(*p);

		delete p;
	}

	return 0;
}
