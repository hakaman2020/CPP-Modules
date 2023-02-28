#include "Cat.hpp"

Cat::Cat(std::string type):Animal(type){
	brain = new Brain();
}

Cat::Cat(Cat const & src):Animal(){
	brain = new Brain();
	*this = src;
}

Cat& Cat::operator=(Cat const & rhs){
	_type = rhs.getType();
	for(unsigned int i = 0; i < brain->getBrainsize(); ++i){
		brain->insertIdea(rhs.getIdea(i), i);
	}
	return *this;
}

Cat::~Cat(void){
	delete brain;
}

void Cat::makeSound(void) const{
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getIdea(int index) const{
	return brain->getIdea(index);
}

void	Cat::insertIdea(std::string idea){
	brain->addIdea(idea);
}

void	Cat::displayBrain(void) const{
	brain->displayBrain();
}
