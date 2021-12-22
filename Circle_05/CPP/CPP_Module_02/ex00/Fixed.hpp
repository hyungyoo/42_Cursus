#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed	&operator=(Fixed const &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int	_point_fix;
		static const int	_bits_fractionnels;

};

#endif
