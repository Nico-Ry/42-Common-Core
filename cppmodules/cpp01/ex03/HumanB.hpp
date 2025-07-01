/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:31:53 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:31:58 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon      *_weapon;
		std::string _name;

	public:
		HumanB( std::string name );
		~HumanB( void );

		void    setWeapon( Weapon& weapon);
		void    attack( void );
};

#endif
