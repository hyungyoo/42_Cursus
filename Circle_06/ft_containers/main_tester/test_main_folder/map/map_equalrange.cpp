// map::equal_range
#include <iostream>
#include "../main.hpp"

int main ()
{
	map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	std::cout << "mymap contains" << std::endl;
	for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << std::endl;

	std::cout << "ret = mymap.equal_range('b') => lower_bound in ret.first(b), upper_bound in ret.second(c)" <<std::endl;
	pair<map<char,int>::iterator, map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to => ";
	std::cout << ret.first->first << " : " << ret.first->second << '\n';
	//				key								value					of lower_bound

	std::cout << "upper bound points to => ";
	std::cout << ret.second->first << " : " << ret.second->second << '\n';
	//				key								value					of upper_bound

	return 0;
}