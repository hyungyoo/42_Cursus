#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(const char* message)
    : message(message) {}

const char* Form::GradeTooHighException::what() const throw()
{
    return message;
}

Form::GradeTooLowException::GradeTooLowException(const char* message)
    : message(message) {}

const char* Form::GradeTooLowException::what() const throw()
{
    return message;
}

Form::Form()
    : name("no_name"), isSigned(false),
      gradeRequiredInSign(150), gradeRequiredInExecute(150) {}

Form::Form(const std::string& name)
    : name(name), isSigned(false),
      gradeRequiredInSign(150), gradeRequiredInExecute(150) {}

Form::Form(int grade)
    : name("no_name"), isSigned(false),
      gradeRequiredInSign(grade), gradeRequiredInExecute(grade)
{
    if (grade > 150)
    {
        throw GradeTooLowException("Exception in constructor. The grade is too low");
    }
    if (grade < 1)
    {
        throw GradeTooHighException("Exception in constructor. The grade is too high");
    }
}

Form::Form(const std::string& name, int grade)
    : name(name), isSigned(false),
      gradeRequiredInSign(grade), gradeRequiredInExecute(grade)
{
    if (grade > 150)
    {
        throw GradeTooLowException("Exception in constructor. The grade is too low");
    }
    if (grade < 1)
    {
        throw GradeTooHighException("Exception in constructor. The grade is too high");
    }
}

Form::Form(int gradeRequiredInSign, int gradeRequiredInExecute)
    : name("no_name"), isSigned(false),
      gradeRequiredInSign(gradeRequiredInSign),
      gradeRequiredInExecute(gradeRequiredInExecute)
{
    if (gradeRequiredInSign > 150 || gradeRequiredInExecute > 150)
    {
        throw GradeTooLowException("Exception in constructor. The grade is too low");
    }
    if (gradeRequiredInSign < 1 || gradeRequiredInExecute < 1)
    {
        throw GradeTooHighException("Exception in constructor. The grade is too high");
    }
}

Form::Form(const std::string& name, int gradeRequiredInSign, int gradeRequiredInExecute)
    : name(name), isSigned(false),
      gradeRequiredInSign(gradeRequiredInSign),
      gradeRequiredInExecute(gradeRequiredInExecute)
{
    if (gradeRequiredInSign > 150 || gradeRequiredInExecute > 150)
    {
        throw GradeTooLowException("Exception in constructor. The grade is too low");
    }
    if (gradeRequiredInSign < 1 || gradeRequiredInExecute < 1)
    {
        throw GradeTooHighException("Exception in constructor. The grade is too high");
    }
}

Form::Form(const Form& a)
    : name(a.getName()), isSigned(false),
      gradeRequiredInSign(a.getGradeRequiredInSign()),
      gradeRequiredInExecute(a.getGradeRequiredInExecute()) {}

Form::~Form() {}

Form& Form::operator=(const Form& a)
{
    isSigned = a.getIsSigned();
    return *this;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeRequiredInSign() const
{
    return gradeRequiredInSign;
}

int Form::getGradeRequiredInExecute() const
{
    return gradeRequiredInExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (isSigned)
    {
        return;
    }
    if (gradeRequiredInSign < b.getGrade())
    {
        throw GradeTooLowException("Exception in beSigned. The grade is too low");
    }
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form &a)
{
    os << "name: " << a.getName() << \
          ", isSigned: " << a.getIsSigned() <<\
          ", gradeRequiredInSign: " << a.getGradeRequiredInSign() << \
          ", gradeRequiredInExecute: " << a.getGradeRequiredInExecute();
    return os;
}
