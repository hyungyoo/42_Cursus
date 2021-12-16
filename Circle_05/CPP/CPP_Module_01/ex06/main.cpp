#include "./Karen.hpp"

int	main(int argc, char **argv)
{
	Karen		karen = Karen();
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;
	int			case_num = 4;

	if (argc != 2)
	{
		std::cout << "arguments est deux!!" << std::endl;
		return (0);
	}
	while (i < TOTAL_NUM_OF_LEVEL)
	{
		if (!(((std::string)argv[1]).compare((std::string)levels[i])))
		{
			case_num = i;
			break ;
		}
		i++;
	}
	switch (case_num)
	{
		case 0:
			karen.complain("DEBUG");
		case 1:
			karen.complain("INFO");
		case 2:
			karen.complain("WARNING");
		case 3:
			karen.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
