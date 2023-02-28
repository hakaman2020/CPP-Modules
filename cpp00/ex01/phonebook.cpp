#include <iostream>
#include <iomanip>
#include "phonebook.hpp"


//initialize the phonebook
Phonebook::Phonebook(void){	
	return;
}

//destructor
Phonebook::~Phonebook(void){
	return;
}

//add start the process of adding a contact to the list
//if it was successfull it will return true
//else it will return false.
bool Phonebook::addContact(void){
	static int index = -1;
	Contact contact;

	if (createContact(contact)){
		index = (index + 1) % MAX_CONTACTLIST_SIZE;
		this->_book[index].copyContact(contact);
		return true;
	}
	else
		return (false);

}

//will return the contact information stored at the index of the list
Contact Phonebook::getContact(int index){
	return ((this->_book)[index]);
}

//will display the whole contactlist in small form
void Phonebook::displayContactList(void){
	this->displayHeader();
	for(int i = 0; i < MAX_CONTACTLIST_SIZE; ++i){
		this->displayOneContact((this->_book)[i], i + 1);
	}
	return;	
}

//this will display all the values of all the fieldnames of a contact
void Phonebook::displayFullContact(const Contact& contact){
	std::cout	<< "\nContact information:\n" 
				<< "First name: " << contact.getFirstName() << "\n"
				<< "Last name: " << contact.getLastName() << "\n"
				<< "Nickname: " << contact.getNickname() << "\n"
				<< "Phone number: " << contact.getPhoneNumber() << "\n"
				<< "Darkest secret: " << contact.getDarkestSecret() << std::endl; 
}

//function to display one contact for the search display
void Phonebook::displayOneContact(const Contact& contact, const int index){
	std::cout	<< std::setw(5)	<< index <<"|"
				<< std::setw(10)<< formatContactInfo(contact.getFirstName()) << "|"
				<< std::setw(10)<< formatContactInfo(contact.getLastName()) << "|"
				<< std::setw(10)<< formatContactInfo(contact.getNickname()) << std::endl;
	return;
}

//display the header of the table 
void Phonebook::displayHeader(void){

	std::cout	<< "Phonebook contactlist\n";
	std::cout 	<< "index|" << std::setw(11) << "first name|" 
							<< std::setw(11) << "last name|"
							<< std::setw(10) << "nickname"
							<< std::endl;
	std::cout	<< std::setfill('-') << std::setw(38) << "-" << std::setfill(' ') << std::endl;
	return;
}

//will create a formated string of if the amount of character is bigger then 10 characters else it will return a copy of the original string
std::string Phonebook::formatContactInfo(std::string info){
	if (info.size() > 10)
	{
		std::string formattedInfo = info.substr(0,9) + ".";
		return (formattedInfo);
	}
	else
		return (info);
}

//will update the given contact with the new values received from input
bool Phonebook::createContact(Contact& contact){

	std::string info;

	std::cout << "Fill in the information of the contact:" << std::endl;
	info = getInfo("First name");
	if (info.empty())
		return false;
	else
		contact.setFirstName(info); 
	info = getInfo("Last name");
	if (info.empty())
		return false;
	else
		contact.setLastName(info);
	info = getInfo("Nickname");
	if (info.empty())
		return false;
	else
		contact.setNickname(info); 
	info = getInfo("Phone number");
	if (info.empty())
		return false;
	else
		contact.setPhoneNumber(info); 
	info = getInfo("Darkest Secret");
	if (info.empty())
		return false;
	else
		contact.setDarkestSecret(info); 
	return (true);	
}

//will receive the input from the user.
std::string Phonebook::getInfo(std::string fieldName){
	
	std::string info;
	bool		done = false;

	while (!done){
		std::cout << fieldName << ":";
		std::getline(std::cin, info);

		if (std::cin.eof())
			return ("");
		else if (info.empty() || isStringEmpty(info))
			std::cout << "It can not be empty\n";
		else 
			done = true;
	}
	return (info);
}

//will test is the string is only composed of whites spaces.
//if it is it wil return true
//else it will return false
bool Phonebook::isStringEmpty(std::string& inputstring){
	
	const std::string whitespaces = " \r\n\t\v\f";
	
	inputstring.erase(0, inputstring.find_first_not_of(whitespaces));
	if (inputstring.empty())
		return (true);
	return (false);
}

int	Phonebook::getMaxContactListSize(void){
	return (MAX_CONTACTLIST_SIZE);
}
