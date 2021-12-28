#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const & src);
		Point(Fixed const x, Fixed const y);
		Point & operator=(Point const & point);
		~Point();

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
	private:
		Fixed const _x;
		Fixed const _y;
};

#endif
