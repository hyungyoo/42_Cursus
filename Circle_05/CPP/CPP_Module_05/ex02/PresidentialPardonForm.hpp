#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <string>

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		virtual void execute(Bureaucrat const &executor);
};

#endif
