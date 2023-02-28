#include "Cat.hpp"

Cat::Cat(std::string type):Animal(type){}

Cat::Cat(Cat const & src):Animal(){
	*this = src;
}

Cat& Cat::operator=(Cat const & rhs){
	_type = rhs.getType();
	return *this;
}

Cat::~Cat(void){}

void Cat::makeSound(void) const{
	std::cout << "Meow!" << std::endl;
}
