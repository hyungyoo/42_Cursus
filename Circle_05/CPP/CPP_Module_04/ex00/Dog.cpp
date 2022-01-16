#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << "dog [" << this->getType() << "] construcor" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog copy [" << this->getType() << "] constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog [" << this->getType() << "] destructor" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	Animal::operator=(rhs);
	std::cout << "Dog operaotr" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "class [" << this->getType() << "] make sound wall wall" << std::endl;
}


