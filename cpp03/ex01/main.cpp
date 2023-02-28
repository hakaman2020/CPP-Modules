#include "ScavTrap.hpp"

int main(){
	ScavTrap st;
	std::string target("Fighter Dummy");

	st.guardGate();
	st.attack(target);
	st.takeDamage(20);
	st.beRepaired(20);
	st.takeDamage(100);
	st.attack(target);

	std::cout << std::endl;
	ScavTrap st2("App");
	for(int i = 0; i < 50; ++i)
		st2.attack(target);
	st2.beRepaired(10);
	return (0);
}