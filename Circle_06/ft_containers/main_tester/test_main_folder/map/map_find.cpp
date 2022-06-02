// map::find
#include <iostream>
#include "../main.hpp"

int main ()
{
    map<char,int> mymap;
    map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;
    std::cout << "mymap contains" << std::endl;
    for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
    std::cout << std::endl;

    std::cout << "find and erase 'b' key" << std::endl;
    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    // print content:
    std::cout << "elements in mymap after" << '\n';
    for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
    std::cout << std::endl;

    return 0;
}