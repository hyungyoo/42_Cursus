#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <ctime>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    virtual void action() const;

public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& a);
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm&);
};

#endif
