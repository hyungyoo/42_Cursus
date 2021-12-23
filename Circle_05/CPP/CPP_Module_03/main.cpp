#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "----------- CONSTRUCTION ----------" << std::endl;
    ClapTrap test1("test1");
    ClapTrap test2;


    ClapTrap test3(test1);
    std::cout << "------------ GAME ----------" << std::endl;
    std::cout << "----------- attack ----------" << std::endl;
    test1.attack("chat");
    test2.attack("chien");
    test3.attack("lapin");
    std::cout << "----------- take damage ----------" << std::endl;
    test1.takeDamage(20);
    test2.takeDamage(0);
    test3.takeDamage(5);
    std::cout << "----------- be repaired ----------" << std::endl;
     test1.beRepaired(20);
    test2.beRepaired(0);
    test3.beRepaired(5);
    std::cout << "test2 is called " << test2.getName() << std::endl;
    std::cout << "----------- DESTRUCTION ----------" << std::endl;
}
