#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(DEFAULT_HITPOINTS), _energyPoints(DEFAULT_ENERGYPOINTS), _attackDamage(DEFAULT_ATTACKDAMAGE){
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src){
	*this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs){
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if(_energyPoints > 0 && _hitPoints > 0){
		_energyPoints--;
		std::cout << "ClapTrap " + _name + " attacks " + target +", causing " 
		<< _attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " + _name + " can't attack because it has no";
		if(_hitPoints == 0)
			std::cout << " hitpoints left" << std::endl;
		else if(_energyPoints == 0)
			std::cout << " energy left" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " + _name + " takes " << amount << " damage";
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

void	ClapTrap::beRepaired(unsigned int amount){
	if(_energyPoints > 0){
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " + _name + " has repaired itself and increased its hitpoints with "
		<< amount << " to a total of " << _hitPoints << std::endl;
	}
	else{
		std::cout << "ClapTrap " + _name + " don't have enough energy to repair itself"
		<< std::endl;
	}
}
