#include "Span.hpp"

int	main(void)
{
	std::cout << "===========Span with 0, add number, catch error===========" << std::endl;
	{
		Span	A(0);
		try
		{
			A.addNumber(1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "===========Span with 20, and random, display===========" << std::endl;
	{
		Span	A(20);
		try
		{
			A.randomVector();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====A=====" << std::endl;
		std::cout << A;
		std::cout << "=====A shortestSpan=====" << std::endl;
		std::cout << A.shortestSpan() << std::endl;
		std::cout << "=====A longestSpan=====" << std::endl;
		std::cout << A.longestSpan() << std::endl;
	}
	std::cout << "===========Span with 3, add seconde number, catch error===========" << std::endl;
	{
		Span	A(3);
		try
		{
			A.addNumber(-5);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			A.addNumber(15);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}	
		try
		{
			A.addNumber(3);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			A.addNumber(1);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====A {-5, 15, 3}=====" << std::endl;
		std::cout << A;
		std::cout << "=====A shortestSpan 8=====" << std::endl;
		try
		{
			std::cout << A.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====A longestSpan 20=====" << std::endl;
		try
		{
			std::cout << A.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "===========Span with 1, catch error for shortest and longestSpan===========" << std::endl;
	{
		Span	A(1);
		
		std::cout << "=====A, size 1 and add num 8=====" << std::endl;
		try
		{
			A.addNumber(8);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====A shortestSpan error=====" << std::endl;
		try
		{
			std::cout << A.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "=====A longestSpan error=====" << std::endl;
		try
		{
			std::cout << A.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
