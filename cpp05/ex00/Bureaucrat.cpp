#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, unsigned int grade):_name(name), _grade(grade){
	checkInitGrade(grade);
}

//Copy constructor and copy assignment will be private and thus not accessible due to the const name
//which make copy the name difficult.
Bureaucrat::Bureaucrat(Bureaucrat const & src){
	checkInitGrade(src.getGrade());
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs){
	checkInitGrade(rhs.getGrade());
    _grade = rhs._grade;
    std::cout << "Grade has been copied, but the name has not been changed because it can't be changed" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(void){}

void Bureaucrat::checkInitGrade(unsigned int grade){
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName(void) const{
    return _name;
}

unsigned int    Bureaucrat::getGrade(void) const{
    return _grade;
}

void    Bureaucrat::incrementGrade(void){
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    --_grade;
}

void    Bureaucrat::decrementGrade(void){
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
	++_grade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("grade too high for bureaucrat");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("grade too low for bureaucrat");
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const & rhs){
	o << rhs.getName() + ", bureaucrat grade " << rhs.getGrade();
	return o;
}