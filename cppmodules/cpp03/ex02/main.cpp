/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:00:46 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:00:46 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("Jose");

	a.takeDamage(5);
	a.beRepaired(1);
	a.attack("Juan");
	a.beRepaired(3);
	a.takeDamage(15);
	a.highFivesGuys();

	return (0);
}
