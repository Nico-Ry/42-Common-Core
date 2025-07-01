/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:13:16 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:13:16 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain* brain;

	public:
		Dog ();
		Dog (const Dog& original);
		Dog& operator=(const Dog& original);
		~Dog();

		const Brain& getBrain() const;
		void makeSound() const;
};

#endif
