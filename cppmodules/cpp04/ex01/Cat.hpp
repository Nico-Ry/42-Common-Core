/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:11:39 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:11:39 by nryser           ###   ########.ch       */
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
