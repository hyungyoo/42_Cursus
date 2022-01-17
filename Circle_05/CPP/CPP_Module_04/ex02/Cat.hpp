#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &rhs);
		virtual ~Cat(void);
		void	makeSound(void) const;
		const	std::string &getIdeas(int index) const;
		void	setIdeas(int index, const std::string &str);
	private:
		Brain *brain;
};

#endif

