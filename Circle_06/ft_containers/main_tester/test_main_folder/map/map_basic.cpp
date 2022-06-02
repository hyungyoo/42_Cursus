#include "../main.hpp"

int main()
{
	std::cout << "Testing pair : " << std::endl;
	pair<int, char> mypair;
	mypair.first = 1;
	mypair.second = 'a';
	std::cout << "Pair first is : " << mypair.first << ", pair second is : " << mypair.second << std::endl;
	std::cout << "Testing pair OK !" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "Testing make pair :" << std::endl;

	pair<int, int> foo;
	pair<int, int> bar;

	foo = make_pair(1, 2);
	bar = make_pair(3, 4);

	std::cout << "foo: " << foo.first << ", " << foo.second << std::endl;
	std::cout << "bar: " << bar.first << ", " << bar.second << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "Checking if keys are unique : " << std::endl;
	map<int, int> mymap;
	mymap.insert(pair<int, int>(1, 10));
	std::cout << "Adding 1, 10 successfully." << std::endl;
	mymap.insert(pair<int, int>(-2, -20));
	std::cout << "Adding 2, -20 successfully." << std::endl;
	mymap.insert(pair<int, int>(0, 0));
	std::cout << "Adding 0, 0 successfully." << std::endl;
	mymap.insert(pair<int, int>(1, -20));
	std::cout << "Tried to add 1, -20" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "Let's check if it was added : " << std::endl;
	map<int, int>::iterator it = mymap.begin();
	map<int, int>::iterator ite = mymap.end();
	int check = (*it).first;
	while (it != ite)
	{
		if (check > (*it).first)
		{
			std::cout << "Error, the map is not ordered !" << std::endl; //will never happen
		}
		check = (*it).first;
		std::cout << "First is : " << (*it).first << ", second is : " << (*it).second << std::endl;
		it++;
	}
	std::cout << "-------" << std::endl;
	std::cout << "Wow, the map is ordered as well !" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << std::endl;
	std::cout << "For further iterator test use the tester." << std::endl;
	std::cout << "Testing if swap is moving pointers and not data :" << std::endl;
	std::cout << std::endl;
	//A montrer en correction car ca va faire forcement une diff
	map<int, int> map1;
	map1.insert(bar);
	map<int, int>::iterator it1 = map1.begin();
	map<int, int> map2;
	map2.insert(foo);
	map<int, int>::iterator it2 = map2.begin();
	swap(map1, map2);
	std::cout << (it1 == map2.begin()) << std::endl;
	std::cout << (it2 == map1.begin()) << std::endl;
	return (0);
}