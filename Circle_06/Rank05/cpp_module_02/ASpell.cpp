#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(ASpell const &copy)
{
	(*this) = copy;
}

ASpell	&ASpell::operator=(ASpell const &rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffects();
	return (*this);
}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->name = name;
	this->effects = effects;
}

std::string const &ASpell::getName() const
{
	return (this->name);
}

std::string const &ASpell::getEffects() const
{
	return (this->effects);
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell((*this));
}
