#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->weapon = &type;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << name << " attack with " << this->weapon->GetType() << std::endl;
}
