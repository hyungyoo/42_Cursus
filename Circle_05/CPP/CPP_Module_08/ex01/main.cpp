#include "Span.hpp"

int	main(void)
{
	Span	A(15);

	A.addNumber(1);
	A.addNumber(2);
	A.addNumber(3);
	A.addNumber(4);

	Span	B(1);
	try
	{
		B = A;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << A;
	std::cout << B;
	return (0);
}
