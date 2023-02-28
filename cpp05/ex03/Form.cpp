#include "Form.hpp"

Form::Form(std::string const & name, unsigned int signMinGrade, unsigned int execMinGrade)
: _name(name), _signMinGrade(signMinGrade), _execMinGrade(execMinGrade), _signed(false){
	checkInitGrade(signMinGrade);
	checkInitGrade(execMinGrade);
}

Form::~Form(){}

//in private not allowed to used due to const variables
Form::Form(Form const & src): _name(src.getName()), _signMinGrade(src.getSignGrade()), _execMinGrade(src.getExecGrade()){}
Form& Form::operator=(Form const & rhs){
	(void) rhs;
	return *this;
}

void	Form::checkInitGrade(unsigned int grade){
	if(grade < 1)
		throw Form::GradeTooHighException();
	else if(grade > 150)
		throw Form::GradeTooLowException();
}

void	Form::executingCheck(Bureaucrat const & executor) const{
	if (this->isSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

std::string	Form::getName(void) const{
	return _name;
}

unsigned int	Form::getSignGrade(void) const{
	return _signMinGrade;
}

unsigned int	Form::getExecGrade(void) const{
	return _execMinGrade;
}

bool	Form::isSigned(void) const{
	return _signed;
}

void	Form::beSigned(Bureaucrat & bur){
	if (bur.getGrade() <= this->_signMinGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what(void) const throw(){
	return ("grade too high for form");
}

const char* Form::GradeTooLowException::what(void) const throw(){
	return ("grade too low for form");
}

const char* Form::FormNotSignedException::what(void) const throw(){
	return ("the form has not been signed");
}

std::ostream& operator<<(std::ostream& o, Form const & rhs){
	o << "Form name: " + rhs.getName() + ", Sign grade : " << rhs.getSignGrade()
		<< " Execution grade : " << rhs.getExecGrade();
	return o;
}