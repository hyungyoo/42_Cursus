#include <string>
#include "iter.hpp"

int main()
{
    {
        std::string array[3] = {"string1", "string2", "string3"};
        iter(array, 3, sample_func<std::string>);
    }
    std::cout << "---------" << std::endl;
    {
        std::string array[3] = {"string1", "string2", "string3"};
        iter(array, 3, sample_func2<std::string>);
    }
    std::cout << "---------" << std::endl;
    {
        const int array[3] = {2, 1, 100};
        iter(array, 3, sample_func<const int>);
    }
}
