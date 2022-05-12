#include <iostream>
#include "../inc/reverse_iterator.hpp"
#include "../inc/utils.hpp"
#include "../inc/iterator_traits.hpp"
#include <vector>
//#include <iterator>


typedef std::vector<int>::iterator iter_type;
typedef ft::reverse_iterator<iter_type> rIter;

static void	constructor(rIter rev_from, rIter rev_until)
{
	std::cout << "myvector avec mon reverse_iterator:";
	while (rev_from != rev_until)
	{
		std::cout << ' ' << *rev_from;
		rev_from++;
	}
	std::cout << '\n';
	
	std::cout << "myvector avec std reverse_iterator:";
	std::cout << " 9 8 7 6 5 4 3 2 1 0" << std::endl;
}

static void base(rIter rev_begin, rIter rev_end)
{
	std::cout << "myvector avec mon reverse_iterator:";
	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "myvector avec std reverse_iterator:";
	std::cout << " 0 1 2 3 4 5 6 7 8 9" << std::endl;
}

void	printTestname(std::string const s)
{
	std::cout << "=====";
	std::cout << s;
	std::cout << "=====" << std::endl;
}

#include <map>
void	operator_flesh(void)
{
	std::map<int,std::string> numbers;
	numbers.insert (std::make_pair(1,"one"));
	numbers.insert (std::make_pair(2,"two"));
	numbers.insert (std::make_pair(3,"three"));

	typedef std::map<int,std::string>::iterator map_iter;
	ft::reverse_iterator<map_iter> rev_end (numbers.begin());
	ft::reverse_iterator<map_iter> rev_iterator (numbers.end());
	for ( ; rev_iterator != rev_end ; ++rev_iterator )
		std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';

}

void	test_reverse_iterator(void)
{
	std::vector<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);
	iter_type from (myvector.begin());
	iter_type until (myvector.end());
	
	rIter	rev_until (from);
	rIter	 rev_from (until);

	printTestname("constructor, operator *-+--++...");
	constructor(rev_from, rev_until);
	printTestname("base");
	base(rev_from, rev_until);
	printTestname("operator[]");

	std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();
	std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
	operator_flesh();
}
