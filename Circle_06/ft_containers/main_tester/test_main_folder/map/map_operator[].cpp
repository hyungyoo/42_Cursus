// accessing mapped values
#include <iostream>
#include <string>

#include "../main.hpp"

int main ()
{
    {
        map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
    {
        map<char, int> m;

        m.insert(pair<char, int>('a', 1));
        m.insert(pair<char, int>('b', 2));
        m.insert(pair<char, int>('c', 3));
        m.insert(pair<char, int>('d', 4));
        m.insert(pair<char, int>('e', 5));

        std::cout << "Map contains following elements" << std::endl;

        std::cout << "m['a'] = " << m['a'] << std::endl;
        std::cout << "m['b'] = " << m['b'] << std::endl;
        std::cout << "m['c'] = " << m['c'] << std::endl;
        std::cout << "m['d'] = " << m['d'] << std::endl;
        std::cout << "m['e'] = " << m['e'] << std::endl;
    }


    return 0;
}