#include "Bureaucrat.hpp"
#include "Form.hpp"

# define DES -1
# define INC 1

void	changeGrade(Bureaucrat &bc, int cmd)
{
	try
	{
		if (cmd == DES)
			bc.decrementGrade();
		else if (cmd == INC)
			bc.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bc << std::endl;
	}
}

int	main(void)
{
	std::cout << "==============constructor Too low================" << std::endl;
	try
	{
		Form test_1("form_too_low", 151, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "==============constructor Too low================" << std::endl;
	try
	{
		Form test_2("form_too_high", 0, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "==============constructor Form A1================" << std::endl;
	Form A1("form_A", 75, 75);
	std::cout << A1 << std::endl;

	std::cout << "==============constructor Form A2================" << std::endl;
	Form A2("form_B", 150, 150);
	std::cout << A2 << std::endl;

	std::cout << "==============constructor Form A3================" << std::endl;
	Form A3("form_C", 10, 10);
	std::cout << A3 << std::endl;

	/*
	std::cout << "==============constructor Too low================" << std::endl;
	try
	{
		Bureaucrat L("too low", 155);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "==============constructor Too high================" << std::endl;
	try
	{
		Bureaucrat H("too high", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	*/
	std::cout << std::endl;
	std::cout << "==============constructor A, B and C================" << std::endl;
	std::cout << "==============constructor B================" << std::endl;
	Bureaucrat B("A", 149);
	std::cout << "==============constructor C================" << std::endl;
	Bureaucrat C("B", 2);
	std::cout << "==============constructor D================" << std::endl;
	Bureaucrat D("C", 65);
	
	std::cout << std::endl;
	std::cout << "==============A sign form================" << std::endl;
	B.signForm(A1);
	std::cout << "==============B sign form================" << std::endl;
	C.signForm(A2);
	std::cout << "==============C sign form================" << std::endl;
	D.signForm(A3);


	std::cout << std::endl;
	std::cout << "==============for A================" << std::endl;
	try
	{
		A1.beSigned(B);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << A1 << std::endl;
		std::cout << B << std::endl;
	}
	std::cout << "==============for B================" << std::endl;
	try
	{
		A2.beSigned(C);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << A2 << std::endl;
		std::cout << C << std::endl;
	}
	std::cout << "==============for C================" << std::endl;
	try
	{
		A3.beSigned(D);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << A3 << std::endl;
		std::cout << D << std::endl;
	}
	/*
	std::cout << "==============decrement A================" << std::endl;
	changeGrade(A, DES);
	std::cout << "==============increment B================" << std::endl;
	changeGrade(B, INC);
	std::cout << "==============catch error A================" << std::endl;
	changeGrade(A, DES);
	std::cout << "==============catch error B================" << std::endl;
	changeGrade(B, INC);
	*/
	std::cout << "==============Destructor ================" << std::endl;
	return (0);
}
