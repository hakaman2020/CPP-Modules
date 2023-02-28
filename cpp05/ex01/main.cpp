#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
		//Bureaucrat john("John",0);
		//Bureaucrat john("John",200);
		//Bureaucrat john("John",150);
		//Bureaucrat john("John",1);
		Bureaucrat john("John", 10); 

		//Form form;
		// Form form("testform", 0, 150);
		//Form form("testform", 160, 150);
		 Form form("testform", 1, 150);
		//Form form("testform", 20, 150);
		// Form form("testform", 10, 150);
		
		std::cout << form << std::endl;
		
		john.signForm(form);
	}
	catch (std::exception & exception){
		std::cout << "Error : " << exception.what() << std::endl;
	}
	return 0;
}