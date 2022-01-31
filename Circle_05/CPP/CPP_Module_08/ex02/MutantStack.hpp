#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

/*
 * template<
    class T,
    class Container = std::deque<T>
	> class stack;
*/

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {}
		MutantStack(MutantStack const &copy) { (*this) = copy; }
		MutantStack	&operator=(MutantStack const &rhs) 
		{ 
			std::stack<T>::operator=(rhs); 
			return (*this);
		}
		~MutantStack(void) {}

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void) { return ((this->c).begin()); }
		iterator	end(void) { return ((this->c).end()); }
};

#endif
