#include "../main.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << "#    operator a->   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;

	map<int,std::string> numbers;
	numbers.insert (make_pair(1,"one"));
	numbers.insert (make_pair(2,"two"));
	numbers.insert (make_pair(3,"three"));

	typedef map<int,std::string>::iterator map_iter;

	reverse_iterator<map_iter> rev_end (numbers.begin());

	reverse_iterator<map_iter> rev_iterator (numbers.end());

	for ( ; rev_iterator != rev_end ; ++rev_iterator )
		std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
	std::cout << std::endl;
	return (0);
}