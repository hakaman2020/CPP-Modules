#include <iostream>
#include "contact.hpp"

Contact::Contact(void):	_firstName(""),
						_lastName(""),
						_nickname(""),
						_phoneNumber(""),
						_darkestSecret(""){
	return;
}

Contact::Contact(	std::string firstName,
					std::string lastName,
					std::string nickname,
					std::string phoneNumber,
					std::string darkestSecret):
					_firstName(firstName),
					_lastName(lastName),
					_nickname(nickname),
					_phoneNumber(phoneNumber),
					_darkestSecret(darkestSecret){
	return;
}

Contact::~Contact(void){
	return;
}

std::string	Contact::getFirstName ( void ) const{
	return this->_firstName;
}

std::string Contact::getLastName ( void ) const{
	return this->_lastName;
}

std::string Contact::getNickname ( void ) const{
	return this->_nickname;
}

std::string Contact::getPhoneNumber ( void ) const{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret ( void ) const{
	return this->_darkestSecret;
}

void Contact::setFirstName(std::string firstName){
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName){
	this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname){
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber){
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret){
	this->_darkestSecret = darkestSecret;
}

void Contact::copyContact(Contact& contact){
	this->_firstName = contact.getFirstName();
	this->_lastName = contact.getLastName();
	this->_nickname = contact.getNickname();
	this->_phoneNumber = contact.getPhoneNumber();
	this->_darkestSecret = contact.getDarkestSecret();
}