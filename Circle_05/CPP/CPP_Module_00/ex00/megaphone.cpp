#include <iostream>	//	for std::cout
#include <cctype>	//	for toupper()

static char	*capitalize_string(char *str)
{
	for (int i = 0; str[i]; ++i)
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; ++i)
			std::cout << capitalize_string(argv[i]);
	}
	std::cout << "\n";
	return (0);
}
