#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

Form::Form(void): _name("no name"), _isSigned(false), _gradeRequiredSign(150), _gradeRequiredExecute(150)
{
	std::cout << "Form constructor default" << std::endl;
}

Form::Form(const std::string name, int gradeRequiredSign, int gradeRequiredExecute) :
_name(name),
_gradeRequiredSign(gradeRequiredSign),
_gradeRequiredExecute(gradeRequiredExecute),
_isSigned(false)
{
	if (gradeRequiredSign > 150  || gradeRequiredExecute > 150)
		throw (Form::GradeTooLowException());
	else if (gradeRequiredSign < 1  || gradeRequiredExecute < 1)
		throw (Form::GradeTooHighException());
}

Form::~Form(void)
{
	std::cout << "deconstructor Form : " << this->getName() << std::endl;
}

Form::Form(Form const &copy) :
_name(copy.getName()),
_isSigned(copy.getIsSign()),
_gradeRequiredSign(copy.getGradeRequiredSign()),
_gradeRequiredExecute(copy.getGradeRequiredExecute())

{
	std::cout << "Form copy constructor" << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	std::cout << "Form operator" << std::endl;
	this->_isSigned = rhs.getIsSign();
	return (*this);
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSign(void) const
{
	return (this->_isSigned);
}
		
const int Form::getGradeRequiredSign(void) const
{
	return (this->_gradeRequiredSign);
}

const int Form::getGradeRequiredExecute(void) const
{
	return (this->_gradeRequiredExecute);
}

void	Form::beSigned(Bureaucrat	const &rhs)
{
	if (this->getIsSign())
	{
		std::cout << rhs.getName() << " is already sign" << std::endl;
		return ;
	}
	else if (this->getGradeRequiredSign() < rhs.getGrade())
		throw (Form::GradeTooLowException());
	else
	{
		std::cout << rhs.getName() << " is sign [called by besigned function]" << std::endl;
		this->_isSigned = true;
	}
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form name = " << rhs.getName() << ", isSigned = " << rhs.getIsSign() << ", gradeRequiredSign = " << rhs.getGradeRequiredSign() << ", _gradeRequiredExecute = " << rhs.getGradeRequiredExecute() << std::endl;
	return (o);
}

