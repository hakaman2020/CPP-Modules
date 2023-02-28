#include "Zombie.hpp"

int main(){

	Zombie zombie("stdzombie"); //create default zombie
	Zombie* newZombie; //pointer for the heap zombie

	newZombie = zombie.newZombie("newZombie"); //create heap zombie
	zombie.announce(); //default zombie announce
	newZombie->announce(); //heap zombie announce
	zombie.randomChump("randomZombie"); //create stack zombie and announce

	delete newZombie;
	return (0);
}