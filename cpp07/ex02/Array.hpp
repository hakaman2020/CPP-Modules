#ifndef	ARRAY_HPP
# define ARRAY_HPP
# include <stdexcept>

template <typename T>
class Array{
	private:

		unsigned int	_size;
		T* 				_data;

	public:

		Array(void)
		{
			_data = NULL;
			_size = 0;
		}

		Array(Array const & src)
		{
			*this = src;
		}

		Array(unsigned int size)
		{
			_size = size;
			_data = new T[size];
		}

		Array& operator=(Array const & rhs)
		{
			_size = rhs.size();
			if (_data != NULL)
				delete [] _data; 
			_data = new T[_size];
			for(unsigned int i = 0; i < _size; ++i)
			{
				this->_data[i] = rhs._data[i];
			}
			return *this;
		}

		~Array(void)
		{
			delete [] _data;
		}

		unsigned int	size(void) const
		{
			return _size;
		}

		T & operator[](unsigned i) const
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _data[i];
		}
};

#endif