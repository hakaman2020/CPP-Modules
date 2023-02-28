#include <iostream>
#include <algorithm>
#include "Span.hpp"

int main()
{
	//default test
	{
		std::cout <<"Test 1" << std::endl;
		unsigned int amount = 3;
		Span testspan(amount);
		testspan.addNumber(2147483647);
		testspan.addNumber(-2147483648);
		testspan.addNumber(2147483646);

		std::cout << "numbers :" ;
		testspan.printNumbers();
		std::cout << "shortest span " <<testspan.shortestSpan() << std::endl;
		std::cout << "longest span " <<testspan.longestSpan() << std::endl;
		std::cout << "\nmax numbers exception test" << std::endl;
		try
		{
			testspan.addNumber(3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\ntest copy constructor and copy assignement" << std::endl;
		Span testspan2 = testspan;
		testspan2.printNumbers();
		Span testspan3;
		testspan3 = testspan;
		testspan3.printNumbers();
	}
	
	{
		// exception test
		std::cout << "\nexception test" << std::endl;
		Span test2(20000);
		try{
			test2.shortestSpan();
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		try{
			test2.longestSpan();
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		//add number range test
		std::cout << "\naddnumber range test" << std::endl;
		std::srand(time(0));
		std::vector<int> input(15000);
		std::generate(input.begin(), input.end(), std::rand);
		std::cout << "longest span in vector " << *(std::max_element(input.begin(), input.end())) - *(std::min_element(input.begin(), input.end())) << std::endl;
		
		test2.addNumber(input.begin(), input.end());
		std::cout << "shortest span " <<test2.shortestSpan() << std::endl;
		std::cout << "longest span " <<test2.longestSpan() << std::endl;
		try
		{
			test2.addNumber(input.begin(), input.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	//subject code
	std::cout << "\nsubject code" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return (0);
}