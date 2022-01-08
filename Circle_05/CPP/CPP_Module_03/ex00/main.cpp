#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "----------- CONSTRUCTION ----------" << std::endl;
    ClapTrap test1("test1");
    ClapTrap test2;
    ClapTrap test3(test1);

    std::cout << "------------ GAME ----------" << std::endl;
    std::cout << "----------- attack ----------" << std::endl;
    test1.attack("A");
    test2.attack("B");
    test3.attack("C");
    std::cout << "----------- take damage ----------" << std::endl;
    test1.takeDamage(20);
    test2.takeDamage(0);
    test3.takeDamage(5);
    std::cout << "----------- be repaired ----------" << std::endl;
	test1.beRepaired(20);
    test2.beRepaired(0);
    test3.beRepaired(5);
    
	std::cout << "----------- DESTRUCTION ----------" << std::endl;
	return (0);
}
