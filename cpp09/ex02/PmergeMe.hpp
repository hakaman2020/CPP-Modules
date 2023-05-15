#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <limits.h>
# include <vector>
# include <deque>
# include <cerrno>
# include <iostream>

class PmergeMe{
	private:

		PmergeMe(PmergeMe const & src){(void) src;}
		PmergeMe & operator=(PmergeMe const & rhs){
			(void) rhs;
			return *this;
		}

		bool is_all_digits(char* str);

		void sort_vector(std::vector<int> & numbers, int start, int end, int size_bucket);
		void merge_sort_vector(std::vector<int> & numbers, int start, int mid, int end);
		void insert_sort_vector(std::vector<int> & numbers, int start, int end);

		void sort_deque(std::deque<int> & numbers, int start, int end, int size_bucket);
		void merge_sort_deque(std::deque<int> & numbers, int start, int mid, int end);
		void insert_sort_deque(std::deque<int> & numbers, int start, int end);

	public:

		PmergeMe(void);
		~PmergeMe(void);

		bool check_input(char **input, int *amount);

		std::vector<int> create_vector(char **input);
		std::deque<int> create_deque(char **input);	

		void start_sort_vector(std::vector<int> & numbers, int size_bucket);
		void start_sort_deque(std::deque<int> & numbers, int size_bucket);
};

#endif
