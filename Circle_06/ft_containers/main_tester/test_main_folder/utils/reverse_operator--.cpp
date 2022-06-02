#include "../main.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << "#    operator a--   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;
	vector<int> rl_vector;
		for (int i=0; i<10; i++) rl_vector.push_back(i);

	typedef vector<int>::iterator iter_type;

	reverse_iterator<iter_type> rev_begin (rl_vector.end());
	reverse_iterator<iter_type> rev_end (rl_vector.begin());

	std::cout << "rl_vector reverse: ";
	reverse_iterator<iter_type> rev_iterator = rev_begin;
	while ( rev_iterator != rev_end )
		std::cout << *rev_iterator++ << ' ';
	std::cout << '\n';

	std::cout << "rl_vector decreament test with operator--: ";
	while ( rev_iterator != rev_begin )
		std::cout << *(--rev_iterator) << ' ';
	std::cout << '\n';
	return (0);
}