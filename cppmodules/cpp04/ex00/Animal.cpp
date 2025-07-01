/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:09:30 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:09:30 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal& original) : type(original.getType()) {}

Animal& Animal::operator=(const Animal& original) {
	if (this != &original) {
		this -> type = original.getType();
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this -> type;
}

void Animal::makeSound() const {
	std::cout << "Some generic Animal sound ..." << std::endl;
}
