#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell *>	arr;

		SpellBook(SpellBook const &copy);
		SpellBook &operator=(SpellBook const &rhs);
	
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &name_spell);
		ASpell *createSpell(std::string const &spell);
};
