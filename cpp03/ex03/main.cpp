#include "DiamondTrap.hpp"

int main(){
	DiamondTrap dt("Diamond");
	std::string target = "Fighter dummy";
	dt.whoAmI();
	dt.otherInfo();

	for(int i =0; i < 50; ++i)
		dt.attack(target);
	dt.beRepaired(100);

	return (0);
}