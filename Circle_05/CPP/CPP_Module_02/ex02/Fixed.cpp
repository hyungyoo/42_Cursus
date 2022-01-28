#include "Fixed.hpp"

const int	Fixed::_bits_fractionnels = 8;

Fixed::Fixed(void):	_point_fix(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const &fixed)
{
	(*this) = fixed;
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	this->_point_fix = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_point_fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->_point_fix = raw;
}

Fixed::Fixed(const int int_convert)
{
	this->_point_fix = int_convert * (1 << this->_bits_fractionnels);
}

Fixed::Fixed(const float float_convert)
{
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

/* operator for > >= < <= == != */
bool	Fixed::operator>(Fixed const &rhs) const
{
	std::cout << "operator > " << std::endl;
	return (this->_point_fix > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	std::cout << "operator < " << std::endl;
	return (this->_point_fix < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	std::cout << "operator >= " << std::endl;
	return (this->_point_fix >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	std::cout << "operator <= " << std::endl;
	return (this->_point_fix <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	std::cout << "operator == " << std::endl;
	return (this->_point_fix == rhs.getRawBits());
}
bool	Fixed::operator!=(Fixed const &rhs) const
{
	std::cout << "operator != " << std::endl;
	return (this->_point_fix != rhs.getRawBits());
}

/* operator for + - * / , mais avec membre function toFloat */
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	ret(this->toFloat() + rhs.toFloat());
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	ret(this->toFloat() - rhs.toFloat());
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	ret(this->toFloat() * rhs.toFloat());
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	ret(this->toFloat() / rhs.toFloat());
	return (ret);
}

/* 단일 증감 */
Fixed	Fixed::operator++(void)
{
	++_point_fix;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	_point_fix++;
	return (temp);
}

Fixed	Fixed::operator--(void)
{
	Fixed temp(*this);

	--_point_fix;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	_point_fix--;
	return (*this);
}

/* min max */
Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	std::cout << "min with operator < " << std::endl;
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed 	&Fixed::min(Fixed  &a, Fixed  &b)
{
	std::cout << "min with operator < " << std::endl;
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	std::cout << "max with operator >" << std::endl;
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed 	&Fixed::max(Fixed  &a, Fixed  &b)
{
	std::cout << "max with operator >" << std::endl;
	if (a > b)
		return (a);
	else
		return (b);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs)
{
	os << rhs.toFloat();
	return (os);
}
