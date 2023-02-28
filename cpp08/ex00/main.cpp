#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>

void	find_in_vector(std::vector<int> & intvector, int number_to_look)
{
	std::vector<int>::iterator itr = easyfind(intvector, number_to_look);
	if (itr == intvector.end())
		std::cout << "didn't find " << number_to_look << std::endl;
	else
		std::cout << "found " << number_to_look << " at position " << itr - intvector.begin() << std::endl;
}

void	find_in_deque(std::deque<int> & intdeque, int number_to_look)
{
	std::deque<int>::iterator itr = easyfind(intdeque, number_to_look);
	if (itr == intdeque.end())
		std::cout << "didn't find " << number_to_look << std::endl;
	else
		std::cout << "found " << number_to_look << " at position " << itr - intdeque.begin() << std::endl;
} 

void	find_in_list(std::list<int> & intlist, int number_to_look)
{
	std::list<int>::iterator itr = easyfind(intlist, number_to_look);
	if (itr == intlist.end())
		std::cout << "didn't find " << number_to_look << std::endl;
	else
		std::cout	<< "found " << number_to_look << " at position " 
					<< std::distance(intlist.begin(), itr) << std::endl; 
	// can't calculate the position with pointer arithmetic because it is a double linked list
	// but with a std::distance we can get the amount of hops made from the start of the list
} 

int main()
{
	//testing vector
	std::cout <<"--- testing int vector ---" << std::endl;
	
	std::vector<int> intvector;
	intvector.push_back(2);
	intvector.push_back(3);
	intvector.push_back(99);
	intvector.push_back(5);
	intvector.push_back(7);
	intvector.push_back(1);

	find_in_vector(intvector, 99);
	find_in_vector(intvector, 10);
	find_in_vector(intvector, 1);

	std::cout <<"--- testing int deque ---" << std::endl;
	std::deque<int> intdeque;
	intdeque.push_back(2);
	intdeque.push_back(3);
	intdeque.push_back(99);
	intdeque.push_back(5);
	intdeque.push_back(7);
	intdeque.push_back(1);
	
	find_in_deque(intdeque, 99);
	find_in_deque(intdeque, 10);
	find_in_deque(intdeque, 1);

	std::cout <<"--- testing int list ---" << std::endl;
	std::list<int> intlist;
	intlist.push_back(2);
	intlist.push_back(3);
	intlist.push_back(99);
	intlist.push_back(5);
	intlist.push_back(7);
	intlist.push_back(1);
	
	find_in_list(intlist, 99);
	find_in_list(intlist, 10);
	find_in_list(intlist, 1);
	return (0);
}