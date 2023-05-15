#include "BitCoinExchange.hpp"


int main(int argc, char **argv){
	
	//(void) argv;
	if(argc != 2){
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try{
		BitCoinEx btc;

		//open the inputfile
		std::fstream input;
		input.open(argv[1], std::ios::in);
		if (!input.is_open()){
			std::cerr << argv[1] << " can't be open" << std::endl;
			return (1);
		}

		//read the inputfile
		std::string line;
		std::getline(input,line);
		while(std::getline(input, line)){
			btc.print_value(line);
		}
		
	} catch (std::exception & exception){
		std::cout << "Exception has beeen thrown" << std::endl;
		std::cout << exception.what() << std::endl;
	}



	return (0);
}