#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat{
	private:

		const std::string	_name;
		int					_grade;

		void	checkInitGrade(unsigned int grade);
		Bureaucrat& operator=(Bureaucrat const & rhs);
		Bureaucrat(Bureaucrat const & src);

	public:

		Bureaucrat(std::string const & name = "John", unsigned int grade = 150);
		~Bureaucrat(void);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void			incrementGrade(void);
		void			decrementGrade(void);

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