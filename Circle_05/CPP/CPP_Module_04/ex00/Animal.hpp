#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		Animal	&operator=(Animal const &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

};

#endif
