#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const &min(T const &a, T const &b)
{
	if (a >= b)
		return (b);
	return (a);
}

template<typename T>
T const &max(T const &a, T const &b)
{
	if (a <= b)
		return (b);
	return (a);
}

#endif
