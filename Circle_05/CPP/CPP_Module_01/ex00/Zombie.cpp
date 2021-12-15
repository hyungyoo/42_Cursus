#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " has been destroyed" << std::endl;
}

void	Zombie::SetName(std::string name)
{
	this->name = name;
}

std::string Zombie::GetName(void) const
{
	return (this->name);
}	

void	Zombie::annonce(void) const
{
	std::cout << GetName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}
