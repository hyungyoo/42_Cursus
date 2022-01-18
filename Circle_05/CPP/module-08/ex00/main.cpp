#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    const int a[] = {1, 0, 2, -1, 3};

    {
        std::vector<int> vec(a, a + 5);
        const int v = 0;
        std::cout << "v = " << v << '\n';
        std::vector<int>::iterator it = easyfind(vec, v);
        if (it != vec.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
    std::cout << "------------\n";
    {
        std::vector<int> vec(a, a + 5);
        const int v = 10;
        std::cout << "v = " << v << '\n';
        std::vector<int>::iterator it = easyfind(vec, v);
        if (it != vec.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
    std::cout << "------------\n";
    {
        const std::vector<int> vec(a, a + 5);
        const int v = 2;
        std::cout << "v = " << v << '\n';
        std::vector<int>::const_iterator it = easyfind(vec, v);
        if (it != vec.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
    std::cout << "------------\n";
    {
        std::list<int> lst(a, a + 5);
        const int v = 2;
        std::cout << "v = " << v << '\n';
        const std::list<int>::const_iterator it = easyfind(lst, v);
        if (it != lst.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
}
