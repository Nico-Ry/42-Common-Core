/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:11:56 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:11:56 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	Animal* animals[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}

	std::cout << "\n------Deep copy check------\n" << std::endl;

	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat(*cat1);

	std::cout << &cat1->getBrain() << std::endl;
	std::cout << &cat2->getBrain() << std::endl;

	delete cat1;
	delete cat2;

	return (0);
}
