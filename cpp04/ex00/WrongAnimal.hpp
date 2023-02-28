#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{
	protected:

		std::string _type;

	public:

		WrongAnimal(std::string type = "wronganimal");
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal& operator=(WrongAnimal const & rhs);
		~WrongAnimal(void);

		void	makeSound(void) const;
		std::string		getType(void) const;
};
#endif