/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:09:02 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:09:02 by nryser           ###   ########.ch       */
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

	//Animal animal;

	return (0);
}
