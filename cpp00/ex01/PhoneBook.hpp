#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact list[8];

		void addFull(std::string name, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);

	public:
		PhoneBook();
		void addContact();
		void searchContact();
};

#endif
