/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:28:27 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:28:27 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie ( void ) {
	this->name = "Unnamed";
	std::cout << name << ": Im alive 😃" << std::endl;
}

Zombie::Zombie ( std::string name )
{
	this->name = name;
	std::cout << name << ": Im alive 😃" << std::endl;
}

Zombie::~Zombie ( void )
{
	std::cout << name << ": Im dead 💀" << std::endl;
}

void Zombie::setName( std::string name)
{
	this->name = name;
}

void Zombie::announce ( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
