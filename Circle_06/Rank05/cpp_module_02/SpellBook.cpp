#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = arr.begin();
	std::map<std::string, ASpell *>::iterator it_end = arr.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	arr.clear();
}

void	SpellBook::learnSpell(ASpell *aspell)
{
	if (aspell)
	{
		arr.insert(std::pair<std::string, ASpell *>(aspell->getName(), aspell->clone()));
	}
}

void	SpellBook::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(spell);
	if (it != arr.end())
	{
		delete it->second;
	}
	arr.erase(spell);
}

ASpell	*SpellBook::createSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(spell);
	if (it != arr.end())
		return (arr[spell]);
	return (NULL);
}

