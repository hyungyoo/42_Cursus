#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int	i;
	std::string name_zombie;
	std::string num;

	i = 0;
	Zombie	*ret;
	ret = new Zombie[N];
	while (i < N)
	{
		num = std::to_string(i);
		name_zombie = name + "_" + num;
		ret[i].SetName(name_zombie);
		ret[i].annonce();
		i++;
	}
	return (ret);
}
