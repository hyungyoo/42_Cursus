#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "Wrong animal [" << this->getType() << "] constuctor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	(*this) = copy;
	std::cout << "Wrong animal copy [" << this->getType() << "] constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong animal [" << this->getType() << "] destructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs.getType();
	std::cout << "Wrong animal operator" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal class [" << this->getType() << "] make sound like -------" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

