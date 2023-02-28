#ifndef TEST_HPP
# define TEST_HPP
# include <string>

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

# endif