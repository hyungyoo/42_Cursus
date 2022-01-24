#include "Convert.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error : ./convert [input]" << std::endl;
	else
	{
		std::string	arg(argv[1]);
		Convert	cv(arg);
		try
		{
			std::cout << cv.ConvertToChar() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
