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
	std::map<std::string, ASpell *>::iterator it_begin = arr.begin();
	std::map<std::string, ASpell *>::iterator it_end = arr.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	arr.clear();
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
	if (spell)
	{
		arr.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
	}
}

void	Warlock::forgetSpell(std::string name_spell)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(name_spell);
	if (it != arr.end())
	{
		delete it->second;
	}
	arr.erase(name_spell);
}

void	Warlock::launchSpell(std::string name, ATarget const &target)
{
	/*
	std::map<std::string, ASpell *>::iterator it = arr.find(name);
	if (it != arr.end())
	{
		ASpell	*tmp = arr[name];
		tmp->launch(target);
	}
	*/
	ASpell *tmp = arr[name];
	if (tmp)
		tmp->launch(target);
}
