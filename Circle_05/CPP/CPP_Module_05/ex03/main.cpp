#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "=====================objet someRandomIntern==================" << std::endl;
    Intern  someRandomIntern;
	std::cout << "=====================pointer Form==================" << std::endl;
    Form*   rrf;
	std::cout << "=====================rrf from makeForm==================" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy reques", "Bender");
	std::cout << *rrf;
	return (0);
}
