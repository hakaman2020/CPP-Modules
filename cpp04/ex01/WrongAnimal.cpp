#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type): _type(type){
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src){
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & rhs){
	_type = rhs._type;
	return *this;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "@#$@#%" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return _type;
}