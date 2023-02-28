#include "WrongCat.hpp"

WrongCat::WrongCat(std::string type):WrongAnimal(type){}

WrongCat::WrongCat(WrongCat const & src){
	*this = src;
}

WrongCat& WrongCat::operator=(WrongCat const & rhs){
	_type = rhs.getType();
	return *this;
}

WrongCat::~WrongCat(void){}

void WrongCat::makeSound(void) const{
	std::cout << "MOOOOOOOOW!" << std::endl;
}