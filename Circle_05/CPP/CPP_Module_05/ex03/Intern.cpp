#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor default" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern constructor copy" << std::endl;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	std::cout << "Intern operator" << std::endl;
	return (*this);
}

Form	*Intern::makeForm(const std::string form, const std::string target) const
{
	std::string	arrayForm[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form	*generatorForm[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	Form	*rrf = NULL;
	int	i(0);
	while (i < 3)
	{
		if (!(form.compare(arrayForm[i])))
		{
			std::cout << "Intern creates " << form << std::endl;
			rrf = generatorForm[i];
			break ;
		}
		i++;
	}
	int	j(0);
	while (j < 3)
	{
		if (j != i)
			delete generatorForm[j];
		j++;
	}
	if (i == 3)
	{
		std::cout << "Intern can't create Form" << std::endl;
		return (rrf);
	}
	return (rrf);
}
