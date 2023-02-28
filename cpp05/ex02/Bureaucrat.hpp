#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

# include "Form.hpp"

class Bureaucrat{
	private:

		const std::string	_name;
		int					_grade;

		Bureaucrat& operator=(Bureaucrat const & rhs);
		Bureaucrat(Bureaucrat const & src);

		void	checkInitGrade(unsigned int grade);

	public:

		Bureaucrat(std::string const & name = "John", unsigned int grade = 150);
		~Bureaucrat(void);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void			incrementGrade(void);
		void			decrementGrade(void);

		void			signForm(Form& form);
		void			executeForm(Form const & form) const;

	class GradeTooHighException: public std::exception{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const & rhs);

#endif