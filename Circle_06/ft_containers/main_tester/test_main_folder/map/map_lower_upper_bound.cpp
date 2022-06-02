// map::lower_bound/upper_bound
#include <iostream>
#include "../main.hpp"

int main ()
{
	map<char,int> mymap;
	map<char,int>::iterator itlow, itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;
	std::cout << "mymap contains" << std::endl;
	for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << std::endl;

	std::cout << "itlow = lower_bound('b') and itup = upper_bound('d')" << std::endl;
	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup = mymap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << "erase from itlow(b) to itup(e) // so erase b, c, d " << std::endl;
	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

  return 0;
}