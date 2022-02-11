#pragma once

#include "ATarget.hpp"

#include <iostream>

class ATarget;

class ASpell
{
	private:
		std::string name;
		std::string effects;
	
	public:
		ASpell();
		virtual ~ASpell();
		ASpell(ASpell const &copy);
		ASpell	&operator=(ASpell const &rhs);
		ASpell(std::string const &name, std::string const &effects);

		std::string const &getName() const;
		std::string const &getEffects() const;

		virtual ASpell *clone () const = 0;

		void	launch(ATarget const &target) const;

};
