#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(void) : _message("grade too high")
{
}

Form::GradeTooLowException::GradeTooLowException(void) : _message("grade too low")
{
}

Form::GradeTooHighException::GradeTooHighException(const char *message) : _message(message)
{
}

Form::GradeTooLowException::GradeTooLowException(const char *message) : _message(message)
{
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (this->_message);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (this->_message);
}

Form::Form(void): _name("no name"), _isSigned(false), _gradeRequiredSign(150), _gradeRequiredExecute(150), _target("defaut")
{
	//std::cout << "Form constructor default" << std::endl;
}

Form::Form(const std::string name, int gradeRequiredSign, int gradeRequiredExecute) :
_name(name),
_gradeRequiredSign(gradeRequiredSign),
_gradeRequiredExecute(gradeRequiredExecute),
_target("Default_target"),
_isSigned(false)
{
	if (gradeRequiredSign > 150  || gradeRequiredExecute > 150)
		throw (Form::GradeTooLowException());
	else if (gradeRequiredSign < 1  || gradeRequiredExecute < 1)
		throw (Form::GradeTooHighException());
	//std::cout << "Form constructor" << std::endl;
}

Form::Form(const std::string name, int gradeRequiredSign, int gradeRequiredExecute, const std::string target) :
_name(name),
_gradeRequiredSign(gradeRequiredSign),
_gradeRequiredExecute(gradeRequiredExecute),
_target(target),
_isSigned(false)
{
	if (gradeRequiredSign > 150  || gradeRequiredExecute > 150)
		throw (Form::GradeTooLowException());
	else if (gradeRequiredSign < 1  || gradeRequiredExecute < 1)
		throw (Form::GradeTooHighException());
	//std::cout << "Form constructor" << std::endl;
}

Form::~Form(void)
{
	//std::cout << "deconstructor Form" << std::endl;
}

Form::Form(Form const &copy) :
_name(copy.getName()),
_isSigned(copy.getIsSign()),
_gradeRequiredSign(copy.getGradeRequiredSign()),
_gradeRequiredExecute(copy.getGradeRequiredExecute()),
_target(copy.getTarget())
{
	//std::cout << "Form copy constructor" << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	//std::cout << "Form operator" << std::endl;
	this->_isSigned = rhs.getIsSign();
	return (*this);
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

const std::string &Form::getTarget(void) const
{
	return (this->_target);
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

void	Form::execute(Bureaucrat const &executor)
{
	if (!(this->getIsSign()))
	{
		throw (Form::GradeTooLowException("not signed"));
	}
	else if (executor.getGrade() > this->getGradeRequiredExecute())
	{
		throw (Form::GradeTooLowException());
	}
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form name = " << rhs.getName() << ", isSigned = " << rhs.getIsSign() << ", gradeRequiredSign = " << rhs.getGradeRequiredSign() << ", _gradeRequiredExecute = " << rhs.getGradeRequiredExecute() << std::endl;
	return (o);
}

