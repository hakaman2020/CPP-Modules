#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

//Mutant stack is extending the stack class
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		//stack class is based on the deque class on default.
		//that class contains iterators 
		//to extend the stack class with iterators, we can use the built-in iterators of the 
		//deque object. We just need to expose it to the user. 

		//typedef to acces the iterators for more readability
		//typename to ensure the compiler it is an declaration;
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		//use the base class constructor and the mutantstack has nothing more than iterators so nothing else to set
		MutantStack():std::stack<T>() {}
		//use copy constructor of the base class
		MutantStack(MutantStack const & src): std::stack<T>(src){}
		//use the base class destructor
		virtual ~MutantStack(void){}
		
		//use the base class copy assignment this will set the internal stack object to the rhs stack object
		MutantStack & operator=(MutantStack const & rhs)
		{
			std::stack<T>::operator=(rhs);
			return *this;
		}

		iterator begin()
		{
			return std::stack<T>::c.begin();
		}
		
		const_iterator begin() const
		{
			return std::stack<T>::c.begin();
		}

		iterator end()
		{
			return std::stack<T>::c.end();
		}

		const_iterator end() const
		{
			return std::stack<T>::c.end();
		}

		reverse_iterator rbegin()
		{
			return std::stack<T>::c.rbegin();
		}

		const_reverse_iterator rbegin() const
		{
			return std::stack<T>::c.rbegin();
		}

		reverse_iterator rend()
		{
			return std::stack<T>::c.rend();
		}

		const_reverse_iterator rend() const
		{
			return std::stack<T>::c.rend();
		}
};
#endif