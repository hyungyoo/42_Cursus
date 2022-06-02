// erasing from map
#include <iostream>
#include "../main.hpp"

int main ()
{
    map<char,int> mymap;
    map<char,int>::iterator it;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    std::cout << "before erase" <<std::endl;
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "find 'b' key in mymap and put it into iterator 'it'" <<std::endl;
    it=mymap.find('b');
    std::cout << "then erase 'it' (erasing by iterator)" <<std::endl;
    mymap.erase (it);                   // erasing by iterator

    std::cout << "then erase 'c' key (erasing by key)" <<std::endl;
    mymap.erase ('c');                  // erasing by key

    std::cout << "find 'e' key in mymap and put it into iterator 'it'" <<std::endl;
    it=mymap.find ('e');
    std::cout << "then erase from 'it' to mymap.end() (erasing by range))" <<std::endl;
    mymap.erase ( it, mymap.end() );    // erasing by range

    // show content:
    std::cout << "after erase" <<std::endl;
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

  return 0;
}