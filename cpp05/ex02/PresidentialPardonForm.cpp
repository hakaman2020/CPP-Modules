#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
:Form("Presidential Pardon Form", 25, 5), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm(void){}

//disables functions because the name of the form is const and can't be changed after initialization.
//thus has been set to private so a copy constructor and copy assignment are not accessible.
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src){
	(void) src;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
	(void) rhs;
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	this->executingCheck(executor);
	std::cout << this->getTarget() + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


