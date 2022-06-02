// map::insert (C++98)
#include <iostream>

#include "../main.hpp"

int main ()
{
    map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( pair<char,int>('a',100) );
    mymap.insert ( pair<char,int>('z',200) );
    mymap.insert ( pair<char, int>('d', 4) );
    mymap.insert ( pair<char, int>('e', 5) );

    pair<map<char,int>::iterator,bool> ret;

    ret = mymap.insert ( pair<char,int>('z',500) );
    
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    map<char,int>::iterator it = mymap.begin();
    
    mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting
    mymap.insert(mymap.begin(), pair<char, int>('a', 1));
    mymap.insert(mymap.end(), pair<char, int>('e', 5));

    // third insert function version (range insertion):
    map<char,int> anothermap;
    
    anothermap.insert(mymap.begin(),mymap.find('c'));


    // showing contents:
    std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    return 0;
}