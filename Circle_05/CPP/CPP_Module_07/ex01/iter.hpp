#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/* class and function for test */
template<typename T>
class	Test
{
	public:
		Test(void) : _data(42) {}
		~Test(void) {}
		T	getData(void) const { return (this->_data); }
	private:
		T	_data;
};

std::ostream &operator<<(std::ostream &o, Test<int> const &rhs) { o << rhs.getData(); return (o); }

template<typename T>
void	execute(T const &a)
{
	std::cout << a << "_hello_42" << std::endl;
}

/* mandatory*/
template<typename T>
void	iter(T const *arr, unsigned int const size, void(*f)(T const &arr))
{
	unsigned int i(0);
	while (i < size)
	{
		(f)(arr[i]);
		i++;
	}
}

#endif
