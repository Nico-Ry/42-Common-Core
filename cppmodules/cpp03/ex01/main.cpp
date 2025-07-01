/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:58:33 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:58:33 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("Jose");

	a.takeDamage(5);
	a.beRepaired(1);
	a.attack("Juan");
	a.beRepaired(3);
	a.takeDamage(15);
	a.guardGate();

	return (0);
}
