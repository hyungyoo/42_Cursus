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
	return (this->_point_fix);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_point_fix = raw;
}

Fixed::Fixed(const int int_convert)
{
	std::cout << "Int constructor called" << std::endl;
	this->_point_fix = int_convert * (1 << this->_bits_fractionnels);
}

Fixed::Fixed(const float float_convert)
{
	std::cout << "Float constructor called" << std::endl;
	this->_point_fix = roundf(float_convert * (1 << this->_bits_fractionnels));
}

int		Fixed::toInt(void) const
{
	return (this->_point_fix / (1 << this->_bits_fractionnels));
}

float	Fixed::toFloat(void) const
{
	return (roundf(this->_point_fix) / (1 << this->_bits_fractionnels));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs)
{
	os << rhs.toFloat();
	return (os);
}
