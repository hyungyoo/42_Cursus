#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::action() const
{
    std::string str = ".\n"
"|-- Bureaucrat.cpp\n"
"|-- Bureaucrat.hpp\n"
"|-- Form.cpp      \n"
"|-- Form.hpp      \n"
"|-- Makefile      \n"
"|-- PresidentialPardonForm.cpp\n"
"|-- PresidentialPardonForm.hpp\n"
"|-- RobotomyRequestForm.cpp\n"
"|-- RobotomyRequestForm.hpp\n"
"|-- ShrubberyCreationForm.cpp\n"
"|-- ShrubberyCreationForm.hpp\n"
"`-- main.cpp\n";

    std::ofstream ofs(getTarget() + "_shrubbery");
    if (!ofs)
    {
        throw std::runtime_error("The file could not be opened.");
    }
    ofs << str;
    if (ofs.fail())
    {
        throw std::runtime_error("Could not write to the file");
    }
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("ShrubberyCreation", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a)
    : Form(a) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&)
{
    return *this;
}
