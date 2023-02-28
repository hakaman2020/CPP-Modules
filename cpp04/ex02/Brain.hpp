#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define BRAIN_SIZE 100 


class Brain{
	private:

		std::string _ideas[BRAIN_SIZE];
		static int _index;

	public:

		Brain(void);
		Brain(Brain const & src);
		Brain& operator=(Brain const & rhs);
		~Brain(void);
		
		unsigned int	getBrainsize(void) const;
		bool			insertIdea(std::string idea, unsigned int index);
		void			addIdea(std::string idea);
		std::string		getIdea(int index) const;
		void			displayBrain(void) const;
};
#endif
