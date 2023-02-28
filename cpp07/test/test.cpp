#include <iostream>
#include <stdexcept>




void test(void)
{
	throw std::out_of_range("out of rang index");
}


int main()
{
	int * a = new int();
	std::cout << *a << std::endl;

	try{
		test();
	}
	catch (std::exception & error)
	{
		std::cout << "error occured" << std::endl;
		std::cout << error.what() << std::endl;
	}


	return(0);
}
