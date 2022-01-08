#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(FragTrap const & fragtrap_copy);
		FragTrap(std::string name);
		~FragTrap(void);

		FragTrap &operator=(FragTrap const &rhs);
		void	highFivesGuys(void);
		void	attack(std::string const & target);
};

#endif
