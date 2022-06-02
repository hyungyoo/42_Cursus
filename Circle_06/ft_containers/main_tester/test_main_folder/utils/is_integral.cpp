#include "../main.hpp"

int	main() 
{
	std::cout << std::boolalpha; //true false in alphabet (instead of 1/0)
	std::cout << "is_integral:" << std::endl;
	std::cout << "my bool: " << ft::is_integral<bool>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my int: " << ft::is_integral<int>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my char: " << ft::is_integral<char>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my wchar_t: " << ft::is_integral<wchar_t>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my signed char: " << ft::is_integral<signed char>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my short int: " << ft::is_integral<short int>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my long int: " << ft::is_integral<long int>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my long long int: " << ft::is_integral<long long int>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my unsigned char: " << ft::is_integral<unsigned char>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my unsigned short int: " << ft::is_integral<unsigned short int>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my unsigned int: " << ft::is_integral<unsigned int>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my unsigned long int: " << ft::is_integral<unsigned long int>::value << std::endl;
	std::cout << std::endl;
	std::cout << "my unsigned long long int: " << ft::is_integral<unsigned long long int>::value << std::endl;
	std::cout << std::endl;
    return (0);

}