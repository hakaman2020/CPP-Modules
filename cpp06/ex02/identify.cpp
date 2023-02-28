#include "identify.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

Base * generate(void)
{
	Base * randomObj = NULL;

	std::cout << "Randomly generated a object of the type : ";
	std::srand(std::time(NULL));
	int result = std::rand() % 3;
	if (result == 0)
	{
		randomObj = dynamic_cast<Base *>(new(A));
		std::cout << "A";
	}
	else if (result == 1)
	{
		randomObj = dynamic_cast<Base *>(new(B));
		std::cout << "B";
	}
	else if (result == 2)
	{
		randomObj = dynamic_cast<Base *>(new(C));
		std::cout << "C";
	}
	std::cout << std::endl;

	return (randomObj);	
}

void identify(Base* p)
{
	std::cout << "The type pointed by p has been identified as ";
	if(dynamic_cast<A *>(p) != NULL)
		std::cout << "A";
	else if(dynamic_cast<B *>(p) != NULL)
		std::cout << "B";
	else if(dynamic_cast<C *>(p) != NULL)
		std::cout << "C";
	std::cout << std::endl;
}

void identify(Base& p)
{
	std::cout << "The type pointed by p has been identified as ";
	try{
		A& temp = dynamic_cast<A&>(p);
		(void) temp;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &error){}
	try{
		B& temp = dynamic_cast<B&>(p);
		(void) temp;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &error){}
	try{
		C& temp = dynamic_cast<C&>(p);
		(void) temp;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &error){}
}

int main()
{
	Base * randomObj;

	randomObj = generate();
	identify(randomObj);

	identify(*randomObj);
	return (0);
}