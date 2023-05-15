#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class Rpn{
	private:

		std::string _inputstring;

		Rpn(Rpn const & cpy);
		Rpn& operator=(Rpn const & rhs);
		bool checkInput(std::string const & inputstr);

	public:
		Rpn(void);
		Rpn(std::string const & inputstr);
		~Rpn(void);
		
		void	setInput(std::string const & inputstring);
		bool	calculate(void);

};

#endif