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
	int	i(0);
	while (i < 3)
	{
		if (form.compare(arrayForm[i]))
			break ;
		i++;
	}
	std::cout << i << std::endl;
	if (i == 3)
	{
		throw (std::runtime_error("Intern can't create Form"));
		return (NULL);
	}
	std::cout << "Intern creates " << form << std::endl;
	return (generatorForm[i]);
}
