#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <deque>

void	test_print_other_iterator(MutantStack<int> mstack)
{
	std::cout << "Printing stack with const iterator" << std::endl;
	MutantStack<int>::const_iterator citr;
	for(citr = mstack.begin(); citr != mstack.end(); citr++)
		std::cout << *citr << " ";
	std::cout << std::endl;
	
	std::cout << "Printing stack with reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator ritr;
	for(ritr = mstack.rbegin(); ritr != mstack.rend(); ritr++)
		std::cout << *ritr << " ";
	std::cout << std::endl;
	
	std::cout << "Printing stack with const reverse iterator" << std::endl;
	MutantStack<int>::const_reverse_iterator critr;
	for(critr = mstack.rbegin(); critr != mstack.rend(); critr++)
		std::cout << *critr << " ";
	std::cout << std::endl;
}

void	print_stack_iterator(MutantStack<int> mstack)
{
	std::cout << "Printing stack with iterator" << std::endl;
	MutantStack<int>::iterator itr;
	for(itr = mstack.begin(); itr != mstack.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void checkleak(void)
{
	system("leaks -q mutantStack");
}


int main()
{
	atexit(checkleak);
	std::cout << "Basic test MutantStack.\n" << std::endl;
	{
		std::cout << " ---Default constructor test---\n" << std::endl;
		MutantStack<int> mstack;
		std::cout << "MutantStack size : " << mstack.size() << std::endl;
		std::cout << "MutantStack adding and popping" << std::endl;
		mstack.push(1);
		print_stack_iterator(mstack);
		mstack.pop();
		print_stack_iterator(mstack);
	}
	{
		std::cout << "\n---Copy constructor test---\n" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		MutantStack<int> mstackcopy = mstack;
		print_stack_iterator(mstackcopy);

		std::cout << "\n---Copy assignment test---\n" << std::endl;
		MutantStack<int> mstackassign;
		mstackassign = mstack;
		print_stack_iterator(mstackassign);
	}
	{
		std::cout << "\n---Basic stack test---\n" << std::endl;
		
		std::cout << "pushing 3 elements" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		print_stack_iterator(mstack);
		std::cout << "popping 1 element" << std::endl;
		mstack.pop();
		print_stack_iterator(mstack);
		std::cout << "checking top element" << std::endl;
		std::cout << "top element is " << mstack.top() << std::endl;
	}
	{
		std::cout << "\n---Mutant stack iterator test---\n" << std::endl;
		std::cout << "Creating Mutant stack with 10 ints 0 to 9\n" << std::endl;
		MutantStack<int> mstack;
		for(int i = 0; i < 10 ; ++i)
			mstack.push(i);
		print_stack_iterator(mstack);
		test_print_other_iterator(mstack);
	}

	{
		std::cout << "\n---Subject code---\n" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n---Subject code with vector---\n" << std::endl;
		std::vector<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << mstack.back() << std::endl;
		
		mstack.pop_back();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		//std::stack<int> s(mstack);
	}
	{
		std::cout << "\n---Subject code with deque---\n" << std::endl;
		std::deque<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << mstack.back() << std::endl;
		
		mstack.pop_back();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		
		std::deque<int>::iterator it = mstack.begin();
		std::deque<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	return (0);
}