#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span{
	private:

		std::vector<int>	_numbers;
		unsigned int		_maxNumbers;
		
		unsigned int		getSize(void) const;
		unsigned int		getMaxNumbers(void) const;
		std::vector<int>	getVector(void) const;

	public:

		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		Span& operator=(Span const & rhs);
		~Span(void);

		void			printNumbers(void);
		void			addNumber(unsigned int number);
		void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

	class MaXElementsReached: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class TooFewElements: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class AmountToAddTooHigh: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
#endif