#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class	Array
{
	private:
		unsigned int	_n;
		T	*_arr;
	
	public:
		class	OutOfBound : public std::exception
		{
			public:
				const char *what(void) const throw() { return ("out of bound"); }
		};
		
		Array(void) : _arr(NULL), _n(0)	{}
		Array(unsigned int n) : _arr(new T[n]), _n(n) {}
		Array(Array const &copy)
		{
			this->_n = copy.size();
			if (this->size())
				this->_arr = new T[this->size()];
			for (unsigned int i = 0;i < this->size(); i++)
				this->_arr[i] = copy._arr[i];
		}
		Array	&operator=(Array const &rhs)
		{
			unsigned int i(0);
			if (this->size())
				delete[] this->_arr;
			this->_n = rhs.size();
			this->_arr = new T[this->size()];
			while (i < this->size())
			{
				this->_arr[i] = rhs._arr[i];
				i++;
			}
			return (*this);
		}
		~Array(void)
		{
			if (this->_arr)
				delete[] this->_arr;
		}
		T	&operator[](unsigned int const index)
		{
			if (index >= this->size())
				throw (OutOfBound());
			return (this->_arr[index]);
		}
		const T	&operator[](unsigned int const index) const
		{
			if (index >= this->size())
				throw (OutOfBound());
			return (this->_arr[index]);
		}
		unsigned int	size(void) const { return (this->_n); }
};

#endif
