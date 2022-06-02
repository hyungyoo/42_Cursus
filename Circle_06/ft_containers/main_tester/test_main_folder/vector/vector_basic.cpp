
#include "../main.hpp"

int main()
{
//Testing dynamic array
    std::cout << "Testing dynamic size" << std::endl;
    std::cout << "-------" << std::endl;
    vector<int> vec(1);
    std::cout << "Size is : " << vec.size() << std::endl;
    vec.push_back(1);
    std::cout << "Size is : " << vec.size() << std::endl;
    vec.pop_back();
    std::cout << "-------" << std::endl;
    //iterator should be comparable
    vector<int>::iterator it = vec.begin();
    vector<int>::const_iterator const_it = vec.begin();
    std::cout << "Are const iterator and iterators comparable ? " << (it == const_it) << std::endl;
    std::cout << "-------" << std::endl;
    //Demo de la dynamic size
    std::cout << "Dyamic reallocation system : " << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "Capacity is " << vec.capacity() << std::endl;
    vec.push_back(5);
    std::cout << "Capacity is " << vec.capacity() << std::endl;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    std::cout << "Capacity is " << vec.capacity() << std::endl;
    std::cout << "-------" << std::endl;
    std::cout << "Pour tester les iterateurs voir les tests plus complets." << std::endl;
    std::cout << "-------" << std::endl;
    return (0);
}