#include "Bureaucrat.hpp"

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
	std::cout << "==============A and B for throw try catch================" << std::endl;
	std::cout << "==============constructor A================" << std::endl;
	Bureaucrat A("A", 149);
	std::cout << "==============constructor B================" << std::endl;
	Bureaucrat B("B", 2);
	std::cout << "==============decrement A================" << std::endl;
	changeGrade(A, DES);
	std::cout << "==============increment B================" << std::endl;
	changeGrade(B, INC);
	std::cout << "==============catch error A================" << std::endl;
	changeGrade(A, DES);
	std::cout << "==============catch error B================" << std::endl;
	changeGrade(B, INC);
	std::cout << "==============Destructor A and B================" << std::endl;
	
	return (0);
}
