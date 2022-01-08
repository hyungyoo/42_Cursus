#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name = "no name";
	this->_hitPoints = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "constructor defalut with [no name] FragTrap is born" << std::endl;
}

// si on mets pas de "ClapTrap(name)", automatiquement, il appele "constructor no name"
FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "constructor with name [" << name << "] FragTrap is born" << std::endl;
}

FragTrap::FragTrap(FragTrap const &fragtrap_copy)
{
	(*this) = fragtrap_copy;
	std::cout << "constructor copy [" << this->_name << "] FragTrap is born" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "destructor FragTrap [" << this->_name << "]" << std::endl;
}


FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap assignment operator! " << std::endl;
	//ClapTrap::operator=(rhs);
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoint = rhs._energyPoint;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_hitPoints << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is requested high five" << std::endl;
}
