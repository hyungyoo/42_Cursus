#include "Span.hpp"

int	main(void)
{
	std::cout << "===========exemple==========" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "Should output:" << std::endl;
		std::cout << "$> ./ex01" << std::endl;
		std::cout << "2" << std::endl;
		std::cout << "14" << std::endl; 
	}
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
		std::cout << "===========B copy = Span B(A)===========" << std::endl;
		std::cout << "=====B=====" << std::endl;
		Span B(A);
		std::cout << B;
		std::cout << "===========deep copy===========" << std::endl;
		if (&(A.getVector()[0]) == &(B.getVector()[0]))
			std::cout << "no deep copy" << std::endl;
		else
			std::cout << "deep copy" << std::endl;
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
