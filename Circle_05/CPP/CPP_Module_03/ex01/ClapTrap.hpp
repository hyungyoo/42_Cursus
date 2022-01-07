#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &clapTrap_copy);
		~ClapTrap(void);
		ClapTrap	&operator=(ClapTrap const &rhs);

		std::string getName(void) const;
		// heritage en considerant de "up casting" --> pointer parent = new ScavTrap obet
		virtual void	attack(std::string const &target);
		void 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);

	// pas de "private" pour heritage
	protected:
		std::string		 _name;
		unsigned int	 _hitPoints;
		unsigned int	 _energyPoint;
		unsigned int	 _attackDamage;
};

#endif 
