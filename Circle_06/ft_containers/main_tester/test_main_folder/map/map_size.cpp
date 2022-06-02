// map::size
#include <iostream>

#include "../main.hpp"

int main ()
{
    {
        map<char,int> mymap;
        mymap['a']=101;
        mymap['b']=202;
        mymap['c']=302;

        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }
    {
        map<char, int> m;

        std::cout << "Initial size of map = " << m.size() << std::endl;
        m.insert(make_pair('a',1));
        m.insert(make_pair('b',2));
        m.insert(make_pair('c',3));
        m.insert(make_pair('d',4));
        m.insert(make_pair('e',5));
        
        std::cout << "Size of map after inserting elements = " << m.size() << std::endl;
    }

  return 0;
}