#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(ASpell const &rhs) { (*this) = rhs; }

ASpell	&ASpell::operator=(ASpell const &copy)
{
	this->name = copy.name;
	this->effects = copy.effects;
	return (*this);
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const 
{ 
	return (this->name); 
}

std::string const &ASpell::getEffects() const 
{ 
	return (this->effects); 
}

void	ASpell::launch(ATarget const &rhs) const
{
	rhs.getHitBySpell((*this));
}
