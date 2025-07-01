/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:11:45 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:11:45 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& original) : Animal(original) {
	brain = new Brain(*original.brain);
}

Dog& Dog::operator=(const Dog& original) {
	if (this != &original) {
		Animal::operator=(original);
		delete this->brain;
		this->brain = new Brain(*original.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

const Brain& Dog::getBrain() const {
	return *brain;
}

void Dog::makeSound() const{
	std::cout << "Guau guau guau ..." << std::endl;
}
