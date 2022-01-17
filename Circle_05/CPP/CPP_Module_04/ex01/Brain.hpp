#ifndef BRAIN_HPP
# define BRAIN_HPP

# define NUM_IDEAS 100

#include <iostream>

class Brain
{
	private:
		std::string ideas[NUM_IDEAS];

	public:
		Brain(void);
		Brain(Brain const &copy);
		Brain	&operator=(Brain const &rhs);
		~Brain(void);
		const std::string	&getIdeas(int index) const;
		void	setIdeas(int index, const std::string &str);
};

#endif
