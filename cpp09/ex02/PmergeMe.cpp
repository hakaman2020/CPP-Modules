#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){};
PmergeMe::~PmergeMe(void){};

bool PmergeMe::is_all_digits(char* str){
	if (str == NULL || *str == '\0'){
		return false;
	}
	while (*str){
		if(*str < '0' || *str> '9')
			return false;
		++str;
	}
	return true;
}

//Function will check the input of the arguments of input
bool PmergeMe::check_input(char **input, int *amount ){
	if(*input == NULL)
		return false;
	*amount = 0;
	while(*input){
		if(!is_all_digits(*input)){
			return false;
		}
		long number = std::strtol(*input, NULL, 10);
		if(errno == ERANGE || number > INT_MAX){
			return false;
		}
		++input;
		(*amount)++;
	}
	return true;
}

std::vector<int> PmergeMe::create_vector(char **input){
	std::vector<int> numbers;
	while(*input){
		numbers.push_back(std::strtol(*input, NULL, 10));
		input++;
	}
	return numbers;
}

void PmergeMe::start_sort_vector(std::vector<int> &numbers, int size_bucket){

	int amount_numbers = numbers.size();

	sort_vector(numbers, 0, amount_numbers - 1, size_bucket);
}

void PmergeMe::sort_vector(std::vector<int> & numbers, int start, int end, int size_bucket){
	if (end - start + 1 > size_bucket){
		int mid = (start + end) / 2;
		sort_vector(numbers, start, mid, size_bucket);
		sort_vector(numbers, mid + 1, end, size_bucket);
		merge_sort_vector(numbers, start, mid, end);
	} else {
		insert_sort_vector(numbers, start, end);
	}
}

void PmergeMe::merge_sort_vector(std::vector<int> & numbers, int start, int mid, int end){
	std::vector<int> sorted;
	int right_index = start;
	int left_index = mid + 1;
	int i = 0;
	int total_amount = end - start + 1;
	while( i < total_amount){
		if(right_index > mid){
			sorted.push_back(numbers[left_index]);
			left_index++;
		} else if(left_index > end){
			sorted.push_back(numbers[right_index]);
			right_index++;
		} else if (numbers[right_index] <= numbers[left_index]){
			sorted.push_back(numbers[right_index]);
			right_index++;
		} else {
			sorted.push_back(numbers[left_index]);
			left_index++;
		}
		i++;
	}

	for(size_t i = 0; i < sorted.size(); i++){
		numbers[start + i] = sorted[i];
	}
}

void PmergeMe::insert_sort_vector(std::vector<int> & numbers, int start, int end){
	if (start == end)
		return;
	int i = start + 1;

	while (i <= end){
		int j = i;
		while (j > start && (numbers[j - 1] > numbers[j])){
			int temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			--j;
		}
		++i;
	}
}

std::deque<int> PmergeMe::create_deque(char **input){
	std::deque<int> numbers;
	while(*input){
		numbers.push_back(std::strtol(*input, NULL, 10));
		input++;
	}
	return numbers;
}

void PmergeMe::start_sort_deque(std::deque<int> & numbers, int size_bucket){

	int amount_numbers = numbers.size();

	sort_deque(numbers, 0, amount_numbers - 1, size_bucket);

}

void PmergeMe::sort_deque(std::deque<int> & numbers, int start, int end, int size_bucket){
	if (end - start + 1 > size_bucket){
		int mid = (start + end) / 2;
		sort_deque(numbers, start, mid, size_bucket);
		sort_deque(numbers, mid + 1, end, size_bucket);
		merge_sort_deque(numbers, start, mid, end);
	} else {
		insert_sort_deque(numbers, start, end);
	}
}

void PmergeMe::merge_sort_deque(std::deque<int> & numbers, int start, int mid, int end){
	std::deque<int> sorted;
	int right_index = start;
	int left_index = mid + 1;
	int i = 0;
	int total_amount = end - start + 1;
	while( i < total_amount){
		if(right_index > mid){
			sorted.push_back(numbers[left_index]);
			left_index++;
		} else if(left_index > end){
			sorted.push_back(numbers[right_index]);
			right_index++;
		} else if (numbers[right_index] <= numbers[left_index]){
			sorted.push_back(numbers[right_index]);
			right_index++;
		} else {
			sorted.push_back(numbers[left_index]);
			left_index++;
		}
		i++;
	}

	for(size_t i = 0; i < sorted.size(); i++){
		numbers[start + i] = sorted[i];
	}
}

void PmergeMe::insert_sort_deque(std::deque<int> & numbers, int start, int end){
	if (start == end)
		return;
	int i = start + 1;

	while (i <= end){
		int j = i;
		while (j > start && (numbers[j - 1] > numbers[j])){
			int temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			--j;
		}
		++i;
	}
}
