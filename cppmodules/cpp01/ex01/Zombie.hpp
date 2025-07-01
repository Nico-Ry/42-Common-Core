/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:28:50 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:28:50 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void    setName( std::string name);

		void    announce( void );
};

//zombieHorde.cpp//
Zombie* zombieHorde( int N, std::string name );

#endif
