#include <iostream>

typedef struct s_data
{
	int x;
	int y;
}				t_data;

int main()
{
	t_data hello{.x= 9,.y = 10};
	t_data hello2{.x=1,.y=2};
	hello2 = hello;
	std::cout << hello.x << " " << hello.y << std::endl;
	std::cout << hello2.x << " " << hello2.y << std::endl;
	hello.x = 99;
	std::cout << hello.x << " " << hello.y << std::endl;
	std::cout << hello2.x << " " << hello2.y << std::endl;
	std::cout << &(hello.x) << " " << &(hello2.x) << std::endl;
	return (0);
}