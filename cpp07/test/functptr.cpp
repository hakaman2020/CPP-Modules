#include <iostream>

#include <iostream>

template<typename A>
void test(A & number)
{
	number = number + 1;
}

// template<typename A>
// void	iter(A *array, size_t length, void (*func)(A & number))
// {
// 	func(array[0]);
// }

template<typename A, typename F>
void	iter(A array, size_t length, F func)
{
	func(array[0]);
}

template<typename T>
void print(const T & t)
{
	std::cout << t << std::endl;
}

//template void print(const float & f);

int main()
{
	
	int array[2] ={4,0};
	float arrayf[2] = {1.1, 2.0};

	iter(array, 2, test<int>);
	std::cout << array[0] << std::endl;
	iter(arrayf, 2, test<float>);
	std::cout << arrayf[0] << std::endl;
	
	iter(arrayf, 2, print<float>);

	return (0);
}


