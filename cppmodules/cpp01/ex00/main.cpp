/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/07/2025 15:24:36 by nryser            #+#    #+#             */
/*   Updated: 01/07/2025 15:25:54 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie1("Juan");
	Zombie zombie2("Alberto");
	Zombie *zombie3;

	std::cout << "--Stack memory zombies--" << std::endl;
	zombie1.announce();
	zombie2.announce();

	std::cout << "--Heap memory zombies--" << std::endl;
	zombie3 = newZombie("Jose Andres");
	zombie3->announce();
	delete zombie3;

	randomChump("Fernando");

	std::cout << "--Program finishes--" << std::endl;
	return (0);
}
