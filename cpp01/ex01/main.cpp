#include "Zombie.hpp"

#define HORDE_SIZE 25

int main(){

	Zombie zombie;
	Zombie* horde;
	
	horde = zombie.zombieHorde(HORDE_SIZE, "hordeMember");

	for(int i = 0; i < HORDE_SIZE; ++i){
		std::cout << i + 1 << ". ";
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}