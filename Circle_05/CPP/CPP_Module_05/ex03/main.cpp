#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		std::cout << "==============RobotomyRequestForm from Intern================" << std::endl;
		Intern  someRandomIntern;
		Form*   rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << "=========profil robotomy==========" << std::endl;
			std::cout << *rrf;
			std::cout << "=========Bureaucrat==========" << std::endl;
			Bureaucrat	bru_10("bru_10", 10);
			std::cout << "=========Bureaucrat execute, but not signed==========" << std::endl;
			bru_10.executeForm(*rrf);
			std::cout << "=========Bureaucrat sign==========" << std::endl;
			bru_10.signForm(*rrf);
			std::cout << "=========Bureaucrat execute==========" << std::endl;
			bru_10.executeForm(*rrf);
			delete rrf;
		}
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "==============ShrubberyCreationForm from Intern================" << std::endl;
		Intern  someRandomIntern;
		Form*   rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			std::cout << "=========profil shrubbery==========" << std::endl;
			std::cout << *rrf;
			std::cout << "=========Bureaucrat==========" << std::endl;
			Bureaucrat	bru_10("bru_10", 10);
			std::cout << "=========Bureaucrat execute, but not signed==========" << std::endl;
			bru_10.executeForm(*rrf);
			std::cout << "=========Bureaucrat sign==========" << std::endl;
			bru_10.signForm(*rrf);
			std::cout << "=========Bureaucrat execute==========" << std::endl;
			bru_10.executeForm(*rrf);
			delete rrf;
		}
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "==============PresidentialPardonForm from Intern================" << std::endl;
		Intern  someRandomIntern;
		Form*   rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{
			std::cout << "=========profil presidential==========" << std::endl;
			std::cout << *rrf;
			std::cout << "=========Bureaucrat==========" << std::endl;
			Bureaucrat	bru_10("bru_10", 10);
			std::cout << "=========Bureaucrat execute, but not signed==========" << std::endl;
			bru_10.executeForm(*rrf);
			std::cout << "=========Bureaucrat sign==========" << std::endl;
			bru_10.signForm(*rrf);
			std::cout << "=========Bureaucrat execute==========" << std::endl;
			bru_10.executeForm(*rrf);
			delete rrf;
		}
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "==============invalid Form  from Intern================" << std::endl;
		Intern  someRandomIntern;
		Form*   rrf;
		rrf = someRandomIntern.makeForm("hyung form", "Bender");
		if (rrf)
		{
			std::cout << "=========profil robotomy==========" << std::endl;
			std::cout << *rrf;
			std::cout << "=========Bureaucrat==========" << std::endl;
			Bureaucrat	bru_10("bru_10", 10);
			std::cout << "=========Bureaucrat execute, but not signed==========" << std::endl;
			bru_10.executeForm(*rrf);
			std::cout << "=========Bureaucrat sign==========" << std::endl;
			bru_10.signForm(*rrf);
			std::cout << "=========Bureaucrat execute==========" << std::endl;
			bru_10.executeForm(*rrf);
			delete rrf;
		}
	}
	return (0);
}
