#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor with target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : Form(copy)
{
	std::cout << "RobotomyRequestForm constructor copy" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	Form::operator=(rhs);
	std::cout << "RobotomyRequestForm operator" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	srand(time(NULL));
	int	random_int(rand() % 10);

	//std::cout << random_int << " == random "  << std::endl;
	(void)executor;
	Form::execute(executor);
	std::cout << "Drill: ZZZZZZZZZZZZZZZZZ" << std::endl;
	if (random_int % 2)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " fail to robotomized" << std::endl;
}
