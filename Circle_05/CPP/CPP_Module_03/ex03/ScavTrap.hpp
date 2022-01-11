#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
			ScavTrap(void);
			ScavTrap(std::string  const name);
			ScavTrap(const ScavTrap &scavtrap_copy);
			~ScavTrap(void);
			ScavTrap	&operator=(ScavTrap const &rhs);

			// overloading function attack from class parent
			void	attack(std::string const &target);

			void	guardGate(void);

	protected:
			bool	_gate_keeper_mode;
};

#endif
