#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
	public:

		Dog(std::string type = "dog");
		Dog(Dog const & src);
		Dog& operator=(Dog const & rhs);
		virtual ~Dog(void);
		
		virtual void	makeSound(void) const;
};
#endif