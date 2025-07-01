/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:31:36 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:31:36 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon&     _weapon;
		std::string _name;

	public:
		HumanA( std::string name, Weapon& weapon);
		~HumanA( void );

		void    attack( void );
};

#endif
