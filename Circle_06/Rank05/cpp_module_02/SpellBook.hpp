#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		SpellBook(SpellBook const &copy);
		SpellBook  &operator=(SpellBook const &rhs);

		std::map<std::string, ASpell *> arr;

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *aspell);
		void	forgetSpell(std::string const &spell);
		ASpell	*createSpell(std::string const &spell);

};
