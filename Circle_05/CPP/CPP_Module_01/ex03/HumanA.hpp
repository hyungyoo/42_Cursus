#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	attack(void);
	
	private:
		std::string name;
		Weapon &weapon;
};

#endif
