#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed	&operator=(Fixed const &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(const int int_convert);
		Fixed(const float float_convert);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool		operator>(Fixed const &rhs) const;
		bool		operator<(Fixed const &rhs) const;
		bool		operator>=(Fixed const &rhs) const;
		bool		operator<=(Fixed const &rhs) const;
		bool		operator==(Fixed const &rhs) const;
		bool		operator!=(Fixed const &rhs) const;

		Fixed		operator+(Fixed const &rhs) const;
		Fixed		operator-(Fixed const &rhs) const;
		Fixed		operator*(Fixed const &rhs) const;
		Fixed		operator/(Fixed const &rhs) const;

		Fixed		operator++(void);
		Fixed		operator++(int);
		Fixed		operator--(void);
		Fixed		operator--(int);

		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed 	&min(Fixed  &a, Fixed  &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
		static Fixed 	&max(Fixed  &a, Fixed  &b);
	private:
		int	_point_fix;
		static const int	_bits_fractionnels;

};

std::ostream 	&operator<<(std::ostream &os, Fixed const & rhs);

#endif
