#ifndef INTERN_H
#define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern&);
    ~Intern();

    Intern& operator=(const Intern&);

    Form* makeShrubberyCreation(const std::string& target) const;
    Form* makeRobotomyRequest(const std::string& target) const;
    Form* makePresidentialPardon(const std::string& target) const;
    Form* makeForm(const std::string& form, const std::string& target) const;
};

#endif
