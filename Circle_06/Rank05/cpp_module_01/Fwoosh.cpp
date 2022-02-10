#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "Fwooshed") {}
Fwoosh::~Fwoosh() {}

ASpell *Fwoosh::clone() const
{
	return (new Fwoosh());
}
