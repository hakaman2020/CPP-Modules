#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void checkleaks(void){
// 	system("leaks -q animal");
// }

int main(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	//cleanup
	delete meta;
	delete j;
	delete i;

	//no virtual functions
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	delete k;

//	atexit(checkleaks);
	return 0;
}