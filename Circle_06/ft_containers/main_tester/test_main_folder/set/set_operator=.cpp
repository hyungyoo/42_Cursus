// assignment operator with sets
#include <iostream>
#include "../main.hpp"

void print(std::string const comment, set<int> const& container)
{
    size_t size = container.size();
    std::cout << comment << "{ ";
	for (set<int>::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << (--size ? ", " : " ");
    std::cout << "}\n";
}

int main ()
{
	{
		int myints[]={ 12,82,37,64,15 };
		set<int> first (myints,myints+5);   // set with 5 ints
		set<int> second;                    // empty set

		second = first;                          // now second contains the 5 ints
		first = set<int>();                 // and first is empty

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	}
	{
		set<int> x;
		x.insert(1);
		x.insert(2);
		x.insert(3);
		
		set<int> y;
		set<int> w;
		w.insert(4);
		w.insert(5);
		w.insert(6);
		w.insert(7);

		std::cout << "Initially:\n";
		print("x = ", x);
		print("y = ", y);
		print("z = ", w);

		std::cout << "Copy assignment copies data from x to y:\n";
		y = x;
		print("x = ", x);
		print("y = ", y);

	}
	return 0;
}