#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string		 _name;
	unsigned int	 _hitPoints;
	unsigned int	 _energyPoint;
	unsigned int	 _attackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const &clapTrap_copy);
	~ClapTrap(void);
	ClapTrap	&operator=(ClapTrap const &rhs);

	void	attack(std::string const &target);
	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);

	std::string		getName(void) const;
	unsigned int 	getHitPoints(void) const;
	unsigned int 	getEnergyPoint(void) const;
	unsigned int 	getAttackDamage(void) const;

	void			setEnergyPoint(unsigned int newEnergy);
};

#endif 
