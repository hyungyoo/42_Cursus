#include "./Karen.hpp"

int	main()
{
	Karen karen = Karen();

	std::cout << "--------------------DEBUG------------------" << std::endl;
	std::cout << std::endl;
	karen.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "--------------------INFO-------------------" << std::endl;
	std::cout << std::endl;
	karen.complain("INFO");
	std::cout << std::endl;
	std::cout << "--------------------WARINING---------------" << std::endl;
	std::cout << std::endl;
	karen.complain("WARNING");
	std::cout << std::endl;
	std::cout << "--------------------ERROR------------------" << std::endl;
	std::cout << std::endl;
	karen.complain("ERROR");
	std::cout << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	return (0);
}
