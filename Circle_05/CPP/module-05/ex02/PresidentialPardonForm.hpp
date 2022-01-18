#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    virtual void action() const;

public:
    PresidentialPardonForm();
    explicit PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& a);
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm&);
};

#endif
