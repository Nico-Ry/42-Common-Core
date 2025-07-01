/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:12:46 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 16:12:46 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& original);
		Brain& operator=(const Brain& original);
		~Brain();

		const std::string(&getIdeas() const)[100];
};

#endif
