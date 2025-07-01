/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:47:53 by nryser            #+#    #+#             */
/*   Updated: 2025/07/01 15:47:53 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#define RESET   "\033[0m"
#define BLUE    "\033[94m"
#define GREEN   "\033[92m"
#define ORANGE  "\033[33m"
#define RED     "\033[91m"

#include <iostream>

class Harl {
	private:
		void    debug(void);
		void    info(void);
		void    warning(void);
		void    error(void);

	public:
		Harl();
		~Harl();
		void    complain(std::string level);
};

#endif
