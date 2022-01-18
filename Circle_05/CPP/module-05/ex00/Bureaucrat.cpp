#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* message)
    : message(message) {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return message;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* message)
    : message(message) {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return message;
}

Bureaucrat::Bureaucrat() : name("no_name"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const & name)
    : name(name), grade(150) {}

Bureaucrat::Bureaucrat(int grade)
    : name("no_name"), grade(grade)
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

Bureaucrat::Bureaucrat(std::string const & name, int grade)
    : name(name), grade(grade)
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

Bureaucrat::Bureaucrat(const Bureaucrat& a)
    : name(a.getName()), grade(a.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
    grade = a.getGrade();
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
    {
        throw GradeTooHighException("Exception in incrementGrade. The grade will not increase any further.");
    }
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
    {
        throw GradeTooLowException("Exception in decrementGrade. The grade will not decrement any further.");
    }
    ++grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &a)
{
    os << a.getName() << ", bureaucrat grade " << a.getGrade();
    return os;
}
