#include "Animal.hpp"

Animal::Animal(std::string type): _type(type){
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(Animal const & src){
	*this = src;
}

Animal& Animal::operator=(Animal const & rhs){
	_type = rhs._type;
	return *this;
}

Animal::~Animal(void){
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound(void) const{
	std::cout << "..." << std::endl;
}

std::string	Animal::getType(void) const{
	return _type;
}