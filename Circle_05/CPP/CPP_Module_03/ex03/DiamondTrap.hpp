#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamondtrap_copy);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &rhs);

		void	whoAmI();
		void	attack(std::string const &target);
};

#endif

