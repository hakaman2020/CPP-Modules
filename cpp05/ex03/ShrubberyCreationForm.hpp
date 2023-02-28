#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm: public Form{
	private:
		std::string	_target;

		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);

	public :

		ShrubberyCreationForm(std::string const & target);
		virtual ~ShrubberyCreationForm(void);

		std::string		getTarget(void) const;
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif