#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	(*this) = copy;
	std::cout << "Brain copy constructor" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain operator" << std::endl;
	// attribute std::string Ideas[NUM_IDEAS]
	int	i(0);
	while (i < NUM_IDEAS)
	{
		this->setIdeas(i, rhs.getIdeas(i));
		i++;
	}
	return (*this);
}

const std::string 	&Brain::getIdeas(int index) const
{
	if (index >= 0 && index <= 100)
		return (this->ideas[index]);
	return (this->ideas[0]);
}

void	Brain::setIdeas(int index, const std::string &str)
{
	if (index >= 0 && index <= 100)
		ideas[index] = str;
}
