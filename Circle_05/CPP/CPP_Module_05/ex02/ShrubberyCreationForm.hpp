#ifndef SHRUBBEYCREATIONFORM_HPP
# define SHRUBBEYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <string>

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		virtual void execute(Bureaucrat const &executor);
};

#endif
