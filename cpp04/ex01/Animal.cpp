#include "Animal.hpp"

Animal::Animal(std::string type): _type(type){}

Animal::Animal(Animal const & src){
	*this = src;
}

Animal& Animal::operator=(Animal const & rhs){
	_type = rhs._type;
	return *this;
}

Animal::~Animal(void){}

void	Animal::makeSound(void) const{
	std::cout << "..." << std::endl;
}

std::string	Animal::getType(void) const{
	return _type;
}