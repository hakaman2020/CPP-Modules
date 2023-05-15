#include "RPN.hpp"

//constructors
Rpn::Rpn(void){}

Rpn::Rpn(std::string const &
inputstring){
	_inputstring = inputstring;
}

Rpn::~Rpn(void){}

//disabled by setting to private
Rpn::Rpn(Rpn const & cpy){
	(void) cpy;
}

//disabled by setting to private
Rpn& Rpn::operator=(Rpn const & rhs){
	(void) rhs;
	return *this;
}

bool Rpn::checkInput(std::string const & inputstr){
	static std::string accepted_input = " +-/*0123456789";
	for(size_t i = 0; i < inputstr.size(); ++i){
		if(accepted_input.find(inputstr[i]) == std::string::npos){
			return false;
		}
	}
	return true;
}

void Rpn::setInput(std::string const & inputstr){
	_inputstring = inputstr;
}

bool Rpn::calculate(void){
	if (_inputstring.empty()){
		std::cout << "Error" << std::endl;
		return false;
	}
	if (!checkInput(_inputstring)){
		std::cout << "Error" << std::endl;
		return false;
	}
	//do the calculation
	std::stack<float> stack;
	std::stringstream str(_inputstring);
	std::string token;
	
	while (str >> token){
		if (token.size() > 1){
			std::cout << "this token " << token << " is not accepted" << std::endl;
			return false;
		}
		if (token[0] >= '0' && token[0] <= '9')
			stack.push(static_cast<float>(token[0] - 48));
		else if (stack.size() >= 2){

			float result = 0;
			
			float second = stack.top();
			stack.pop();
			float first = stack.top();
			stack.pop();
			if(token[0] == '+'){
				result = first + second;
			}
			else if(token[0] == '-'){
				result = first - second;
			}
			else if(token[0] == '*'){
				result = first * second;
			}
			else if(token[0] == '/'){
				result = first / second;
			}
			stack.push(result);
		}
		else{
			std::cout << "Error" << std::endl;
			return false;
		}
	}
	if (stack.size() > 1 || stack.size() == 0){
		std::cout << "Error" << std::endl;
		return false;
	}
	std::cout << stack.top() << std::endl;
	return true;
}