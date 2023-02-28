#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public:
		FragTrap(std::string name="Anon");
		FragTrap(FragTrap const & src);
		FragTrap& operator=(FragTrap const & rhs);
		~FragTrap(void);
 		
		void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
		void	highFivesGuys(void) const;
		
		unsigned int getHitpoints(void) const;
		unsigned int getAttackDamage(void) const;
};


#endif