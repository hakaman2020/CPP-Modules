#include "Brain.hpp"

Brain::Brain(void){}

Brain::Brain(Brain const & src){
	*this = src;
}

Brain& Brain::operator=(Brain const & rhs){
	_index = rhs._index;
	for(int i = 0; i < BRAIN_SIZE; ++i){
		_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

Brain::~Brain(void){}

unsigned int	Brain::getBrainsize(void) const{
	return BRAIN_SIZE;
}

bool	Brain::insertIdea(std::string idea, unsigned int index){
	if (index < BRAIN_SIZE){
		_ideas[index] = idea;
		return true;
	}
	return false;
}
void	Brain::addIdea(std::string idea){
	_ideas[_index] = idea;
	++_index;
	_index %= BRAIN_SIZE;
}

std::string	Brain::getIdea(int index) const{
	if(index >= 0 && index < BRAIN_SIZE)
		return _ideas[index];
	return "";
}

void	Brain::displayBrain(void) const{
	for(int i = 1; i <= BRAIN_SIZE; ++i)
		std::cout << "idea " << i << ": " + _ideas[i -1] << std::endl;
}

int Brain::_index = 0;
