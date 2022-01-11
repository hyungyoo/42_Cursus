#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
    std::cout << "test2 is called " << test2.getName() << std::endl;


    std::cout <<std::endl << std::endl << "-----------  ScavTrap  ----------" << std::endl << std::endl;

    std::cout << "----------- CONSTRUCTION ----------" << std::endl;
    std::cout << "----------- construction dans l'ordre de contreverse de stack ----------" << std::endl;
	std::cout << "contructor" << std::endl;
	ScavTrap test4("test4");
	std::cout << "contructor" << std::endl;
    ScavTrap test5;
	std::cout << "contructor copy" << std::endl;
    ScavTrap test6(test4);
	std::cout << "=====profil copy=====" << std::endl;
	std::cout << "name  == " << test6.getName() << std::endl;
	std::cout << "hit poit == " << test6.getHitPoints() << std::endl;
	std::cout << "energy pointt == " << test6.getEnergyPoint() << std::endl;
	std::cout << "attack damage == " << test6.getAttackDamage() << std::endl;

	std::cout << std::endl << "----------- attack ----------" << std::endl;
    test4.attack("A");
    test5.attack("B");
    test6.attack("C");
    std::cout << std::endl << "----------- take damage ----------" << std::endl;
    std::cout << "----------- damage methode from ClapTrap----------" << std::endl;
    test4.takeDamage(20);
    test5.takeDamage(0);
    test6.takeDamage(5);
    std::cout << std::endl << "----------- be repaired ----------" << std::endl;
    std::cout << "----------- be repaired methode from ClapTrap----------" << std::endl;
    test4.beRepaired(20);
    test5.beRepaired(0);
    test6.beRepaired(5);

     std::cout <<std::endl << std::endl << "-----------  FrapTrap  ----------" << std::endl << std::endl;

    std::cout << "----------- CONSTRUCTION ----------" << std::endl;
    std::cout << "----------- construction dans l'ordre de contreverse de stack ----------" << std::endl;
	std::cout << "contructor" << std::endl;
	FragTrap test7("test7");
	std::cout << "contructor" << std::endl;
    FragTrap test8;
	std::cout << "contructor copy" << std::endl;
    FragTrap test9(test7);
	std::cout << "=====profil copy=====" << std::endl;
	std::cout << "name  == " << test9.getName() << std::endl;
	std::cout << "hit poit == " << test9.getHitPoints() << std::endl;
	std::cout << "energy pointt == " << test9.getEnergyPoint() << std::endl;
	std::cout << "attack damage == " << test9.getAttackDamage() << std::endl;
	
	// pour up casting, il va montrer la raison pour virtual
	//ClapTrap *pClap = new FragTrap("up_casting");

	std::cout << std::endl << "----------- attack ----------" << std::endl;
    test7.attack("A");
    test8.attack("B");
    test9.attack("C");
	
	//pClap->attack("[target 'for up_casting']");
    
	std::cout << std::endl << "----------- take damage ----------" << std::endl;
    std::cout << "----------- damage methode from ClapTrap----------" << std::endl;
    test7.takeDamage(20);
    test8.takeDamage(0);
    test9.takeDamage(5);
    std::cout << std::endl << "----------- be repaired ----------" << std::endl;
    std::cout << "----------- be repaired methode from ClapTrap----------" << std::endl;
    test7.beRepaired(20);
    test8.beRepaired(0);
    test9.beRepaired(5);

    std::cout << std::endl << "----------- high fives ----------" << std::endl;
	test7.highFivesGuys();
	test8.highFivesGuys();
	test9.highFivesGuys();
    */

	std::cout << "----------- DiamondTrap  ----------" << std::endl << std::endl;
	std::cout << "----------- CONSTRUCTION ----------" << std::endl << std::endl;
	std::cout << "contructor" << std::endl;
	DiamondTrap test10("test10");
	std::cout << "contructor" << std::endl;
	DiamondTrap test11;
	std::cout << "contructor" << std::endl;
	DiamondTrap test12(test10);

	std::cout << "------------ GAME ----------" << std::endl;
	std::cout << "----------- attack ----------" << std::endl;
	test10.attack("A");
	test11.attack("B");
	test12.attack("C");
	std::cout << "----------- take damage ----------" << std::endl;
	test10.takeDamage(20);
	test11.takeDamage(0);
	test12.takeDamage(5);
	std::cout << "----------- be repaired ----------" << std::endl;
	test10.beRepaired(20);
	test11.beRepaired(0);
	test12.beRepaired(5);

	std::cout << "----------- who am i ----------" << std::endl;
	test10.whoAmI();
	test11.whoAmI();
	test12.whoAmI();

	
	std::cout << "----------- DESTRUCTION ----------" << std::endl;
    std::cout << "----------- destruction dans l'ordre de stack ----------" << std::endl;
	return (0);
	}
