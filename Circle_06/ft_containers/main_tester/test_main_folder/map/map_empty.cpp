// map::empty
#include <iostream>

#include "../main.hpp"

int main ()
{
	{
		map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	{
		map<char, int> m;

		if (m.empty())
		std::cout << "Map is empty" << std::endl;

		m.insert(pair<char, int>('a', 1));

		if (!m.empty())
		std::cout << "Map is not empty" << std::endl;
	}
	{
		map<int,int> numbers;
		std::cout << std::boolalpha;
		std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

		numbers.insert(make_pair(13317, 123)); 
		std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
	}

  return 0;
}