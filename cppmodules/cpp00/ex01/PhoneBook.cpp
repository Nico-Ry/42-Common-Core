#include "PhoneBook.hpp"
#include "iomanip"

PhoneBook::PhoneBook() {};


void PhoneBook::addContact() {
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "Enter name: ";
	if (!(std::cin >> name))
		return;
	std::cout << "Enter last name: ";
	if (!(std::cin >> lastName))
		return;
	std::cout << "Enter nickname: ";
	if (!(std::cin >> nickname))
		return;
	std::cout << "Enter phone number: ";
	if (!(std::cin >> phoneNumber))
		return;
	std::cout << "Enter darkest secret: ";
	if (!(std::getline(std::cin >> std::ws, darkestSecret)))
		return;

	if (list[7].getName() == "") {
		for(int i = 0; i < 8; i++) {
			if (list[i].getName() == "") {
				list[i].setName(name);
				list[i].setLastName(lastName);
				list[i].setNickname(nickname);
				list[i].setPhoneNumber(phoneNumber);
				list[i].setDarkestSecret(darkestSecret);
				std::cout << GREEN << "Contact added" << RESET << std::endl;
				return;
			}
		}
	} else {
		addFull(name, lastName, nickname, phoneNumber, darkestSecret);
		std::cout << GREEN << "Contact added" << RESET << std::endl;
	}
}

void PhoneBook::addFull(std::string name, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	for (int i = 0; i < 7; i++) {
		list[i].setName(list[i + 1].getName());
		list[i].setLastName(list[i + 1].getLastName());
		list[i].setNickname(list[i + 1].getNickname());
		list[i].setPhoneNumber(list[i + 1].getPhoneNumber());
		list[i].setDarkestSecret(list[i + 1].getDarkestSecret());
	}
	list[7].setName(name);
	list[7].setLastName(lastName);
	list[7].setNickname(nickname);
	list[7].setPhoneNumber(phoneNumber);
	list[7].setDarkestSecret(darkestSecret);
}

void PhoneBook::searchContact() {
	std::string name;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string input;
	int index;

	if (list[0].getName() == "") {
		std::cout << RED << "No contacts available" << RESET << std::endl;
		return;
	}

	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < 8; i++) {
		if (list[i].getName() != "") {
			std::cout << "|" << std::setw(10) << i + 1 << "|";

			name = list[i].getName();
			if (name.length() > 10)
				name = name.substr(0, 9) + ".";
			std::cout << std::setw(10) << name << "|";

			lastName = list[i].getLastName();
			if (lastName.length() > 10)
				lastName = lastName.substr(0, 9) + ".";
			std::cout << std::setw(10) << lastName << "|";

			nickname = list[i].getNickname();
			if (nickname.length() > 10)
				nickname = nickname.substr(0, 9) + ".";
			std::cout << std::setw(10) << nickname << "|" << std::endl;

			std::cout << "|----------|----------|----------|----------|" << std::endl;
		}
	}

	std::cout << YELLOW << "--Select contact index or -1 to return to the menu--" << RESET << std::endl;
	std::cout << "Enter index: ";
	std::getline(std::cin >> std::ws, input);

	if (input == "-1")
		return;

	if (input.find_first_not_of("012345678") != std::string::npos) {
		std::cout << RED << "Invalid input. Please enter a number between 1 and 8." << RESET << std::endl;
		return;
	}

	index = std::stoi(input);

	if (index > 0 && index < 9 && list[index - 1].getName() != "") {
		std::cout << PURPLE << "CONTACT INFO:" << std::endl;
		std::cout << "First name: " << list[index - 1].getName() << std::endl;
		std::cout << "Last name: " << list[index - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << list[index - 1].getNickname() << std::endl;
		std::cout << "Phone number: " << list[index - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << list[index - 1].getDarkestSecret() << RESET << std::endl;
	} else {
		std::cout << RED << "Invalid index" << RESET << std::endl;
	}
}
