#include <vector>
#include <iostream>

#include "../main.hpp"

int main()
{
    vector<int> rlvector (3,100); // {100, 100, 100}
	vector<int>::iterator it;

	for (size_t i = 0; i < rlvector.size(); i++)
		std::cout << rlvector[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << rlvector.size() << std::endl;
	std::cout << "cap: " << rlvector.capacity() << std::endl;
	std::cout << std::endl;
	
	it = rlvector.begin(); //rlvector[0]=> 100
	it = rlvector.insert ( it + 2, 200 ); //begin()위치부터 200을 1회 insert후 이미 있던 value들은 뒤로 밀림
	std::cout << "*it value after: " << *it << std::endl;
	for (size_t i = 0; i < rlvector.size(); i++)
		std::cout << rlvector[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << rlvector.size() << std::endl;
	std::cout << "cap: " << rlvector.capacity() << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << ">>> std <<<" << std::endl;
	std::cout << std::endl;
	rlvector.insert (it + 1, 7, 0); 

	for (size_t i = 0; i < rlvector.size(); i++)
		std::cout << rlvector[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << rlvector.size() << std::endl;
	std::cout << "cap: " << rlvector.capacity() << std::endl;
	std::cout << std::endl;
	// "it" no longer valid, get a new one:
	it = rlvector.begin(); //
	std::cout << "new *it value after: " << *it << std::endl;

	vector<int> anothervector (15,400);
	rlvector.insert (it + 2, anothervector.begin(), anothervector.end());

	for (size_t i = 0; i < rlvector.size(); i++)
		std::cout << rlvector[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << rlvector.size() << std::endl;
	std::cout << "cap: " << rlvector.capacity() << std::endl;
	std::cout << std::endl;

	int myarray [] = { 501, 502, 503 };
	rlvector.insert (rlvector.begin(), myarray, myarray + 3);

	for (size_t i = 0; i < rlvector.size(); i++)
		std::cout << rlvector[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << rlvector.size() << std::endl;
	std::cout << "cap: " << rlvector.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "rlvector contains:";
	for (it=rlvector.begin(); it<rlvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';

    return (0);
}