#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
	protected:

		std::string _type;

	public:

		Animal(std::string type = "animal");
		Animal(Animal const & src);
		Animal& operator=(Animal const & rhs);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};
#endif