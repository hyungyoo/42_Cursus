#include "../main.hpp"

int main()
{
		std::cout << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << "#    operator a-=   #" << std::endl;
	std::cout << "#####################" << std::endl;
	std::cout << std::endl;
	vector<int> rl_vector;
	for (int i=0; i<10; i++)
		rl_vector.push_back(i);	// rl_vector: 0 1 2 3 4 5 6 7 8 9
	std::cout << "rl_vector: ";
	for (size_t i = 0; i < rl_vector.size(); i++)
		std::cout << rl_vector[i] << ' ';
	std::cout << std::endl;


	typedef vector<int>::iterator iter_type;

	reverse_iterator<iter_type> rev_iterator = rl_vector.rend();

	std::cout << "rev_iterator points to rl_vector.rend(): which is before 0" << std::endl;

	rev_iterator -= 4;
	std::cout << "after rev_iterator -= 4..." << std::endl;
	std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
    return (0);
}