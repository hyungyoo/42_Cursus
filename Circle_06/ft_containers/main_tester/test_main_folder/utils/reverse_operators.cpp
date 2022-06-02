#include "../main.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "#   non-member function: relational operators    #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << std::endl;

	vector<int> test1;
	for (size_t i = 0; i < 10; i++)
		test1.push_back(i);
	
	vector<int> test2;
	for (size_t i = 0; i < 10; i++)
		test2.push_back(i);

	std::cout << "vector test1: ";
	for (size_t i = 0; i < test1.size(); i++)
		std::cout << test1[i] << " ";
	std::cout << std::endl;

	std::cout << "vector test2: ";
	for (size_t i = 0; i < test2.size(); i++)
		std::cout << test2[i] << " ";
	std::cout << std::endl;

	vector<int>::iterator it1_begin;
	vector<int>::iterator it1_end;
	vector<int>::iterator it2_begin;
	vector<int>::iterator it2_end;
	
	it1_begin = test1.begin();
	it1_end = test1.end();
	it2_begin = test2.begin();
	it2_end = test2.end();

	reverse_iterator<vector<int>::iterator> r1_begin(it1_end);
	reverse_iterator<vector<int>::iterator> r1_end(it1_begin);
	reverse_iterator<vector<int>::iterator> r2_begin(it2_end);
	reverse_iterator<vector<int>::iterator> r2_end(it2_begin);
	reverse_iterator<vector<int>::iterator> tmp1(r1_begin);
	reverse_iterator<vector<int>::iterator> tmp2(r2_begin);

	std::cout << "rev vector test1: ";
	for (size_t i = 0; tmp1 != r1_end; tmp1++)
		std::cout << r1_begin[i++] << " ";
	std::cout << std::endl;

	std::cout << "rev vector test2: ";
	for (size_t i = 0; tmp2 != r2_end; tmp2++)
		std::cout << r2_begin[i++] << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "<< reverse iter test1, test2 comparison >>" << std::endl;
	std::cout << std::endl;
	std::cout << "test1 == test2 ?" << std::endl;
	if (r1_begin == r2_begin)
		std::cout << "test1 and test2 is the same reverse_iter" << std::endl;
	else
		std::cout << "test1 and test2 is different reverse_iter" << std::endl;
	
	std::cout << std::endl;
	std::cout << "test1[5] != test2[2] ?" << std::endl;
	if (r1_begin[5] != r1_begin[2])
		std::cout << "different reverse_iter" << std::endl;
	else
		std::cout << "same reverse_iter" << std::endl;
	std::cout << std::endl;

	std::cout << "test1[6] > test2[1] ?" << std::endl;
	if (r1_begin[6] > r2_begin[1])
		std::cout << "test1[6] one is bigger" << std::endl;
	else
		std::cout << "test2[1] one is bigger" << std::endl;
	std::cout << std::endl;

	std::cout << "test1[6] < test2[1] ?" << std::endl;
	if (r1_begin[6] < r2_begin[1])
		std::cout << "test1[6] one is smaller" << std::endl;
	else
		std::cout << "test2[1] one is smaller" << std::endl;
	std::cout << std::endl;

	std::cout << "test1[4] <= test2[4] ?" << std::endl;
	if (r1_begin[4] <= r2_begin[4])
		std::cout << "test1[4] is smaller or same as test2[4]" << std::endl;
	else
		std::cout << "test1[4] is bigger" << std::endl;
	std::cout << std::endl;

	std::cout << "test1[6] >= test2[2] ?" << std::endl;
	if (r1_begin[6] >= r2_begin[2])
		std::cout << "test1[6] is bigger or same as test2[2]" << std::endl;
	else
		std::cout << "test1[6] is smaller" << std::endl;
    return (0);
}