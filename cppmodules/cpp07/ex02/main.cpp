/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:13:24 by nryser            #+#    #+#             */
/*   Updated: 2026/01/20 14:13:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Array.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"
#define ORANGE  "\033[38;5;214m"

static void printTitle(const std::string& title) {
	std::cout << ORANGE << "\n=== " << title << " ===" << RESET << std::endl;
}

static void printOk(const std::string& msg) {
	std::cout << GREEN << "[OK] " << RESET << msg << std::endl;
}

static void printFail(const std::string& msg) {
	std::cout << RED << "[FAIL] " << RESET << msg << std::endl;
}

int main() {
	try {
		/* =========================
		   1) Default constructor
		   ========================= */
		printTitle("Default constructor (empty)");
		Array<int> emptyArray;
		std::cout << "emptyArray.size() = " << emptyArray.size() << std::endl;
		if (emptyArray.size() == 0) printOk("Empty array size is 0");
		else printFail("Empty array size is not 0");

		/* =========================
		   2) Sized constructor + fill
		   ========================= */
		printTitle("Sized constructor + fill/read");
		Array<int> numbers(5);
		for (unsigned int i = 0; i < numbers.size(); ++i)
			numbers[i] = static_cast<int>(i) * 10;

		std::cout << "numbers = ";
		for (unsigned int i = 0; i < numbers.size(); ++i)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;
		printOk("Write/read with operator[] works");

		/* =========================
		   3) Copy constructor (deep copy)
		   ========================= */
		printTitle("Copy constructor deep copy");
		Array<int> copy(numbers);
		copy[0] = 999;

		std::cout << "numbers[0] = " << numbers[0] << std::endl;
		std::cout << "copy[0]    = " << copy[0] << std::endl;

		if (numbers[0] != copy[0]) printOk("Copy is independent (deep copy)");
		else printFail("Copy is NOT independent (shallow copy bug)");

		/* =========================
		   4) Copy assignment (deep copy)
		   ========================= */
		printTitle("Copy assignment deep copy");
		Array<int> assigned(2);
		assigned[0] = -1;
		assigned[1] = -2;

		assigned = numbers;      // assignment operator
		assigned[1] = 777;       // modify assigned only

		std::cout << "numbers[1]  = " << numbers[1] << std::endl;
		std::cout << "assigned[1] = " << assigned[1] << std::endl;

		if (numbers[1] != assigned[1]) printOk("Assignment is independent (deep copy)");
		else printFail("Assignment is NOT independent (shallow copy bug)");

		/* =========================
		5) Self-assignment
		========================= */
		printTitle("Self-assignment");

		// Save some data to verify it survives self-assignment
		int before0 = numbers[0];
		int before1 = numbers[1];

		// Create an alias so the compiler does not warn with -Werror
		Array<int>& ref = numbers;

		// Runtime self-assignment
		numbers = ref;

		// Verify content was not corrupted
		if (numbers[0] == before0 && numbers[1] == before1)
			printOk("Self-assignment preserved data (handled correctly)");
		else
			printFail("Self-assignment corrupted data (operator= bug)");

		/* =========================
		   6) Const correctness (const operator[])
		   ========================= */
		printTitle("Const correctness");
		Array<int> tmp(3);
		for (unsigned int i = 0; i < tmp.size(); ++i)
			tmp[i] = 100 + static_cast<int>(i);

		Array<int> const constArr(tmp); // const object
		std::cout << "constArr[0] = " << constArr[0] << std::endl;
		printOk("Reading from const Array works (const operator[])");

		// This should NOT compile (correct): uncomment to verify.
		// constArr[0] = 5;

		/* =========================
		   7) Out-of-bounds tests
		   ========================= */
		printTitle("Out of bounds (read)");
		try {
			std::cout << numbers[10] << std::endl;
			printFail("Out-of-bounds read did NOT throw");
		} catch (const std::exception& e) {
			printOk("Out-of-bounds read threw std::exception");
		}

		printTitle("Out of bounds (write)");
		try {
			numbers[10] = 42;
			printFail("Out-of-bounds write did NOT throw");
		} catch (const std::exception& e) {
			printOk("Out-of-bounds write threw std::exception");
		}

		/* =========================
		   8) Template works with another type
		   ========================= */
		printTitle("Template works with std::string");
		Array<std::string> words(3);
		words[0] = "hi";
		words[1] = "cpp";
		words[2] = "42";

		std::cout << "words = ";
		for (unsigned int i = 0; i < words.size(); ++i)
			std::cout << "\"" << words[i] << "\" ";
		std::cout << std::endl;
		printOk("Array<std::string> works");

		std::cout << PURPLE << "\nAll tests completed.\n" << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Unexpected exception: " << RESET << e.what() << std::endl;
	}

	return 0;
}
