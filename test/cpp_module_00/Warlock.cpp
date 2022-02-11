#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;

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
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	book.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string name_spell)
{
	book.forgetSpell(name_spell);
}

void	Warlock::launchSpell(std::string nam, ATarget const &target)
{
	ASpell *tmp = book.createSpell(nam);
	if (!(tmp == NULL))
	{
		tmp->launch(target);
	}
}
