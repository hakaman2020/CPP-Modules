#include <iostream>
#include "phonebook.hpp"
#include <limits.h>

// function check if all all characters are digits
static bool stringAllDigit(const std::string& input){

	for(unsigned long i = 0; i < input.size(); ++i)
	{
		if (input[i] < '0' && input[i] > '9'){
			return false;
		}
	}
	return true;
}

//convert the string into an positive integer
static int convertToInt(const std::string& input){
	unsigned long result = 0;

	for(unsigned long i = 0; i < input.size(); ++i){
		result = result * 10 + input[i] - 48;
	}
	if (result > INT_MAX)
		result = -1;
	return (result);
}

//will attempt to convert the input into an positive integer
//if it fails it will return -1
static int getIndex(void){
	std::string	index_string;

	std::getline(std::cin, index_string);
	if (std::cin.eof() == true || stringAllDigit(index_string) == false)
		return (-1);
	else
		return (convertToInt(index_string));
}

//function that will add a contact to the phonebook
static void fncADD(Phonebook& phonebook){
	if(phonebook.addContact() == false)
		std::cout << "\nError: Contact has not been added." << std::endl;
	else
		std::cout << "Success: Contact has been added." << std::endl;
}

//function that will display the contactlist and then display the chosen contact
static void fncSearch(Phonebook& phonebook){
	int index;

	phonebook.displayContactList();
	std::cout << "\nPlease select the index of the contact you want to view:";

	index = getIndex();
	if (index < 1 || index > phonebook.getMaxContactListSize())
		std::cout << "\nInvalid input." << std::endl;
	else{
		phonebook.displayFullContact(phonebook.getContact(index -1));
	}
}

//display the menu with the possible commands
static void displayMenu(void){
	
	std::cout 	<< "\nPlease enter your command:\n" 
				<< "ADD	for adding a new contact.\n"
				<< "SEARCH	for displaying a specific contact.\n"
				<< "EXIT	to quit the program." << std::endl;
	std::cout << ">";
}

int main(){

	Phonebook phonebook;

	std::cout << "\nWELCOME TO THE PHONEBOOK." << std::endl;
	while(true)
	{
		std::string command;

		displayMenu();
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0){
			fncADD(phonebook);
		}
		else if (command.compare("SEARCH") == 0){
			fncSearch(phonebook);
		}

		else if (command.compare("EXIT") == 0){
			std::cout << "\nExiting Program." << std::endl;
			break;
		}
		else
			std::cout << "\nInvalid command." << std::endl;
		if (std::cin.eof()){
			std::cout << "\nExiting Program." << std::endl;
			break;
		}
	}
	return (0);
}
