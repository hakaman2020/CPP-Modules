#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<template<typename,typename> class Container, typename T, typename Allocator>
typename Container<T, Allocator>::iterator easyfind(Container<T, Allocator> & container, int number)
{
	return std::find(container.begin(), container.end(), number);
}
#endif