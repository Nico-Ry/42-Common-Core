/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:13 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:10:13 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n-----WrongAnimal & WrongCat-----\n" << std::endl;

	const WrongAnimal*  wanimal = new WrongAnimal();
	const WrongAnimal*  wcat = new WrongCat();

	std::cout << wanimal->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;

	wanimal->makeSound();
	wcat->makeSound();

	delete wanimal;
	delete wcat;

	return (0);
}
