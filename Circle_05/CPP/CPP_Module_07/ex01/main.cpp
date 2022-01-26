#include "iter.hpp"

int	main(void)
{
	std::cout << "=====test with float=====" << std::endl;
	float arrF[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	iter(arrF, 5, execute);
	std::cout << std::endl;
	std::cout << "=====test with int=====" << std::endl;
	int	arrI[5] = {1, 2, 3, 4, 5};
	iter(arrI, 5, execute);
	std::cout << std::endl;
	std::cout << "=====test with class=====" << std::endl;
	Test<int> tab[5];
	iter(tab, 5, execute);

	return (0);
}
