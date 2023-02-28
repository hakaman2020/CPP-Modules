#include "FragTrap.hpp"

int main(){
	FragTrap ft("Joe");
	std::string target = "Fighter Dummy";

	ft.takeDamage(100);
	ft.attack(target);
	ft.beRepaired(10);
	for(int i = 0; i < 99; ++i)
		ft.attack(target);
	ft.attack(target);
	ft.highFivesGuys();
	return (0);
}