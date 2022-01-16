#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &rhs);
		~Dog(void);
		void	makeSound(void) const;
	private:
		/* non */
};

#endif

