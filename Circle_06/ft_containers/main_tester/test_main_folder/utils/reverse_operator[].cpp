#include "../main.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << "#    operator a[]   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;
	vector<int> rl_vector;
	for (int i=0; i<10; i++)
		rl_vector.push_back(i);  // rl_vector: 0 1 2 3 4 5 6 7 8 9
	std::cout << "rl_vector: ";
	for (size_t i = 0; i < rl_vector.size(); i++)
		std::cout << rl_vector[i] << ' ';
	std::cout << std::endl;

	typedef vector<int>::iterator iter_type;

	reverse_iterator<iter_type> rev_iterator = rl_vector.rbegin();
	reverse_iterator<iter_type> tmp = rev_iterator;

	std::cout << "rl_vector reverse: ";
	while (tmp != rl_vector.rend())
		std::cout << *tmp++ << " ";
	std::cout << std::endl; 

	std::cout << "result of rl_vector: " << std::endl;
	std::cout << "The fourth element(rev[3]) from the end is: " << rev_iterator[3] << '\n';
	return (0);
}
