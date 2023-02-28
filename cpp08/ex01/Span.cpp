#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cmath>

Span::Span(void){}

Span::Span(unsigned int N):_maxNumbers(N){}

Span::Span(Span const & src)
: _numbers(src.getVector()),
 _maxNumbers(src.getMaxNumbers()){}

Span& Span::operator=(Span const & rhs)
{
	_maxNumbers = rhs._maxNumbers;
	_numbers = rhs._numbers;
	return *this;
}

Span::~Span(void){}

std::vector<int>	Span::getVector(void) const
{
	return (_numbers);
}

unsigned int	Span::getMaxNumbers(void) const
{
	return (_maxNumbers);
}
unsigned int	Span::getSize(void) const
{
	return (_numbers.size());
}

void	Span::printNumbers(void)
{
	std::vector<int>::iterator itr;
	for(itr = _numbers.begin(); itr != _numbers.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void	Span::addNumber(unsigned int number)
{
	if (_numbers.size() + 1 > _maxNumbers)
		throw Span::MaXElementsReached();
	else
		_numbers.push_back(number);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int amount = std::distance(begin, end);
	if (_numbers.size() + amount > _maxNumbers)
		throw Span::AmountToAddTooHigh();
	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int	Span::shortestSpan(void)
{
	if(_numbers.size() < 2)
		throw TooFewElements();
	std::vector<int> tmpcopy = _numbers;
	std::sort(tmpcopy.begin(), tmpcopy.end());
	long shortspan = -1;
	for(std::vector<int>::iterator itr = tmpcopy.begin(); itr != tmpcopy.end(); itr++)
	{
		std::vector<int>::iterator next = itr + 1;
		if (next == tmpcopy.end())
			break;
		long span = std::abs(*next - *itr);
		if(span < shortspan || shortspan == -1)
			shortspan = span;
	}
	return static_cast<unsigned int>(shortspan);
}
unsigned int	Span::longestSpan(void)
{
	if(_numbers.size() < 2)
		throw TooFewElements();
	return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}

const char * Span::MaXElementsReached::what(void) const throw()
{
	return ("Maximum elements reached.");
}

const char * Span::TooFewElements::what(void) const throw()
{
	return ("Too few elements stored.");
}

const char * Span::AmountToAddTooHigh::what(void) const throw()
{
	return ("Amount integers to add too high.");
}