#include "../main.hpp"

int main()
{
    pair<int, int> foo;
    pair<int, int> bar;

    std::cout << "foo = make_pair(10, 20)" << std::endl;
    std::cout << "bar = make_pair(10.5, 'A')" << std::endl;
    foo = make_pair(10, 20);
    bar = make_pair(10.5, 'A');
    std::cout << "foo: " << foo.first << ", " << foo.second << std::endl;
    std::cout << "bar: " << bar.first << ", " << bar.second << std::endl;
    return (0);
}