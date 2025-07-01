/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/07/2025 16:06:32 by nryser            #+#    #+#             */
/*   Updated: 01/07/2025 16:06:32 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain* brain;

	public:
		Cat();
		Cat(const Cat& original);
		Cat& operator=(const Cat& original);
		~Cat();

		const Brain& getBrain() const;
		void makeSound() const;
};

#endif
