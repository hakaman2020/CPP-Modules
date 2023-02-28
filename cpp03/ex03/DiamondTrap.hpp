#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
	private:
		
		std::string _name;

	public:

		DiamondTrap(std::string name= "Anon");
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap& operator=(DiamondTrap const & rhs);
		~DiamondTrap(void);

		void	attack(std::string & target);
		void	whoAmI(void) const;

		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	otherInfo(void) const;

		std::string		getName(void) const;
		unsigned int	getHitpoints(void) const;
		unsigned int	getEnergypoints(void) const;
		unsigned int	getAttackdamage(void) const;
};

#endif
