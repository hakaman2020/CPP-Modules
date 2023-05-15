#include "PmergeMe.hpp"
#include <sys/time.h>

void print_numbers(std::vector<int> & numbers, std::string const & prefix){
	std::cout << prefix;
	for(size_t i = 0; i < numbers.size(); ++i){
		std::cout << numbers[i] << " ";
	}
	std::cout << "\n" << std::endl;
}

void print_elapsed_time(struct timeval & begin, struct timeval & end,
	int amount_elements, std::string container_name){
	
	long seconds = end.tv_sec - begin.tv_sec;
	long microsecond = end.tv_usec - begin.tv_usec;
	double elapsed = seconds + microsecond * 1e-6;
	
	std::cout << "Time to process a range of " << amount_elements 
		<< " elements with " << container_name << " : "
		<< std::fixed<<  elapsed << " sec." << std::endl;
}

int main(int argc, char **argv){
	if(argc == 1){
		std::cout << "Please provide a sequence of positive integers to sort " << std::endl;
		return (0);
	}

	PmergeMe merge_me;
	int amount_elements; 

	//check the inpupt and also returns the amount of elements counted
	if(!merge_me.check_input(&argv[1], &amount_elements)){
		std::cout << "Error: Wrong input" << std::endl;
		return (1);
	}

	int size_bucket = 10;
	
	std::vector<int> numbers_vector = merge_me.create_vector(&argv[1]);
	std::deque<int> numbers_deque = merge_me.create_deque(&argv[1]);

	struct timeval begin;
	struct timeval end;

	print_numbers(numbers_vector, "Before : ");

	gettimeofday(&begin, 0);
	merge_me.start_sort_vector(numbers_vector, size_bucket);
	gettimeofday(&end, 0);

	print_numbers(numbers_vector, "After : ");
	print_elapsed_time(begin, end, amount_elements, "std::vector");

	gettimeofday(&begin, 0);
	merge_me.start_sort_deque(numbers_deque, size_bucket);
	gettimeofday(&end, 0);
	print_elapsed_time(begin, end, amount_elements, "std::deque");
	return (0);
}
