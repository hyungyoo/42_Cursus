#include "../main.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << "#    operator a+=   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;

	vector<int> rl_vector;
		for (int i=0; i<10; i++) rl_vector.push_back(i);
	
	std::cout << "rl_vector: ";
	for (size_t i = 0; i < rl_vector.size(); i++)
		std::cout << rl_vector[i] << ' ';
	std::cout << std::endl;

	typedef vector<int>::iterator iter_type;

	reverse_iterator<iter_type> rev_iterator = rl_vector.rbegin();
	std::cout << "rl_vector.rbegin() is " << *rev_iterator << std::endl;

	rev_iterator += 2;
	std::cout << std::endl;
	std::cout << "after +=2 on rev_iterator..." << std::endl;
	std::cout << "rl_vector: The third element from the end is " << *rev_iterator << '\n';
	std::cout << std::endl;
    return (0);
}
