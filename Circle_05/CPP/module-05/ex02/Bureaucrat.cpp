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

void Bureaucrat::signForm(Form& f) const
{
    std::string reason;

    if (f.getIsSigned())
    {
        reason = "it's already been signed";
    }
    else if (f.getGradeRequiredInSign() < grade)
    {
        reason = "the grade is too low";
    }
    else
    {
        std::cout << name << " signs " << \
                     f.getName() << std::endl;
        f.beSigned(*this);
        return ;
    }
    std::cout << name << " cannot sign " << \
                 f.getName() << " because " << \
                 reason << std::endl;
}

void Bureaucrat::executeForm(const Form& form) const
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << name << " could not execute " << \
                     form.getName() << " reason: " << \
                     e.what() << std::endl;
        return;
    }
    std::cout << name << " executes " << form.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &a)
{
    os << a.getName() << ", bureaucrat grade " << a.getGrade();
    return os;
}
