// map::max_size
#include <iostream>
#include <locale>

#include "../main.hpp"

int main ()
{
	{
		int i;
		map<int,int> mymap;

		std::cout << mymap.max_size() << std::endl;

		if (mymap.max_size()>1000)
		{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";
	}
	{
		map<char, char> q;
		std::cout.imbue(std::locale("en_US.UTF-8"));    
		std::cout << "Maximum size of a map is " << q.max_size() << '\n';
	}

  return 0;
}