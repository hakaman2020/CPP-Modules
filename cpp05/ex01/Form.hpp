#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>

class Form;

# include "Bureaucrat.hpp"

class Form{
	private:
	 
		const std::string	_name;
		const unsigned int	_signMinGrade;
		const unsigned int	_execMinGrade;
		bool 				_signed;

		Form(Form const & src);
		Form& operator=(Form const & rhs);

		void	checkInitGrade(unsigned int grade);

	public:
	
		Form(std::string const & name="default", unsigned int signMinGrade = 150
			, unsigned int execMinGrade = 150);
		~Form(void);

		std::string		getName(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;
		bool			isSigned(void) const;
		void			beSigned(Bureaucrat & bur);

	class GradeTooHighException: public std::exception{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, Form const & rhs);

#endif