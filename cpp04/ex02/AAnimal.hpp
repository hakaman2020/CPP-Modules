#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal{
	protected:

		std::string _type;

	public:

		AAnimal(std::string type = "animal");
		AAnimal(AAnimal const & src);
		AAnimal& operator=(AAnimal const & rhs);
		virtual ~AAnimal(void);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};
#endif