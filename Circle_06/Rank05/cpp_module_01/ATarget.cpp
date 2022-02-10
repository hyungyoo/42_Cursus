#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::~ATarget() {}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget	&ATarget::operator=(ATarget const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

ATarget::ATarget(ATarget const &rhs)
{
	(*this) = rhs;
}

std::string	const &ATarget::getType() const
{
	return (this->type);
}

void	ATarget::getHitBySpell(ASpell const &rhs) const
{
	std::cout << this->type << " has been " << rhs.getEffects() << std::endl;
}
