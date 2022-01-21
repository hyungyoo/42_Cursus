#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
		std::cout << "==========================ShrubberyCreationForm=================================" << std::endl;
	{
		std::cout << "==============ShrubberyCreationForm upcasting from Form with grade 120==================" << std::endl;
		Form *ptrShr = new ShrubberyCreationForm("target_A");
		//Form *ptrShr2 = new ShrubberyCreationForm("target_B");
		std::cout << "==============ShrubberyCreationForm profile==================" << std::endl;
		std::cout << *ptrShr;
		std::cout << "==============Bureaucrat ==================" << std::endl;
		Bureaucrat bru("bru_120", 120);
		std::cout << "==============try catch with function execute but not signed==================" << std::endl;
		bru.executeForm(*ptrShr);
		std::cout << "==============bru_120 sign for execute==================" << std::endl;
		bru.signForm(*ptrShr);
		std::cout << "==============bru_120 executing==================" << std::endl;
		bru.executeForm(*ptrShr);
		std::cout << "==============destructor with delete==================" << std::endl;
		delete ptrShr;
	}
	std::cout << std::endl;
	{
		std::cout << "==============ShrubberyCreationForm upcasting from Form with grade 140==================" << std::endl;
		Form *ptrShr = new ShrubberyCreationForm("target_B");
		//Form *ptrShr2 = new ShrubberyCreationForm("target_B");
		std::cout << "==============ShrubberyCreationForm profile==================" << std::endl;
		std::cout << *ptrShr;
		std::cout << "==============Bureaucrat ==================" << std::endl;
		Bureaucrat bru("bru_140", 140);
		std::cout << "==============try catch with function execute but not signed==================" << std::endl;
		bru.executeForm(*ptrShr);
		std::cout << "==============bru_140 sign for execute==================" << std::endl;
		bru.signForm(*ptrShr);
		std::cout << "==============bru_140 executing==================" << std::endl;
		bru.executeForm(*ptrShr);
		std::cout << "==============destructor with delete==================" << std::endl;
		delete ptrShr;
	}
	return (0);
}
