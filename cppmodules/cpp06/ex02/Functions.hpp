/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:33:04 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"

// Required by the subject (free functions):
// They operate on Base*, Base& but are not members of Base.
Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

#endif
