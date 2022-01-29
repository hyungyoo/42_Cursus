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
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error(std::string("not found"));
	//std::cout << *it << std::endl; 
	//std::cout << *(container.end()) << std::endl;
	return (it);
}

#endif
