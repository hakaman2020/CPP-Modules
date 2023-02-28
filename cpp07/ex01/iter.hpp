#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>

template<typename A, typename F>
void iter(A array, size_t length, F func)
{
	for(size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

template<typename A>
void	print_array(A array, size_t length)
{
	for(size_t i = 0; i < length; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

#endif