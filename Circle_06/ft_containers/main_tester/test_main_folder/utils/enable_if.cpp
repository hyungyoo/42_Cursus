#include "../main.hpp"

// Test enable if
template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
is_odd(T i) { return bool(i % 2); }

int main()
{
    std::cout << "template <class T>" << std::endl;
    std::cout << "typename ft::enable_if<ft::is_integral<T>::value, bool>::type" << std::endl;
    std::cout << "is_odd(T i) { return bool(i % 2); }" << std::endl;

    std::cout << ">> this enable if check that type is integral or not. if argument isn't integral, code doesn't complie" <<std::endl;

    short int i = 1; // code does not compile if type of i is not integral
    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    return (0);
}