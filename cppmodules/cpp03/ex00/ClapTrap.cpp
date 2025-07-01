/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:51 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:56:51 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name)
{
	std::cout << "[" << _name << "]" << " I am alive :)" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& original): _name(original.getName())
{
	std::cout << "[" << _name << "]" << " I am alive by copy :)" << std::endl;
	_hitPoints = original.getHitPoints();
	_energyPoints = original.getEnergyPoints();
	_attackDamage = original.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original) {
	if (this != &original) {
		_hitPoints = original.getHitPoints();
		_energyPoints = original.getEnergyPoints();
		_attackDamage = original.getAttackDamage();
	}
	return *this;
};

ClapTrap::~ClapTrap() {std::cout << "[" << _name << "]" << " I am dead :(" << std::endl;}

const std::string& ClapTrap::getName() const {return _name;}

unsigned int ClapTrap::getHitPoints() const {return _hitPoints;}

unsigned int ClapTrap::getEnergyPoints() const {return _energyPoints;}

unsigned int ClapTrap::getAttackDamage() const {return _attackDamage;}

void    ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
		std::cout << YELLOW << "ClapTrap " << _name << " wants to attack " << target << " but it has 0 energy points !" << RESET << std::endl;
	else {
		_energyPoints--;
		std::cout << YELLOW << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage ! - [" << _hitPoints <<
			" HP, " << _energyPoints << " EP]" << RESET << std::endl;
	}
}


void    ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << RED << "ClapTrap " << _name << " takes " << amount <<
		" points of damage - [" << _hitPoints << " HP, " << _energyPoints << " EP]" << RESET << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
		std::cout << GREEN << "ClapTrap " << _name << " wants to be repaired but it has 0 energy points !" << RESET << std::endl;
	else {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << GREEN << "ClapTrap " << _name << " is repaired " << amount << " hit points - [" << _hitPoints <<
			" HP, " << _energyPoints << " EP]" << RESET << std::endl;
	}
}
