#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::action() const
{
    if (rand() % 2)
    {
        std::cout << "buzz-buzz... " << getTarget() << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "buzz-buzz... " << getTarget() << " has failed to make robotomized." << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm()
    : Form("RobotomyRequest", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequest", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a)
    : Form(a) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&)
{
    return *this;
}
