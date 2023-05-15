#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Usage e.g. ./RPN \"7 3 + 7 -\"" << std::endl;
		return (1);
	}

	Rpn rpn(argv[1]);
	rpn.calculate();
	return(0);
}