#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern &operator=(Intern const &rhs);
	
		Form *makeForm(const std::string  form, const std::string target) const;
};

#endif
