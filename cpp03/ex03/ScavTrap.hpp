#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	private:

		bool _guardDuty;

	public:
		
		ScavTrap(std::string name = "Anon");
		ScavTrap(ScavTrap const & src);
		ScavTrap& operator=(ScavTrap const & rhs);
		~ScavTrap(void);

		void guardGate(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

		unsigned int	getEnergyPoints(void) const;
};
#endif