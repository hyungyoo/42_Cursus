#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;


		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &rhs);
		
		SpellBook	book;	

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;

		void	setTitle(std::string const &title);

		void	introduce() const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string name_spell);
		void	launchSpell(std::string nam, ATarget const &target);
};
