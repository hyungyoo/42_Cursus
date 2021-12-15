#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie chump;
	chump.SetName(name);
	chump.annonce();
}
