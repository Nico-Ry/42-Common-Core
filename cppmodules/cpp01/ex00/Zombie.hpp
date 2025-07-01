/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:26:46 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:26:51 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		Zombie( std::string name );
		~Zombie( void );

		void announce( void );
};

//newZombie.cpp//
Zombie* newZombie( std::string name );

//randomChump.cpp//
void randomChump( std::string name );

#endif
