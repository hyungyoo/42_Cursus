#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Parctice Dummy")
{}

Dummy::~Dummy() {}

ATarget	*Dummy::clone() const
{
	return (new Dummy());
}


