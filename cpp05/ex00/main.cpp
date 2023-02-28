#include "Bureaucrat.hpp"

int main(){
	try{
		//Bureaucrat john("John",0);
		//Bureaucrat john("John",200);
		//Bureaucrat john("John",150);
		//Bureaucrat john("John",1);
		
		Bureaucrat john("John", 10); 
	
		std::cout << "Starting situation:\n" <<john << std::endl;
		std::cout << "name of bureaucrat is " + john.getName() << " and grade is " << john.getGrade() << std::endl;
		std::cout << "\nDecrementing grade" << std::endl;
		john.decrementGrade();
		std::cout << john << std::endl;
		std::cout << "\nIncrementing grade" << std::endl;
		john.incrementGrade();
		std::cout << john << std::endl;

		//disabled copy constructor and copy assignment because of the constant name
		// Bureaucrat dud;
		// dud = john;

	}
	catch (std::exception & exception){
		std::cout << "Error : " << exception.what() << std::endl;
	}
	return 0;
}