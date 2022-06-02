// map::begin/end
#include <iostream>

#include "../main.hpp"

int main ()
{
    //map::begin/end
    {
        map<char,int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        // show content:
        std::cout << "Map contains following elements with begin/end" << std::endl;
        for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    //map::rbegin/rend
    {
        map<char,int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        std::cout << "Map contains following elements with rbegin/rend" << std::endl;
        map<char,int>::reverse_iterator rit;
        for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }

    return 0;
}