#include "WrongDog.hpp"

WrongDog::WrongDog(void) : WrongAnimal()
{
	this->_type = "Wrong Dog";
	std::cout << "Wrong dog [" << this->getType() << "] construcor" << std::endl;
}

WrongDog::WrongDog(WrongDog const &copy) : WrongAnimal(copy)
{
	std::cout << "Wrong Dog copy [" << this->getType() << "] constructor" << std::endl;
}

WrongDog::~WrongDog(void)
{
	std::cout << "Wrong Dog [" << this->getType() << "] destructor" << std::endl;
}

WrongDog	&WrongDog::operator=(WrongDog const &rhs)
{
	WrongAnimal::operator=(rhs);
	std::cout << "Wrong Dog operaotr" << std::endl;
	return (*this);
}

void	WrongDog::makeSound(void) const
{
	std::cout << "Wrong dog class [" << this->getType() << "] make sound wall wall" << std::endl;
}


