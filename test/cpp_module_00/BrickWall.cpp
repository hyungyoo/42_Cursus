#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Incospicuous Red-brick Wall")
{}

BrickWall::~BrickWall()
{}

ATarget *BrickWall::clone() const
{
	return (new BrickWall());
}
