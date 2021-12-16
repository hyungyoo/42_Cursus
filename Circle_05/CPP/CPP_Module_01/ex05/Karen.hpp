#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
	typedef void (Karen::*f)(void)const;

	public:

		Karen(void);
		~Karen(void);
		void	complain(std::string level);

	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif 
