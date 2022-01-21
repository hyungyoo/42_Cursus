# include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat constructor default" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat [" << this->getName() << "], grade [" << this->getGrade() << "] constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	/* const std::string, donc error */
	//this->_name = copy.getName();
	this->_grade = copy.getGrade();
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat [" << this->getName() << "], grade [" << this->getGrade() << "] destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat operator" << std::endl;
	this->_grade = rhs.getGrade();
	return (*this);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->getGrade()  == 1)
	{
		throw (GradeTooHighException());
	}
	--_grade;
	std::cout << "name is " << this->getName() << ", name is " << this->getGrade() << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() == 150)
	{
		throw (GradeTooLowException());
	}
	++_grade;
	std::cout << "name is " << this->getName() << ", name is " << this->getGrade() << std::endl;
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::signForm(Form &form)
{
	std::string reason(this->getName());

	if (form.getIsSign())
		reason.append(" already sign!");
	else if (form.getGradeRequiredSign() < this->getGrade())
		reason.append(", grade is too low");
	else
	{
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
		return ;
	}
	std::cout << this->getName() << " couldn’t sign " << form.getName() << " becuase : " << reason << std::endl;
}

void	Bureaucrat::executeForm(Form &form)
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << this->getName() << " can't execute form " << form.getName() << " reason : ";
		std::cerr << e.what() << std::endl;
		return ;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}


