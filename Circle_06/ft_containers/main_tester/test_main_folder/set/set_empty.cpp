// set::empty
#include <iostream>
#include "../main.hpp"

int main ()
{
    {
        std::set<int> myset;

        myset.insert(20);
        myset.insert(30);
        myset.insert(10);

        std::cout << "myset contains:";
        while (!myset.empty())
        {
            std::cout << ' ' << *myset.begin();
            myset.erase(myset.begin());
        }
        std::cout << '\n';
    }
    {
        std::set<int> numbers;
        std::cout << std::boolalpha;
        std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

        numbers.insert(42);
        numbers.insert(13317); 
        std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
    }

  return 0;
}