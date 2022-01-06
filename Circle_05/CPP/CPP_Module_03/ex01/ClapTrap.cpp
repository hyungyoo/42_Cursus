#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("no name"), _hitPoints(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "constructor defalut with [no name] is born" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hitPoints(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "constructor with name: [" << name << "] is born" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap_copy)
{
	(*this) = clapTrap_copy;
	std::cout << "constructor copy [" << this->getName() << "] is born"  <<std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor [" << this->_name << "]" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	//std::cout << "ClapTrap assignation operator! " << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoint = rhs.getEnergyPoint();
	this->_attackDamage = rhs.getAttackDamage();
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

void			ClapTrap::setEnergyPoint(unsigned int newEnergy)
{
	this->_energyPoint = newEnergy;
}

void			ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << this->getName() << " attack " << target << ", causing " << this->getHitPoints()  << " points of damage!" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap " << this->getName() << " is attaked [" << amount << "] point of damage" << std::endl;
	if ((this->getEnergyPoint()) <= amount)
	{
		setEnergyPoint(0);
		std::cout << "ClapTrap " << this->getName() << " is dead" << std::endl;
	}
	else
	{
		setEnergyPoint(this->_energyPoint - amount);
		std::cout << "Claptrap " << this->getName() << " has now " << this->getEnergyPoint() << std::endl;
	}
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoint() == 0)
		std::cout << "ClapTrap is dead, so no longer be repaired" << std::endl;
	else
	{
		setEnergyPoint(this->_energyPoint + amount);
		std::cout << "Claptrap " << this->getName() << " has now " << this->getEnergyPoint() << std::endl;
	}
	
}
