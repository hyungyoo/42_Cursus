#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	try
	{
		this->brain = new Brain();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "dog [" << this->getType() << "] construcor" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	try
	{
		// deep copy
		this->brain = new Brain();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "Dog copy consructor, error new Brain " << std::endl;
		return ;
	}
	(*this) = copy;
	std::cout << "Dog copy [" << this->getType() << "] constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog ";
	delete brain;
	std::cout << "Dog [" << this->getType() << "] destructor" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	Animal::operator=(rhs);
	*(this->brain) = *(rhs.brain);
	std::cout << "Dog operaotr" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "class [" << this->getType() << "] make sound wall wall" << std::endl;
}

const	std::string &Dog::getIdeas(int index) const
{
	return (this->brain->getIdeas(index));
}

void	Dog::setIdeas(int index, const std::string &str)
{
	this->brain->setIdeas(index, str);
}
