/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:49:07 by nryser            #+#    #+#             */
/*   Updated: 2026/01/21 13:49:15 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

/* ================= ANSI COLORS (works in most terminals) ================= */

#define C_RESET  "\033[0m"
#define C_BOLD   "\033[1m"
#define C_RED    "\033[31m"
#define C_GREEN  "\033[32m"
#define C_YELLOW "\033[33m"
#define C_BLUE   "\033[34m"
#define C_CYAN   "\033[36m"

static void	printHeader(const std::string& title)
{
	std::cout << "\n" << C_BOLD << C_BLUE
			  << "===== " << title << " ====="
			  << C_RESET << std::endl;
}

static void	printPass(const std::string& msg)
{
	std::cout << C_GREEN << "[PASS] " << C_RESET << msg << std::endl;
}

static void	printFail(const std::string& msg)
{
	std::cout << C_RED << "[FAIL] " << C_RESET << msg << std::endl;
}

static void	printExpectedActual(int expected, int actual)
{
	std::cout << C_CYAN << "Expected: " << C_RESET << expected
			  << " | "
			  << C_CYAN << "Actual: " << C_RESET << actual
			  << std::endl;
}

/* ================= TESTS ================= */

static void	testSubjectExample()
{
	printHeader("Test 1 - Subject example (deterministic)");

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	int shortest = sp.shortestSpan();
	int longest  = sp.longestSpan();

	// From subject: shortest = 2, longest = 14
	printExpectedActual(2, shortest);
	printExpectedActual(14, longest);

	if (shortest == 2)
		printPass("shortestSpan() matches subject output");
	else
		printFail("shortestSpan() does NOT match subject output");

	if (longest == 14)
		printPass("longestSpan() matches subject output");
	else
		printFail("longestSpan() does NOT match subject output");
}

static void	testFullException()
{
	printHeader("Test 2 - FullSpanException (adding past capacity)");

	Span sp(5);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(5);

	try
	{
		std::cout << C_YELLOW << "Action: addNumber(42) when already full" << C_RESET << std::endl;
		sp.addNumber(42);
		printFail("No exception thrown (this is wrong)");
	}
	catch (const std::exception& e)
	{
		printPass(std::string("Exception thrown as expected: ") + e.what());
	}
}

static void	testNotEnoughNumbersException()
{
	printHeader("Test 3 - NotEnoughNumbersException (size < 2)");

	Span sp(2);
	sp.addNumber(5);

	try
	{
		std::cout << C_YELLOW << "Action: shortestSpan() with only 1 element" << C_RESET << std::endl;
		(void)sp.shortestSpan();
		printFail("No exception thrown (this is wrong)");
	}
	catch (const std::exception& e)
	{
		printPass(std::string("Exception thrown as expected: ") + e.what());
	}

	try
	{
		std::cout << C_YELLOW << "Action: longestSpan() with only 1 element" << C_RESET << std::endl;
		(void)sp.longestSpan();
		printFail("No exception thrown (this is wrong)");
	}
	catch (const std::exception& e)
	{
		printPass(std::string("Exception thrown as expected: ") + e.what());
	}
}

static void	testIteratorRangeAdd()
{
	printHeader("Test 4 - Iterator range insertion (addNumber(begin, end))");

	Span sp(10);

	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i * 3); // 0, 3, 6, 9, ..., 27

	// Expected:
	// shortest span = 3 (adjacent difference)
	// longest span  = 27 (27 - 0)
	sp.addNumber(v.begin(), v.end());

	int shortest = sp.shortestSpan();
	int longest  = sp.longestSpan();

	printExpectedActual(3, shortest);
	printExpectedActual(27, longest);

	if (shortest == 3)
		printPass("shortestSpan() correct for range insertion");
	else
		printFail("shortestSpan() incorrect for range insertion");

	if (longest == 27)
		printPass("longestSpan() correct for range insertion");
	else
		printFail("longestSpan() incorrect for range insertion");
}

static void	testBigRandom()
{
	printHeader("Test 5 - 10,000 random numbers (stress test)");

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	const int N = 10000;
	Span bigSpan(N);

	for (int i = 0; i < N; ++i)
		bigSpan.addNumber(std::rand());

	/*
		I don't have deterministic expected values here because rand() changes.
		This test is mainly about:
		- performance
		- no crashes
		- correct exceptions not triggered
	*/
	int shortest = bigSpan.shortestSpan();
	int longest  = bigSpan.longestSpan();

	std::cout << C_CYAN << "Result shortestSpan(): " << C_RESET << shortest << std::endl;
	std::cout << C_CYAN << "Result longestSpan():  " << C_RESET << longest << std::endl;

	// Basic sanity checks
	if (shortest >= 0)
		printPass("shortestSpan() returned a non-negative value");
	else
		printFail("shortestSpan() returned a negative value (unexpected)");

	if (longest >= 0)
		printPass("longestSpan() returned a non-negative value");
	else
		printFail("longestSpan() returned a negative value (unexpected)");

	if (longest >= shortest)
		printPass("longestSpan() >= shortestSpan() (sanity check)");
	else
		printFail("longestSpan() < shortestSpan() (sanity check failed)");
}

int main()
{
	try
	{
		testSubjectExample();
		testFullException();
		testNotEnoughNumbersException();
		testIteratorRangeAdd();
		testBigRandom();
	}
	catch (const std::exception& e)
	{
		// If something unexpected escapes a test, I catch it here.
		std::cerr << C_RED << "[UNEXPECTED EXCEPTION] " << C_RESET << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n" << C_BOLD << C_GREEN << "All tests finished." << C_RESET << std::endl;
	return 0;
}



//main from subject
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }

// $> ./ex01
// 2
// 14
// $>
