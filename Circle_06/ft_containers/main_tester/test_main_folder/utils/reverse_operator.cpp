#include "../main.hpp"

int main()
{
	std::cout << "####################################" << std::endl;
	std::cout << "#    constructors, base, *a, a++   #" << std::endl;
	std::cout << "####################################" << std::endl;
	std::cout << std::endl;
	vector<int> rl_vector;
	for (int i=0; i<10; i++)
		rl_vector.push_back(i);

	std::cout << "rl_vector: ";
	for (size_t i = 0; i < rl_vector.size(); i++)
		std::cout << rl_vector[i] << ' ';
	std::cout << std::endl;

	typedef vector<int>::iterator iter_type;
	iter_type rl_from (rl_vector.begin());
	iter_type rl_until (rl_vector.end());
	reverse_iterator<iter_type> rl_rev_until (rl_from);
	reverse_iterator<iter_type> rl_rev_from (rl_until);

	std::cout << "rl_vector:";
	while (rl_rev_from != rl_rev_until)
		std::cout << ' ' << *rl_rev_from++;
	std::cout << '\n';
	std::cout << std::endl;
    return (0);
}
