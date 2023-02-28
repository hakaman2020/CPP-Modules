#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
:Form("Robotomy Request Form", 145, 137), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(void){}

//disables functions because the name of the form is const and can't be changed after initialization.
//thus has been set to private so a copy constructor and copy assignment are not accessible.
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src){
	(void) src;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){
	(void) rhs;
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	this->executingCheck(executor);

	std::srand(std::time(NULL));
	int result = std::rand() % 2;
	if (result == 1)
		std::cout << this->getTarget() + " has succesfully been robotomized." << std::endl;
	else
		std::cout << this->getTarget() + " has not been robotomized." << std::endl;
}