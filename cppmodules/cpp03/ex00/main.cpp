/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:57:09 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:57:09 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Jose");

	a.takeDamage(5);
	a.beRepaired(1);
	a.attack("Juan");
	a.beRepaired(3);
	a.takeDamage(15);

	return (0);
}
