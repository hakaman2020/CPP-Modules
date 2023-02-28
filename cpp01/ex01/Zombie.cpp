#include "Zombie.hpp"

Zombie::Zombie(void){
	return;
}

Zombie::~Zombie(void){
	std::cout << "Destructor for zombie " + this->_name + " called." << std::endl;
	return;
}

void Zombie::announce(void){
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->_name = name;
}
