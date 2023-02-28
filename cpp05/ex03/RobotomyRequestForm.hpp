#ifndef ROBOTOMYREQUESTFORM_HPP 
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm: public Form{
	private:
		std::string	_target;

		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

	public :

		RobotomyRequestForm(std::string const & target);
		virtual ~RobotomyRequestForm(void);

		std::string		getTarget(void) const;
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif