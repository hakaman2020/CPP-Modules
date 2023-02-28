#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void checkleaks(void){
	system("leaks -q intern");
}
int main(){
	try{
		//Bureaucrat john("John",0);
		//Bureaucrat john("John",200);
		//Bureaucrat john("John",150);
		//Bureaucrat john("John",1);
		Bureaucrat john("John", 1); 

		//Form form;
		//Form form("testform", 0, 150);
		//Form form("testform", 160, 150);
		//Form form("testform", 1, 150);
		//Form form("testform", 20, 150);
	
		// PresidentialPardonForm form("Johnny");
		// john.signForm(form);
		// john.executeForm(form);

		// RobotomyRequestForm robo("Noa");
		// john.signForm(robo);
		// john.executeForm(robo);
		
		// ShrubberyCreationForm shrub("house");
		// john.signForm(shrub);
		// john.executeForm(shrub);

		Intern it;
		//Form* testForm = it.makeform("fasdljk","house");
		//Form* testForm = it.makeform("presidential pardon","house");
		//Form* testForm = it.makeform("robotomy request","house");
		Form* testForm = it.makeform("shrubbery creation","house");

		john.signForm(*testForm);
		john.executeForm(*testForm);
		delete testForm;
	}
	catch (std::exception & exception){
		std::cout << "Error : " << exception.what() << std::endl;
	}
	

	atexit(checkleaks);
	return 0;
}