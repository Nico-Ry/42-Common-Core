/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:27:43 by nryser            #+#    #+#             */
/*   Updated: 2026/01/20 18:30:44 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	/* ================= VECTOR TEST ================= */

	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "[vector] Found value: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[vector] " << e.what() << std::endl;
	}

	/* ================= LIST TEST ================= */

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	try
	{
		std::list<int>::iterator it = easyfind(l, 4);
		std::cout << "[list] Found value: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[list] " << e.what() << std::endl;
	}

	/* ================= DEQUE TEST ================= */

	std::deque<int> d;
	d.push_back(42);
	d.push_back(84);

	try
	{
		std::deque<int>::iterator it = easyfind(d, 42);
		std::cout << "[deque] Found value: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[deque] " << e.what() << std::endl;
	}

	return 0;
}
