// map::clear
#include <iostream>
#include "../main.hpp"

int main ()
{
    map<char,int> mymap;

    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;

    std::cout << "before clear" << std::endl;
    std::cout << "mymap contains:\n";
    for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << std::endl;

    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;

    std::cout << "after clear with two keys inserted" << std::endl;
    std::cout << "mymap contains:\n";
    for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

  return 0;
}