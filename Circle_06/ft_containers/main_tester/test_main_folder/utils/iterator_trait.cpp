#include <typeinfo>
#include "../main.hpp"

int main()
{
    typedef ft::iterator_traits<int *> traits;
    if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
        std::cout << "int* is a random-access iterator" << std::endl;
    if (typeid(traits::iterator_category) == typeid(std::input_iterator_tag))
        std::cout << "int* is an input_iterator_tag" << std::endl;
    if (typeid(traits::iterator_category) == typeid(std::output_iterator_tag))
        std::cout << "int* is a output_iterator_tag" << std::endl;
    if (typeid(traits::iterator_category) == typeid(std::forward_iterator_tag))
        std::cout << "int* is a forward_iterator_tag" << std::endl;
    if (typeid(traits::iterator_category) == typeid(std::bidirectional_iterator_tag))
        std::cout << "int* is a bidirectional_iterator_tag" << std::endl;
    return (0);
}