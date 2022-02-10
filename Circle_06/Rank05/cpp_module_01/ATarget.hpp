#pragma once

#include <iostream>

class ASpell;

class ATarget
{
	private:
		std::string type;

	public:
		ATarget();
		virtual ~ATarget();
		ATarget(ATarget const &rhs);
		ATarget	&operator=(ATarget const &rhs);
		ATarget(std::string const &type);

		std::string const &getType() const;
		virtual ATarget *clone() const = 0;

		void	getHitBySpell(ASpell const &rhs) const;
};

#include "ASpell.hpp"
