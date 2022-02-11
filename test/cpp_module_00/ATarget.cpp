#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::~ATarget() {}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::ATarget(ATarget const &copy)
{
	(*this) = copy;
}

ATarget	&ATarget::operator=(ATarget const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

std::string	const &ATarget::getType() const { return this->type; }

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << std::endl;
}
