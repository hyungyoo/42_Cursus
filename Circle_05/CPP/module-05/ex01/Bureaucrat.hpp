#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    class GradeTooHighException : public std::exception
    {
    private:
        const char* message;

    public:
        explicit GradeTooHighException(const char* message);
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    private:
        const char* message;

    public:
        explicit GradeTooLowException(const char* message);
        virtual const char* what() const throw();
    };

    Bureaucrat();
    explicit Bureaucrat(std::string const & name);
    explicit Bureaucrat(int grade);
    Bureaucrat(std::string const & name, int grade);
    Bureaucrat(const Bureaucrat& a);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& a);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(Form& f) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &a);

#endif
