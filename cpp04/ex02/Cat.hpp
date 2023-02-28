#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal{
	private:
	
		Brain * brain;

	public:

		Cat(std::string type = "cat");
		Cat(Cat const & src);
		Cat& operator=(Cat const & rhs);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
		std::string		getIdea(int index) const;
		void			insertIdea(std::string idea);
		void			displayBrain(void) const;
};

#endif