#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name = "no name";
	this->_hitPoints = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->_gate_keeper_mode = false;
	std::cout << "constructor defalut with [no name] ScavTrap is born" << std::endl;
}

// si on mets pas de "ClapTrap(name)", automatiquement, il appele "constructor no name"
ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->_gate_keeper_mode = false;
	std::cout << "constructor with name [" << name << "] ScavTrap is born" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap_copy)
{
	(*this) = scavtrap_copy;
	std::cout << "constructor copy [" << this->_name << "] ScavTrap is born" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "destructor ScavTrap [" << this->_name << "]" << std::endl;
}


ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap assignment operator! " << std::endl;
	ClapTrap::operator=(rhs);
	//this->_name = rhs._name;
	//this->_hitPoints = rhs._hitPoints;
	//this->_energyPoint = rhs._energyPoint;
	//this->_attackDamage = rhs._attackDamage;
	this->_gate_keeper_mode = rhs._gate_keeper_mode;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_hitPoints << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_energyPoint)
	{
		std::cout << "ScavTrap " << this->_name << " guarde keeper mode is activated!" << std::endl;
		this->_gate_keeper_mode = true;
	}
}

