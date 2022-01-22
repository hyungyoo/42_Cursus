#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5)
{
//	std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5, target)
{
//	std::cout << "PresidentialPardonForm constructor with target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : Form(copy)
{
//	std::cout << "PresidentialPardonForm constructor copy" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
//	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	Form::operator=(rhs);
//	std::cout << "PresidentialPardonForm operator" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	//std::cout << random_int << " == random "  << std::endl;
	(void)executor;
	Form::execute(executor);
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
