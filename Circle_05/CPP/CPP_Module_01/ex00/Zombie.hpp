#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void		SetName(std::string name);
		std::string	GetName(void) const;
		void		annonce(void) const;

	private:
		std::string	name;

};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
