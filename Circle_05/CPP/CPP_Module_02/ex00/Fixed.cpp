#include "Fixed.hpp"

const int	Fixed::_bits_fractionnels = 8;

Fixed::Fixed(void):	_point_fix(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = fixed;
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Assignation operator called " << std::endl;
	this->_point_fix = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_point_fix);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_point_fix = raw;
}
