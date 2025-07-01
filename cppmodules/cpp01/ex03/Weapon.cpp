/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:32:26 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:32:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type)
{
	this->_type = type;
}

Weapon::~Weapon( void ) {}

const std::string& Weapon::getType( void ) const
{
	return (_type);
}

void Weapon::setType( std::string type)
{
	this->_type = type;
}
