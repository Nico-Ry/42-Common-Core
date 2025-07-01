#include "Contact.hpp"

Contact::Contact() {};

void Contact::setName(std::string name) {
	this->name = name;
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string Contact::getName() {
	return (this->name);
}

std::string Contact::getLastName() {
	return (this->lastName);
}

std::string Contact::getNickname() {
	return (this->nickname);
}

std::string Contact::getPhoneNumber() {
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() {
	return (this->darkestSecret);
}
