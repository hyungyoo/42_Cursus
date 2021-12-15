#include "Zombie.hpp"

bool	CheckDigit(std::string num_str)
{
	int	i;
	int	num_str_length;

	i = 0;
	num_str_length = num_str.length();
	while (i <  num_str_length)
	{
		if (!(std::isdigit(num_str[i])))
			return (false);
		i++;
	}
	return (true);
}

int	main(void)
{
	int	number;
	std::string	num_str;
	std::string name;
	Zombie	*horde;

	std::cout << "enter number: ";
	getline(std::cin, num_str);
	if (!CheckDigit(num_str))
	{
		std::cout << "please enter a number" << std::endl;
		return (1);
	}
	number = stoi(num_str);
	std::cout << "enter name: ";
	getline(std::cin, name);
	horde = zombieHorde(number, name);

	delete [] horde;
	return (0);
}
