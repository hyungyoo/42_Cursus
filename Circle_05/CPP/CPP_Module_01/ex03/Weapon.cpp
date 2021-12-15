#include "./Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string const &type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const &Weapon::GetType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string const &type)
{
	this->type = type;
}
