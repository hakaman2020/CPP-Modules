#include "iter.hpp"

template<typename A>
void increase(A & number)
{
	number += 1;
}

template<typename A>
void decrease(A & number)
{
	number -= 1;
}

typedef struct s_bureaucrat
{
	std::string	name;
	int			grade;
}			t_bureaucrat;

void	print_bureaucrat(t_bureaucrat & bur)
{
	std::cout	<< "name: " << bur.name
				<< " grade: " << bur.grade
				<< std::endl;
}

void	increase_grade(t_bureaucrat & bur)
{
	bur.grade -= 1;
}

int main()
{
	//test int array
	int array[6] ={0, 1, 2, 3, 4, 5};
	
	std::cout << "current int array" << std::endl;
	print_array(array, 6);
	std::cout << std::endl;
	std::cout << "increase int array by 1" << std::endl;
	iter(array, 6, increase<int>);
	std::cout << std::endl;
	std::cout << "current int array" << std::endl;
	print_array(array, 6);
	std::cout << std::endl;

	//test float array
	float arrayf[7] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	std::cout << "current float array" << std::endl;
	print_array(arrayf, 7);
	std::cout << std::endl;
	std::cout << "increase float array by 1" << std::endl;
	iter(arrayf, 7, decrease<float>);
	std::cout << std::endl;
	std::cout << "current float array" << std::endl;
	print_array(arrayf, 7);
	std::cout << std::endl;

	t_bureaucrat team[3]={
		{.name="John",	.grade=10},
		{.name="Betty",	.grade=10},
		{.name="Carl",	.grade=2}
	};

	std::cout << "current team" << std::endl;
	iter(team, 3, print_bureaucrat);
	std::cout << std::endl;
	std::cout << "increasing all grades" << std::endl;
	iter(team, 3, increase_grade);
	std::cout << std::endl;
	std::cout << "current team " << std::endl;
	iter(team, 3, print_bureaucrat);
	
	return (0);
}