#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	/*
    std::cout << "----------- CONSTRUCTION ----------" << std::endl << std::endl;
	std::cout << "contructor" << std::endl;
	ClapTrap test1("test1");
	std::cout << "contructor" << std::endl;
    ClapTrap test2;
	std::cout << "contructor" << std::endl;
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
	*/

    std::cout <<std::endl << std::endl << "-----------  ScavTrap  ----------" << std::endl << std::endl;

    std::cout << "----------- CONSTRUCTION ----------" << std::endl;
    std::cout << "----------- construction dans l'ordre de contreverse de stack ----------" << std::endl;
	std::cout << "===contructor with name===" << std::endl;
	ScavTrap test4("test4");
	std::cout << "===contructor without name===" << std::endl;
    ScavTrap test5;
	std::cout << "===contructor copy===" << std::endl;
	ScavTrap test6(test4);
	std::cout << "=====profil copy doit etre meme que test4=====" << std::endl;
	std::cout << "name  == " << test6.getName() << std::endl;
	std::cout << "hit poit == " << test6.getHitPoints() << std::endl;
	std::cout << "energy pointt == " << test6.getEnergyPoint() << std::endl;
	std::cout << "attack damage == " << test6.getAttackDamage() << std::endl;

	std::cout << std::endl << "----------- attack virtual function----------" << std::endl;
    test4.attack("A");
    test5.attack("B");
    test6.attack("C");
    std::cout << std::endl << "----------- take damage ----------" << std::endl;
    std::cout << "----------- damage methode from ClapTrap----------" << std::endl;
    test4.takeDamage(20);
    test5.takeDamage(10);
    test6.takeDamage(100);
    std::cout << std::endl << "----------- be repaired ----------" << std::endl;
    std::cout << "----------- be repaired methode from ClapTrap ----------" << std::endl;
    std::cout << "+20" << std::endl;
    test4.beRepaired(20);
    std::cout << "+1" << std::endl;
    test5.beRepaired(1);
    std::cout << "+5" << std::endl;
    test6.beRepaired(5);

    std::cout << std::endl << "----------- guard gate ----------" << std::endl;
	test4.guardGate();
	test5.guardGate();
	test6.guardGate();
    
	std::cout << "----------- DESTRUCTION ----------" << std::endl;
    std::cout << "----------- destruction dans l'ordre de stack ----------" << std::endl;
	return (0);
	}
