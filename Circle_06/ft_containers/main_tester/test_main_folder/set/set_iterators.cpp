// set::begin/end
#include <iostream>
#include "../main.hpp"

int main ()
{
	//begin, end
	{
		int myints[] = {75,23,65,42,13};
		set<int> myset (myints,myints+5);

		std::cout << "myset contains:";
		for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	//rbegin, rend
	{
		int myints[] = {21,64,17,78,49};
		set<int> myset (myints,myints+5);

		set<int>::reverse_iterator rit;

		std::cout << "myset contains:";
		for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
			std::cout << ' ' << *rit;

		std::cout << '\n';
	}

  return 0;
}