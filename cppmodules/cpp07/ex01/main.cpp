/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:09:50 by nryser            #+#    #+#             */
/*   Updated: 2026/01/20 12:16:34 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"
#include <iostream>

// template <typename T>
// void printElement(T const &element) {
// 	std::cout << element << " ";
// }

// void increment(int &n) {
// 	n++;
// }

// int main() {
// 	int arr[] = {1, 2, 3, 4, 5};
// 	size_t len = sizeof(arr) / sizeof(arr[0]);

// 	std::cout << "Original Array: ";
// 	::iter(arr, len, printElement<int>);
// 	std::cout << std::endl;

// 	std::cout << "Incrementing Elements..." << std::endl;
// 	::iter(arr, len, increment);

// 	std::cout << "Modified Array: ";
// 	::iter(arr, len, printElement<int>);
// 	std::cout << std::endl;

// 	std::cout << "Example With Strings:" << std::endl;
// 	std::string strArr[] = {"Jamon", "Salchichon", "Fuet"};
// 	::iter(strArr, 3, printElement<std::string>);
// 	std::cout << std::endl;

// 	return 0;
// }


#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int const& x) {
	std::cout << x << std::endl;
}

void add1(int& x) {
	x += 1;
}

void printString(std::string const& s) {
	std::cout << s << std::endl;
}

void addExclamation(std::string& s) {
	s += "!";
}

int main() {
	std::cout << "=== int array (modifiable) ===" << std::endl;
	int arr[] = {1, 2, 3};
	iter(arr, 3, &printInt);
	std::cout << "--- Adding 1 to each element ---" << std::endl;
	iter(arr, 3, &add1);
	iter(arr, 3, &printInt);

	std::cout << "\n=== const int array (read-only) ===" << std::endl;
	int const carr[] = {10, 20, 30};
	iter(carr, 3, &printInt);

	// This MUST NOT compile (correct behavior). Uncomment to verify.
	// iter(carr, 3, &add1);

	std::cout << "\n=== string array (modifiable) ===" << std::endl;
	std::string sarr[] = {"hi", "42", "cpp"};
	iter(sarr, 3, &printString);
	iter(sarr, 3, &addExclamation);
	std::cout << "--- After adding exclamation ---" << std::endl;
	iter(sarr, 3, &printString);

	return 0;
}
