#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(Warlock const &copy)
{
	(*this) = copy;
}

Warlock	&Warlock::operator=(Warlock const &rhs)
{
	this->name = rhs.name;
	this->title = rhs.title;
	return (*this);
}

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;;
	this->title = title;
	std::cout <<  this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout <<  this->name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const
{
	return (this->name);
}

std::string const &Warlock::getTitle() const
{
	return (this->title);
}

void	Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << " !" << std::endl;
}

void	Warlock::learnSpell(ASpell *rhs)
{
	if (rhs)
	{
		arr.insert(std::pair<std::string, ASpell *>(rhs->getName(), rhs->clone()));
	}
}

void	Warlock::forgetSpell(std::string rhs)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(rhs);
	if (it != arr.end())
		delete it->second;
	arr.erase(rhs);
}

void	Warlock::launchSpell(std::string name, ATarget const &rhs)
{
	ASpell *spell = arr[name];
	if (spell)
		spell->launch(rhs);
}
