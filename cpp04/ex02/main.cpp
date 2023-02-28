#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void checkleaks(void){
// 	system("leaks -q brain");
// }

int main(){
	
	//create the array of animals with half dogs and half cats
	AAnimal* animals[100];
	for(int i = 0; i < 50; ++i){
		animals[i] = new Dog();
	}
	for(int i = 50; i < 100; ++i){
		animals[i] = new Cat();
	}
	std::cout << "\nDisplay all the animals in the array:\n" << std::endl;
	for(int i = 0; i < 100;++i){
		std::cout << "Animal " << i + 1 << " is of the type "+ animals[i]->getType() << " and makes the sound: ";
		animals[i]->makeSound();
	}
	for(int i = 0; i < 100; ++i){
		delete animals[i];
	}
	
	std::cout << "\nTesting Dog brain:" << std::endl;
	//test the Dog brain
	Dog dog;
	dog.insertIdea("Bones");
	dog.insertIdea("Sky");
	dog.insertIdea("Squirrel");
	std::cout << "Dog brain content:" << std::endl;
	dog.displayBrain();
	std::cout << "Dog idea at index 1:";
	std::cout << dog.getIdea(1) << std::endl;

	std::cout << "\nDog copy test:" << std::endl;
	Dog dog2 = dog;
	dog2.displayBrain();
	std::cout << "Dog idea at index 1:";
	std::cout << dog.getIdea(1) << std::endl;
	// atexit(checkleaks);

	//AAnimal a = new AAnimal();

	return 0;
}