#include "../main.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << "#    operator a-   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;

	std::vector<int> rl_vector;
		for (int i=0; i<10; i++) rl_vector.push_back(i);
	std::cout << "rl_vector: ";
	for (size_t i = 0; i < rl_vector.size(); i++)
		std::cout << rl_vector[i] << ' ';
	std::cout << std::endl;


	typedef std::vector<int>::iterator iter_type;

	std::reverse_iterator<iter_type> rev_iterator;
	
	std::cout << "rl_vector.rend() points to the theoretical element preceding the first element in the vector (before 0)" << std::endl;

	rev_iterator = rl_vector.rend() - 3;

	std::cout << "rl_vector.rend() - 3 points to: " << *rev_iterator << '\n';
	std::cout << std::endl;
    return (0);
}