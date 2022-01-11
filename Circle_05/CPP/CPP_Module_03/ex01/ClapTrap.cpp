#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("no name"), _hitPoints(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "constructor defalut with [no name] ClapTrap is born" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hitPoints(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "constructor with name: [" << name << "] ClapTrap is born" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap_copy)
{
	(*this) = clapTrap_copy;
	std::cout << "constructor copy [" << this->_name << "] ClapTrap is born"  <<std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor ClapTrap [" << this->_name << "]" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap assignation operator! " << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoint = rhs._energyPoint;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoint(void) const
{
	return (this->_energyPoint);
}

unsigned int 	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void			ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_hitPoints  << " points of damage!" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap " << this->_name << " is attaked [" << amount << "] point of damage" << std::endl;
	if ((this->_energyPoint) <= amount)
	{
		this->_energyPoint = 0;
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
	else
	{
		this->_energyPoint -= amount;
		std::cout << "Claptrap " << this->_name << " has now " << this->_energyPoint << std::endl;
	}
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoint == 0)
		std::cout << "ClapTrap is dead, so no longer be repaired" << std::endl;
	else
	{
		this->_energyPoint += amount;
		std::cout << "Claptrap " << this->_name << " has now " << this->_energyPoint << std::endl;
	}
	
}
