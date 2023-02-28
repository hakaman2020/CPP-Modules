#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# define DEFAULT_HITPOINTS 10
# define DEFAULT_ENERGYPOINTS 10
# define DEFAULT_ATTACKDAMAGE 0

class ClapTrap{
    protected:

        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;

    public:

        ClapTrap(std::string name = "Anon"); //default constructor with default arguments
		ClapTrap(std::string name, unsigned int hitpoints, unsigned int energypoints, unsigned int attackdamage);
        ClapTrap(ClapTrap const & src);
        ClapTrap& operator=(ClapTrap const & rhs);
        ~ClapTrap(void);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif