#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:

		WrongCat(std::string type = "wrongcat");
		WrongCat(WrongCat const & src);
		WrongCat& operator=(WrongCat const & rhs);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif