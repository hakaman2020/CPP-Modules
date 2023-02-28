#include "Array.hpp"
#include <iostream>

template<typename T>
void print_array(Array<T>& array, unsigned int size, std::string name)
{
	std::cout << name << std::endl;
	for(unsigned i = 0; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

typedef struct s_data
{
	int x;
	double y;
}				t_data;

int main()
{
	//creating of empty array;
	std::cout << "testing empty array" << std::endl;
	Array<int> intArray;
	std::cout << "size array: " << intArray.size() << std::endl;

	//create an int array of 10
	std::cout << "\ncreating int array of 10" << std::endl;
	Array<int> intArray2(10);
	for(int i = 0; i < 10; ++i)
	{
		intArray2[i] = i;
	}
	print_array<int>(intArray2, intArray2.size(), "intArray2");

	//testing copy constructor
	std::cout << "\ntesting copy constructor " << std::endl;
	Array<int> intArray3 = intArray2;
	print_array(intArray2, intArray2.size(), "intArray2");
	print_array(intArray3, intArray3.size(), "intArray3");
	std::cout << "changed a single int in array 3" << std::endl;
	intArray3[2] = 9;
	print_array(intArray2, intArray2.size(), "intArray2");
	print_array(intArray3, intArray3.size(), "intArray3");

	//testing copy assignment
	std::cout << "\ntesting copy assignment" << std::endl;
	Array<int>intArray4;
	intArray4 = intArray3;
	print_array(intArray3, intArray3.size(), "intArray3");
	print_array(intArray4, intArray4.size(), "intArray4");
	std::cout << "changing a single int in array 4" << std::endl;
	intArray4[5] = 99;
	print_array(intArray3, intArray3.size(), "intArray3");
	print_array(intArray4, intArray4.size(), "intArray4");
	//testing out of bound index
	std::cout << "\ntesting out of bound index" << std::endl;
	try{
		intArray[11] = 0;
	}
	catch(std::exception & except)
	{
		std::cout << except.what() << std::endl;
	}

	//testing a different data type
	std::cout << "\ntesting a different data type" << std::endl;
	Array<t_data>data(2);
	data[0].x = 0;
	data[0].y = 1.6;
	data[1].x = 10;
	data[1].y = 23.4;
	std::cout << "data content"<< std::endl;
	std::cout << "data 0 : x : " << data[0].x << " y :" << data[0].y << std::endl;
	std::cout << "data 1 : x : " << data[1].x << " y :" << data[1].y << std::endl;
	
	return (0);
}