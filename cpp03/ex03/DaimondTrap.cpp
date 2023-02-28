#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"), _name(name){
std::cout << "Diamand constructor called" << std::endl;

	//creating seperate class objects to still technically get the variable values from the respective class objects
	ScavTrap st;
	FragTrap ft;

	_hitPoints = ft.getHitpoints();
	_energyPoints = st.getEnergyPoints();
	_attackDamage = ft.getAttackDamage();
}

DiamondTrap::DiamondTrap(DiamondTrap const & src){
	*this = src;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs){
	_name = rhs.getName();
	_hitPoints = rhs.getHitpoints();
	_energyPoints = rhs.getEnergypoints();
	_attackDamage = rhs.getAttackdamage();
	return *this;
}

DiamondTrap::~DiamondTrap(void){
	return;
}
void	DiamondTrap::attack(std::string & target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const{
	std::cout << "DiamondTrap name is " + _name + " and the ClapTrap name is " + ClapTrap::_name << std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount){
	std::cout << "DiamondTrap " + _name + " takes " << amount << " damage";
	if (amount >= _hitPoints){
		_hitPoints = 0;
		std::cout << " and lost all its hitpoints";
	}
	else{
		_hitPoints -= amount;
		std::cout << " and has " << _hitPoints << " hitpoints left";
	}
	std::cout << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount){
	if(_energyPoints > 0){
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "DiamondTrap " + _name + " has repaired itself and increased its hitpoints with "
		<< amount << " to a total of " << _hitPoints << std::endl;
	}
	else{
		std::cout << "DiamondTrap " + _name + " don't have enough energy to repair itself"
		<< std::endl;
	}
}

void	DiamondTrap::otherInfo(void) const{
	std::cout 	<< "DiamondTrap info:\nHitpoints : " << _hitPoints 
				<< "\nEnergy points : " << _energyPoints
				<< "\nAttack damame : " << _attackDamage
				<< std::endl;
}

std::string	DiamondTrap::getName(void) const{
	return _name;
}

unsigned int	DiamondTrap::getHitpoints(void) const{
	return _hitPoints;
}

unsigned int	DiamondTrap::getEnergypoints(void) const{
	return _energyPoints;
}

unsigned int	DiamondTrap::getAttackdamage(void) const{
	return _attackDamage;
}