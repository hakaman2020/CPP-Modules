#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20), _guardDuty(false){
	std::cout << "ScavTrap Constructor called" << std::endl;
} 

ScavTrap::ScavTrap(ScavTrap const & src){
	*this = src;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs){
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	_guardDuty = rhs._guardDuty;
	return *this;
}
ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if(_energyPoints > 0 && _hitPoints > 0){
		_energyPoints--;
		std::cout << "ScavTrap " + _name + " attacks " + target +", causing " 
		<< _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " + _name + " can't attack because it has no";
		if(_hitPoints == 0)
			std::cout << " hitpoints left" << std::endl;
		else if(_energyPoints == 0)
			std::cout << " energy left" << std::endl;
	}
}

void	ScavTrap::guardGate(void){
	std::cout << "ScavTrap " + _name + " is now in Gate keeper mode" << std::endl;
	_guardDuty = true;
}

void	ScavTrap::takeDamage(unsigned int amount){
	std::cout << "ScavTrap " + _name + " takes " << amount << " damage";
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

void	ScavTrap::beRepaired(unsigned int amount){
	if(_energyPoints > 0){
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ScavTrap " + _name + " has repaired itself and increased its hitpoints with "
		<< amount << " to a total of " << _hitPoints << std::endl;
	}
	else{
		std::cout << "ScavTrap " + _name + " don't have enough energy to repair itself"
		<< std::endl;
	}
}
