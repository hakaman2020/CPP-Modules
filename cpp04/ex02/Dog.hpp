#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal{
	private:

		Brain* brain;

	public:

		Dog(std::string type = "dog");
		Dog(Dog const & src);
		Dog& operator=(Dog const & rhs);
		virtual ~Dog(void);
		
		virtual void	makeSound(void) const;
		std::string		getIdea(int index) const;
		void			insertIdea(std::string idea);
		void			displayBrain(void) const;
};
#endif