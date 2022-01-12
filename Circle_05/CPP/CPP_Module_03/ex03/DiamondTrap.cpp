#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoint(ScavTrap::getEnergyPoint());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "constructor default with [no name] DiamondTrap is born" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoint(ScavTrap::getEnergyPoint());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "name of claptrap is " << ClapTrap::getName() << std::endl;
	std::cout << "constructor default with name [" << name << "]  DiamondTrap is born" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap_copy) : 
ClapTrap(diamondtrap_copy), 
ScavTrap(diamondtrap_copy),
FragTrap(diamondtrap_copy)
{
	//(*this) = diamondtrap_copy;
	std::cout << "constuctor copy [" << this->getName() << "] DiamondTrap is born" << std::endl;
}

DiamondTrap		&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	//(void)rhs;
	ClapTrap::operator=(rhs);
	ScavTrap::operator=(rhs);
	FragTrap::operator=(rhs);	
	std::cout << "DiamondTrap assignment operator !" << std::endl;
	//setHitPoints(FragTrap::getHitPoints());
	//setEnergyPoint(ScavTrap::getEnergyPoints);
	//setAttackPoint(FragTrap::getAttackDamage());
	//this->_name = rhs._name;
	//this->_hitPoints = rhs._hitPoints;
	//this->_energyPoint = rhs._energyPoint;
	//this->_attackDamage = rhs._attackDamage;
	//this->_gate_keeper_mode = rhs._gate_keeper_mode;
	//(void)rhs;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "destructor DiamondTrap [" << this->getName() << "]" << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "==who am i ?= " << std::endl;
	std::cout << "i am [" << this->getName() << "]" << std::endl;
	std::cout << "my grandfather is [" << ClapTrap::getName() << "]" << std::endl;
}
