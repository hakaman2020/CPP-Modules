#include "serial.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

void	printData(Data* person)
{
	std::cout << "Name: " << person->name << "\nJob :" << person->job << "\nGrade :" << person->grade << std::endl;
}

void checkleaks(void)
{
	system("leaks -q serialize");
}

int main()
{
	//creation of the data struct
	Data* person = new(Data);
	person->name = "John";
	person->job = "Bureaucrat";
	person->grade = 100;

	//printing the data
	std::cout << "Original data :" << std::endl;
	printData(person);
	//serialize the pointer
	uintptr_t raw = serialize(person);
	//deserialize the pointer
	Data* recoverData = deserialize(raw);
	//printing the recovered data pointer
	std::cout << "Recovered data :" << std::endl;
	printData(recoverData);
	//checking if the recovered pointer also points to the original
	std::cout << "address of original :" << person << std::endl;
	std::cout << "address of the recovered :" << recoverData << std::endl;

	delete (person);
	atexit(checkleaks);
	return (0);
}
