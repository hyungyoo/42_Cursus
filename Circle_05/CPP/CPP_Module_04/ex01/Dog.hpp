#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &rhs);
		virtual ~Dog(void);
		void	makeSound(void) const;
		const std::string 	&getIdeas(int index) const;
		void	setIdeas(int index, const std::string &str);
	private:
		Brain *brain;
};

#endif

