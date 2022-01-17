#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class	WrongDog : public WrongAnimal
{
	public:
		WrongDog(void);
		WrongDog(WrongDog const &copy);
		WrongDog	&operator=(WrongDog const &rhs);
		~WrongDog(void);
		void	makeSound(void) const;
	private:
		/* non */
};

#endif

