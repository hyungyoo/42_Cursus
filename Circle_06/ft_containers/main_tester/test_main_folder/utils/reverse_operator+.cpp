#include "../main.hpp"

int		main()
{
	std::cout << std::endl;
	std::cout << "####################" << std::endl;
	std::cout << "#    operator a+   #" << std::endl;
	std::cout << "####################" << std::endl;
	std::cout << std::endl;
	vector<int> rl_vector;
	for (int i=0; i<10; i++) rl_vector.push_back(i);

	std::cout << "rl_vector: ";
	for (size_t i = 0; i < rl_vector.size(); i++)
		std::cout << rl_vector[i] << ' ';
	std::cout << std::endl;

	typedef vector<int>::iterator iter_type;
	reverse_iterator<iter_type> rl_rev_it;

	std::cout << "rl_vector.rbegin(): " << *rl_vector.rbegin() << std::endl;

	rl_rev_it = rl_vector.rbegin() +3;
	std::cout << "The fourth element from the end is: " << *rl_rev_it << '\n';
	return (0);
}
