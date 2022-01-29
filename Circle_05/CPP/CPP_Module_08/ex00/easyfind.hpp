#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <deque>
# include <set>
# include <map>

template<typename T>
typename T::iterator	easyfind(T	&container, int value)
{
	// std::vector<T>::iterator is a dependent name, so you need a typename here to specify that it refers to a type. Otherwise it is assumed to refer to a non-type
	// https://stackoverflow.com/questions/20934311/c-template-stdvectoriterator-error
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error(std::string("not found"));
	//std::cout << *it << std::endl; 
	//std::cout << *(container.end()) << std::endl;
	return (it);
}

#endif
