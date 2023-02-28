#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
	try{
		//Bureaucrat john("John",0);
		//Bureaucrat john("John",200);
		//Bureaucrat john("John",150);
		//Bureaucrat john("John",1);
		Bureaucrat john("John", 20); 

		//Form form;
		//Form form("testform", 0, 150);
		//Form form("testform", 160, 150);
		//Form form("testform", 1, 150);
		//Form form("testform", 20, 150);
	
		PresidentialPardonForm form("Johnny");
		john.signForm(form);
		john.executeForm(form);

		RobotomyRequestForm robo("Noa");
		john.signForm(robo);
		john.executeForm(robo);

		ShrubberyCreationForm shrub("house");
		john.signForm(shrub);
		john.executeForm(shrub);
	}
	catch (std::exception & exception){
		std::cout << "Error : " << exception.what() << std::endl;
	}
	return 0;
}