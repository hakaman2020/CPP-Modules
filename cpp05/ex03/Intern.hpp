#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern{
	enum forms {Unknown = -1, ShrubberyCreation, RobotomyRequest, PresidentialPardon};

	private :
	void	printMessage(std::string formName);
	int		findFormNumber(std::string const & formName);

	public :

		Intern(void);
		Intern(Intern const & src);
		Intern& operator=(Intern const & rhs);
		~Intern(void);


		Form* makeform(std::string const & formName, std::string const & target);

	class UnknowFormException: public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

#endif