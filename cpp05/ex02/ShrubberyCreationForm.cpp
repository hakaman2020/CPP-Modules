#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
:Form("Shrubbery Creation Form", 145, 137), _target(target){}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

//disables functions because the name of the form is const and can't be changed after initialization.
//thus has been set to private so a copy constructor and copy assignment are not accessible.
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src){
	(void) src;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){
	(void) rhs;
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	this->executingCheck(executor);

    std::ofstream outputfile;
    outputfile.open(this->getTarget() + "_shrubbery");
    outputfile <<
	"       ###     \n" <<
	"      #o###     \n" <<
	"    #####o###  \n" <<
	"   #o#\\#|#/### \n" <<
	"    ###\\|/#o#  \n" <<
	"     # }|{  #  \n" <<
	"       }|{     \n" << std::endl;
	outputfile.close();
}