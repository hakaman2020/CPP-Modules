#include "Dog.hpp"

Dog::Dog(std::string type):Animal(type){
	brain = new Brain();
}

Dog::Dog(Dog const & src):Animal(){
	brain = new Brain();;
	*this = src;
}

Dog& Dog::operator=(Dog const & rhs){
	_type = rhs.getType();
	for(unsigned int i = 0; i < brain->getBrainsize(); ++i){
		brain->insertIdea(rhs.getIdea(i), i);
	}
	return *this;
}

Dog::~Dog(void){
	delete brain;
}

void Dog::makeSound(void) const{
	std::cout << "WOOF!" << std::endl;
}

std::string	Dog::getIdea(int index) const{
	return brain->getIdea(index);
}

void	Dog::insertIdea(std::string idea){
	brain->addIdea(idea);
}

void	Dog::displayBrain(void) const{
	brain->displayBrain();
}
