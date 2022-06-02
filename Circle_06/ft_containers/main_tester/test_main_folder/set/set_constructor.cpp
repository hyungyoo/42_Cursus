// constructing sets
#include <iostream>

#include "../main.hpp"

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};
 
int main ()
{
	{
		set<int> first;                           // empty set of ints

		int myints[]= {10,20,30,40,50};
		set<int> second (myints,myints+5);        // range

		set<int> third (second);                  // a copy of second

		set<int> fourth (second.begin(), second.end());  // iterator ctor.

		set<int,classcomp> fifth;                 // class as Compare

		bool(*fn_pt)(int,int) = fncomp;
		set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
	}
	{
		// (1) Default constructor
		set<std::string> a;
		a.insert("cat");
		a.insert("dog");
		a.insert("horse");
		for (set<std::string>::iterator it = a.begin(); it != a.end(); it++)
			std::cout << *it << ' ';
		std::cout << '\n';
		
		// (2) Iterator constructor
		set<std::string> b(a.find("dog"), a.end());
		for (set<std::string>::iterator it = b.begin(); it != b.end(); it++)
			std::cout << *it << ' ';
		std::cout << '\n';
		
		// (3) Copy constructor
		set<std::string> c(a);
		c.insert("another horse");
		for (set<std::string>::iterator it = c.begin(); it != c.end(); it++)
			std::cout << *it << ' ';
		std::cout << '\n';
	}

  return 0;
}