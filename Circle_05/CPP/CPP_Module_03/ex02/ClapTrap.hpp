#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(const ClapTrap &clapTrap_copy);
		~ClapTrap(void);
		ClapTrap	&operator=(ClapTrap const &rhs);

		std::string getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;
		void			setHitPoints(unsigned int hp);
		void			setEnergyPoint(unsigned int ep);
		void			setAttackDamage(unsigned int ap);
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
