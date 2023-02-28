#include "Harl.hpp"

Harl::Harl(void){
	return;
}

Harl::~Harl(void){
	return;
}

void Harl::complain(std::string level){

	//string array of the different levels
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	//create array of the member function pointers
	void (Harl::*words[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for(int i = 0; i < 4; ++i){
		if (level.compare(levels[i]) == 0){
			(this->*words[i])();
		}	
	}
	return;
}

void Harl::debug(void){
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last months.\n" << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
