#include "Base.hpp"

int	main(void)
{
	std::cout << "=====generate=====" << std::endl;
	Base *ptr = generate();
	std::cout << "=====idnentify ptr=====" << std::endl;
	identify(ptr);
	std::cout << "=====idnentify ref=====" << std::endl;
	identify(*ptr);
	std::cout << std::endl << std::endl;
	delete ptr;
	return (0);
}
