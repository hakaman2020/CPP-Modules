#include "Harl.hpp"

Harl::Harl(void){
    return;
}

Harl::~Harl(void){
    return;
}

void Harl::complain(std::string input){
    
    e_level level = convertInput(input);
    switch(level){
        case DEBUG:
            debug();
        case INFO:
            info();
        case WARNING:
            warning();
        case ERROR:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

e_level Harl::convertInput(std::string input){
    e_level level = NONE;
    
    if(input.compare("DEBUG") == 0)
        level = DEBUG;
    else if(input.compare("INFO") == 0)
        level = INFO;
    else if(input.compare("WARNING") == 0)
        level = WARNING;
    else if(input.compare("ERROR") == 0)
        level = ERROR;
    return (level);
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
