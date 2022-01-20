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

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "name is " << rhs.getName() << " and grade is " << rhs.getGrade();
	return (o);
}

