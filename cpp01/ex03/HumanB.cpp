#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){
	_weapon = NULL;
	return;
}

HumanB::~HumanB(void){
	return;
}

void	HumanB::attack(void){
	std::cout << this->_name << " attacks with their ";
	if (_weapon != NULL)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "fists" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}