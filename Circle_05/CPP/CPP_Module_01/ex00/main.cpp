#include "Zombie.hpp"

int	main(void)
{
	//std::cout << "new Zombue allocate a Zombie on the heap" << std::endl;
	Zombie *heapZombie;
	heapZombie = newZombie("Heap Zombie");
	heapZombie->annonce();
	
	//std::cout << "random chump allocate a Zombie on the stack" << std::endl;
	randomChump("Stack Zombie");

	delete heapZombie;
	return (0);
}
