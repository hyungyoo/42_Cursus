#include "Cat.hpp"

Cat::Cat(void) 
{
	this->_type = "Cat";
	try
	{
		brain = new Brain();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "cat [" << this->getType() << "] construcor" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	try
	{
		// deep copy
		this->brain = new Brain();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout <<"Cat copy contructor, error new Brain" << std::endl;
		return ;
	}
	(*this) = copy;
	std::cout << "Cat copy [" << this->getType() << "] constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat ";
	delete brain;
	std::cout << "Cat [" << this->getType() << "] destructor" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	Animal::operator=(rhs);
	*(this->brain) = *(rhs.brain);
	std::cout << "Cat operaotr" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "class [" << this->getType() << "] make sound yaong yaong" << std::endl;
}

const std::string &Cat::getIdeas(int index) const
{
	return (this->brain->getIdeas(index));
}

void	Cat::setIdeas(int index, const std::string &str)
{
	this->brain->setIdeas(index, str);
}
