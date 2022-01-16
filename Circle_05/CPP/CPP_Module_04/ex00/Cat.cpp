#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "cat [" << this->getType() << "] construcor" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	std::cout << "Cat copy [" << this->getType() << "] constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat [" << this->getType() << "] destructor" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	Animal::operator=(rhs);
	std::cout << "Cat operaotr" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "class [" << this->getType() << "] make sound yaong yaong" << std::endl;
}

