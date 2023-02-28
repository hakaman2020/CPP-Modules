#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm: public Form{
	private:
		std::string	_target;

		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

	public :

		PresidentialPardonForm(std::string const & target);
		virtual ~PresidentialPardonForm(void);

		std::string		getTarget(void) const;
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif