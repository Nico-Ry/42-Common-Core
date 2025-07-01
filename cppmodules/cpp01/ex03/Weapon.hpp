/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:32:38 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:32:38 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon( std::string type);
		~Weapon( void );

		const std::string&  getType( void ) const;
		void                setType( std::string type);
};

#endif
