#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
    virtual void action() const;

public:
    ShrubberyCreationForm();
    explicit ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& a);
    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
};

#endif
