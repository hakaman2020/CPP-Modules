#include "ClapTrap.hpp"

int main(){
	ClapTrap ct("Clap");
	std::string target = "Fighting dummy";

	ct.attack(target);
	ct.takeDamage(1);
	ct.beRepaired(1);
	for(int i = 0; i < 7; ++i){
		ct.attack(target);
	}
	ct.attack(target);
	ct.beRepaired(10);
	std::cout << std::endl;
	
	ClapTrap ct2("Clap2");
	ct2.attack(target);
	ct2.takeDamage(10);
	ct2.attack(target);

	std::cout << std::endl;
	ClapTrap ct3(ct);
	ct3.attack(target);

	return (0);
}