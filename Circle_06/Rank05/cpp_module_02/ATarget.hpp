#pragma once

#include "ASpell.hpp"

#include <iostream>

class ASpell;

class ATarget
{
	private:
		std::string type;
	
	public:
		ATarget();
		ATarget(std::string const &type);
		virtual ~ATarget();
		ATarget(ATarget const &copy);
		ATarget	&operator=(ATarget const &rhs);

		std::string const &getType() const;

		virtual ATarget	*clone() const = 0;

		void	getHitBySpell(ASpell const &spell) const;

};
