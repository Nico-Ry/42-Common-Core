/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:28:02 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:28:02 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int     N = 5;
	Zombie  *horde = zombieHorde(N, "Enrique");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}
