#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "animal constuctor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	(*this) = copy;
	std::cout << "animal copy constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "animal destructor" << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	this->_type = rhs.getType();
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

