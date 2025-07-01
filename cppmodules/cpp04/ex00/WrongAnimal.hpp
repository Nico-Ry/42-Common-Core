/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:38 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:10:38 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string.h>
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal (const WrongAnimal& original);
		WrongAnimal& operator=(const WrongAnimal& original);
		virtual ~WrongAnimal();

		std::string getType() const;

		void makeSound() const;
};

#endif
