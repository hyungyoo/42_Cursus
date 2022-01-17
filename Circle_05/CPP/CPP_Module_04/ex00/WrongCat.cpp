#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "Wrong cat [" << this->getType() << "] construcor" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	std::cout << "Wrong Cat copy [" << this->getType() << "] constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat [" << this->getType() << "] destructor" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	WrongAnimal::operator=(rhs);
	std::cout << "Wrong Cat operaotr" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong cat class [" << this->getType() << "] make sound yaong yaong" << std::endl;
}

