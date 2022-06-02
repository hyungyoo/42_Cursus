// vector::at
#include <iostream>
#include <vector>

#include "../main.hpp"

int main ()
{

	{
		vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}
	{
		vector<int> data(6, 6);
		data.at(1) = 88;
		std::cout << "Element at index 2 has value " << data.at(2) << std::endl;
		std::cout << "data size = " << data.size() << std::endl;
		try
		{
			data.at(5) = 666;
		}
		catch (std::out_of_range const &exc)
		{
			std::cout << exc.what() << std::endl;
		}
		std::cout << "data: " << std::endl;
		vector<int>::iterator it = data.begin();
		vector<int>::iterator ite = data.end();
		while (it != ite)
		{
			std::cout << (*it) << " ";
			it++;
		}
		std::cout << std::endl;
	}

  return 0;
}