#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor with target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : Form(copy)
{
	std::cout << "ShrubberyCreationForm constructor copy" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	Form::operator=(rhs);
	std::cout << "ShrubberyCreationForm operator" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	(void)executor;
	std::ofstream	ofs;
	std::string file_name(this->getTarget());
	file_name.append("_shrubbey");
	Form::execute(executor);
	try
	{
		std::cout << "[with virtual, execute in ShrubbertCreationForm]" << std::endl;
		ofs.open(file_name.data(), std::ofstream::trunc | std::ofstream::out);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::cout << executor.getName() << ", executor ShrubberyCreationForm" << std::endl;
	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	ofs.close();	
}
