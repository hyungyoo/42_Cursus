#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "animal [" << this->getType() << "] constuctor" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	(*this) = copy;
	std::cout << "animal copy [" << this->getType() << "] constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "animal [" << this->getType() << "] destructor" << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	this->_type = rhs.getType();
	std::cout << "animal operator" << std::endl;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "class" << this->getType() << "make sound like -------" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

