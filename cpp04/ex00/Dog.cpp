#include "Dog.hpp"

Dog::Dog(std::string type):Animal(type){}

Dog::Dog(Dog const & src):Animal(){
	*this = src;
}

Dog& Dog::operator=(Dog const & rhs){
	_type = rhs.getType();
	return *this;
}

Dog::~Dog(void){}

void Dog::makeSound(void) const{
	std::cout << "WOOF!" << std::endl;
}
