#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "----------- CONSTRUCTION ----------" << std::endl;
    std::cout << "===objet avec nom===" << std::endl;
    ClapTrap test1("test1");
    std::cout << "===objet sans nom===" << std::endl;
    ClapTrap test2;
    std::cout << "===objet copy===" << std::endl;
    ClapTrap test3(test1);

    std::cout << "------------ GAME ----------" << std::endl;
    std::cout << "----------- attack ----------" << std::endl;
    test1.attack("A");
    test2.attack("B");
    test3.attack("C");
    std::cout << "----------- take damage ----------" << std::endl;
    test1.takeDamage(30);
    test2.takeDamage(5);
    test3.takeDamage(3);
    std::cout << "----------- be repaired ----------" << std::endl;
    std::cout << "+20" << std::endl;
	test1.beRepaired(20);
    std::cout << "+2" << std::endl;
    test2.beRepaired(2);
    std::cout << "+1" << std::endl;
    test3.beRepaired(1);
    
	std::cout << "----------- DESTRUCTION ----------" << std::endl;
	return (0);
}
