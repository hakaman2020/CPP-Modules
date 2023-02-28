#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30){
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src){
	*this = src;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs){
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " + _name + " is holding it's hands up and requesting a high five" << std::endl;
}

void	FragTrap::attack(const std::string& target){
	if(_energyPoints > 0 && _hitPoints > 0){
		_energyPoints--;
		std::cout << "FragTrap " + _name + " attacks " + target +", causing " 
		<< _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " + _name + " can't attack because it has no";
		if(_hitPoints == 0)
			std::cout << " hitpoints left" << std::endl;
		else if(_energyPoints == 0)
			std::cout << " energy left" << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount){
	std::cout << "FragTrap " + _name + " takes " << amount << " damage";
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

void	FragTrap::beRepaired(unsigned int amount){
	if(_energyPoints > 0){
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "FragTrap " + _name + " has repaired itself and increased its hitpoints with "
		<< amount << " to a total of " << _hitPoints << std::endl;
	}
	else{
		std::cout << "FragTrap " + _name + " don't have enough energy to repair itself"
		<< std::endl;
	}
}