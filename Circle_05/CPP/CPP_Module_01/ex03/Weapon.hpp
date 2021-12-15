#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string const &type);
		~Weapon();

		void				setType(std::string const &type);
		std::string	const 	&GetType(void) const;

	private:
		std::string type;
};

#endif
