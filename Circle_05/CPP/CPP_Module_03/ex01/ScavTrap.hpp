#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
			ScavTrap(void);
			ScavTrap(std::string  const name);
			ScavTrap(ScavTrap const &scavtrap_copy);
			~ScavTrap(void);
			ScavTrap	&operator=(ClapTrap const &rhs);

			// overloading function attack from class parent
			void	attack(std::string const &target);

			void	guardGate(void);

	private:
			bool	_gate_keeper_mode;
};

#endif
