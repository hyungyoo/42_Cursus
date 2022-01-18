#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeRequiredInSign;
    const int gradeRequiredInExecute;

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

    Form();
    explicit Form(const std::string& name);
    explicit Form(int grade);
    Form(const std::string& name, int grade);
    Form(int gradeRequiredInSign, int gradeRequiredInExecute);
    Form(const std::string& name, int gradeRequiredInSign, int gradeRequiredInExecute);
    Form(const Form& a);
    ~Form();

    Form& operator=(const Form& a);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredInSign() const;
    int getGradeRequiredInExecute() const;

    void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form &a);

#endif
