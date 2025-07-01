/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:27 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:10:33 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& original) : type(original.getType()) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original) {
	if (this != &original) {
		this -> type = original.getType();
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this -> type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Some generic WrongAnimal sound ..." << std::endl;
}
