// assignment operator with maps
#include <iostream>

#include "../main.hpp"

int main ()
{
    {
        map<char,int> first;
        map<char,int> second;

        first['x']=8;
        first['y']=16;
        first['z']=32;

        second=first;                // second now contains 3 ints
        first=map<char,int>();  // and first is now empty

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }

    {
        /* Initializer_list constructor */
        map<char, int> m1;
        m1.insert(pair<char, int>('a', 1));
        m1.insert(pair<char, int>('b', 2));
        m1.insert(pair<char, int>('c', 3));
        m1.insert(pair<char, int>('d', 4));
        m1.insert(pair<char, int>('e', 5));

        map<char, int> m2 = m1;

        std::cout << "Map contains following elements" << std::endl;

        for (map<char, int>::iterator it = m2.begin(); it != m2.end(); ++it)
            std::cout << it->first << " = " << it->second << std::endl;
    }
  return 0;
}