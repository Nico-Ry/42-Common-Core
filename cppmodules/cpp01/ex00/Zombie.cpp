/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:26:37 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:26:41 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie ( std::string name )
{
	this->name = name;
	std::cout << name << ": Im alive 😃" << std::endl;
}

Zombie::~Zombie ( void )
{
	std::cout << name << ": Im dead 💀" << std::endl;
}

void Zombie::announce ( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
