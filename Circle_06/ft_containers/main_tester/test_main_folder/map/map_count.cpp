// map::count
#include <iostream>
#include "../main.hpp"

int main ()
{
    map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;
    std::cout << "mymap contains" << std::endl;
    for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
    std::cout << std::endl;

    for (c = 'a'; c < 'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c) > 0)
            std::cout << " is an element of mymap.\n";
        else 
            std::cout << " is not an element of mymap.\n";
    }

  return 0;
}