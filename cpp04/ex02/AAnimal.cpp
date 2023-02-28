#include "AAnimal.hpp"

AAnimal::AAnimal(std::string type): _type(type){}

AAnimal::AAnimal(AAnimal const & src){
	*this = src;
}

AAnimal& AAnimal::operator=(AAnimal const & rhs){
	_type = rhs._type;
	return *this;
}

AAnimal::~AAnimal(void){}

void	AAnimal::makeSound(void) const{
	std::cout << "..." << std::endl;
}

std::string	AAnimal::getType(void) const{
	return _type;
}