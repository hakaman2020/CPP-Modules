#include "Intern.hpp"

Intern::Intern(void){}
Intern::Intern(Intern const & src){
	*this = src;
}
Intern& Intern::operator=(Intern const & rhs){
	(void) rhs;
	return *this;
}

Intern::~Intern(void){}

void	Intern::printMessage(std::string formName){
	std::cout << "Intern creates " + formName + " form" << std::endl;
}

int Intern::findFormNumber(std::string const & formName){
	std::string formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int sizeArray = sizeof (formTypes)/ sizeof(formTypes[0]);
	for(int formNumber = 0; formNumber < sizeArray; ++formNumber){
		if (formName.compare(formTypes[formNumber]) == 0)
			return formNumber;
	}
	return Unknown;
}

//function that will attempt to create the requested form object in heap and return the pointer to it
Form* Intern::makeform(std::string const & formName, std::string const & target){
	int formNumber = this->findFormNumber(formName);
	switch (formNumber){
		case ShrubberyCreation:
			Intern::printMessage(formName);
			return (new ShrubberyCreationForm(target));
		case RobotomyRequest:
			Intern::printMessage(formName);
			return (new RobotomyRequestForm(target));
		case PresidentialPardon:
			Intern::printMessage(formName);
			return (new PresidentialPardonForm(target));
		default:
			throw UnknowFormException();
	}
}

const char* Intern::UnknowFormException::what(void) const throw(){
	return ("the requested form is unknown");
}
