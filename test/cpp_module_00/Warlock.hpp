#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;

		std::map<std::string, ASpell *>	arr;

		Warlock();
		Warlock(Warlock const &copy);
		Warlock &operator=(Warlock const &rhs);
	
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;

		void	setTitle(std::string const &title);

		void	introduce() const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string name_spell);
		void	launchSpell(std::string name, ATarget const &target);
};
