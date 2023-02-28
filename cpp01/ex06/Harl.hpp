#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
enum e_level{NONE = 0, DEBUG = 1, INFO = 2, WARNING = 3, ERROR = 4};

class Harl{

	public:
		
		Harl(void);
		~Harl(void);

		void	complain(std::string input);

	private:

		e_level	convertInput(std::string input);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
