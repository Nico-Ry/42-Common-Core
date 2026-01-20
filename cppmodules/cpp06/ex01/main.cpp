/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:32:04 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

#include <iostream>
#include <iomanip>   // std::hex, std::dec
#include <string>
#include <stdint.h>  // uintptr_t


static void printData(const Data& d) {
	std::cout << "Data contents:" << std::endl;
	std::cout << "  id    = " << d.id << std::endl;
	std::cout << "  value = " << d.value << std::endl;
	std::cout << "  name  = " << d.name << std::endl;
}

int main() {
	//private constructors so these lines would cause compilation errors
	// Serializer s;
	// new Serializer(s);
	// Serializer a(b);
	// a = b;

	// 1) Create a real Data object with real members (non-empty struct required)
	Data data;
	data.id = 42;
	data.value = 3.14159f;
	data.name = "hello_ex01";

	std::cout << "===== ex01: Serializer demo =====" << std::endl;
	printData(data);
	std::cout << std::endl;

	// 2) Take its address (pointer)
	Data* originalPtr = &data;

	std::cout << "Original pointer (Data*): " << originalPtr << std::endl;

	// 3) Serialize pointer -> integer
	uintptr_t raw = Serializer::serialize(originalPtr);

	std::cout << "Serialized (uintptr_t):" << std::endl;
	std::cout << "  dec: " << raw << std::endl;
	std::cout << "  hex: 0x" << std::hex << raw << std::dec << std::endl;


	// 4) Deserialize integer -> pointer
	Data* deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Deserialized pointer (Data*): " << deserializedPtr << std::endl;
	std::cout << std::endl;

	// 5) Prove equality: same address
	if (deserializedPtr == originalPtr) {
		std::cout << "[OK] Pointers are equal (round-trip succeeded)" << std::endl;
	} else {
		std::cout << "[FAIL] Pointers are NOT equal" << std::endl;
	}

	// 6) Prove usability: reading through the deserialized pointer
	std::cout << std::endl;
	std::cout << "Reading through deserialized pointer:" << std::endl;
	std::cout << "  id    = " << deserializedPtr->id << std::endl;
	std::cout << "  value = " << deserializedPtr->value << std::endl;
	std::cout << "  name  = " << deserializedPtr->name << std::endl;

	return 0;
}


// int main() {
// 	Data* data = new Data;
// 	data->id = 42;
// 	data->value = 3.14f;
// 	data->name = "heap_case";

// 	uintptr_t raw = Serializer::serialize(data);

// 	// Delete the original object
// 	delete data;

// 	// Deserialize AFTER delete
// 	Data* deserializedPtr = Serializer::deserialize(raw);

// 	// ❌ UNDEFINED BEHAVIOR (comment/uncomment this)
// 	// std::cout << deserializedPtr->id << std::endl;

// 	return 0;
// }

// int main() {
// 	Data data;
// 	data.name = "Kerry Caverga";
// 	data.age = 42;
// 	data.city = "Albacete";

// 	uintptr_t serialized = Serializer::serialize(&data);
// 	Data* deserialized = Serializer::deserialize(serialized);

// 	std::cout << "Name: " << deserialized->name << std::endl;
// 	std::cout << "Age: " << deserialized->age << std::endl;
// 	std::cout << "City: " << deserialized->city << std::endl;

// 	return 0;
// }
