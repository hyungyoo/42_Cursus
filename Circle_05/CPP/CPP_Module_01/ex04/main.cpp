#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

void	replace(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
	std::string str;
	size_t		pos;
	bool		next_line_flag;

	next_line_flag = false;
	while (std::getline(ifs, str))
	{
		if (next_line_flag)
			ofs << std::endl;
		next_line_flag = true;
		
		/* pos et npos with function find*/
		pos = str.find(s1);
		while (pos != std::string::npos && s1.compare(s2))
		{
			/* erase et insert pour replace */
			str.erase(pos, s1.length());
			str.insert(pos, s2);
			/* trouver "s1" dans "str", mais a partir de "pos" */
			pos = str.find(s1, pos);
		}
		ofs << str;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error:  3 arguements!" << std::endl;
		return (1);
	}
	std::string s1(argv[1]);
	std::string s2(argv[2]);
	std::string file_name(argv[3]);
	
	/* ifstream */
	std::string in_file = "./" + file_name;
	std::ifstream ifs;
	ifs.open(in_file);
	if (ifs.fail())
	{
		std::cerr << "Error: fail open file" << std::endl;
		return (1);
	}
	/* ofstream */
	std::string out_file;
	out_file = file_name + ".replace";
	std::ofstream ofs(out_file);
	
	/* replace */
	replace(ifs, ofs, s1, s2);

	/* close file stream */
	ifs.close();
	ofs.close();
	return (0);
}
