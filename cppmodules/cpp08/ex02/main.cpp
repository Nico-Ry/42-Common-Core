/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:59:07 by nryser            #+#    #+#             */
/*   Updated: 2026/01/21 13:05:10 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

/* ================= ANSI COLORS ================= */

#define C_RESET  "\033[0m"
#define C_BOLD   "\033[1m"
#define C_RED    "\033[31m"
#define C_GREEN  "\033[32m"
#define C_YELLOW "\033[33m"
#define C_BLUE   "\033[34m"
#define C_CYAN   "\033[36m"

/* ================= Small helpers ================= */

static void header(const std::string& title)
{
	std::cout << "\n" << C_BOLD << C_BLUE << "===== " << title << " =====" << C_RESET << std::endl;
}

static void subheader(const std::string& title)
{
	std::cout << C_BOLD << C_CYAN << "\n--- " << title << " ---" << C_RESET << std::endl;
}

static void info(const std::string& label, int value)
{
	std::cout << C_YELLOW << label << C_RESET << value << std::endl;
}

/* ================= Subject test for MutantStack ================= */

static void run_subject_mutantstack()
{
	header("Subject test - MutantStack");

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	info("top(): ", mstack.top());
	mstack.pop();
	info("size() after pop: ", static_cast<int>(mstack.size()));
	info("new top() after pop is: ", mstack.top());

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	subheader("Iterating (expected same output as std::list version)");
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Subject requires that this compiles:
	// constructing a std::stack from a MutantStack
	std::stack<int> s(mstack);
	(void)s;
}

/* ================= Subject comparison with std::list ================= */

static void run_subject_list()
{
	header("Subject test - std::list (comparison)");

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);

	info("back(): ", lst.back());
	lst.pop_back();
	info("size() after pop_back: ", static_cast<int>(lst.size()));
	info("new back() after pop_back is: ", lst.back());

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;

	subheader("Iterating (should match MutantStack output)");
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

/* ================= Extra tests  ================= */

static void run_extra_iterator_tests()
{
	header("Extra tests - iterators (reverse / const)");

	MutantStack<int> m;
	m.push(10);
	m.push(20);
	m.push(30);
	m.push(40);

	subheader("Forward iteration (iterator)");
	for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << *it << std::endl;

	subheader("Reverse iteration (reverse_iterator)");
	for (MutantStack<int>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
		std::cout << *it << std::endl;

	const MutantStack<int> cm = m;

	subheader("Forward iteration (const_iterator)");
	for (MutantStack<int>::const_iterator it = cm.begin(); it != cm.end(); ++it)
		std::cout << *it << std::endl;

	subheader("Reverse iteration (const_reverse_iterator)");
	for (MutantStack<int>::const_reverse_iterator it = cm.rbegin(); it != cm.rend(); ++it)
		std::cout << *it << std::endl;
}

int main()
{
	run_subject_mutantstack();
	run_subject_list();
	run_extra_iterator_tests();

	std::cout << "\n" << C_BOLD << C_GREEN << "All MutantStack tests finished." << C_RESET << std::endl;
	return 0;
}
