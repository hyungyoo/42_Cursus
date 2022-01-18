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
    const std::string target;
    virtual void action() const = 0;

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
    Form(const std::string& name, int gradeRequiredInSign, int gradeRequiredInExecute, const std::string& target);
    Form(const Form& a);
    virtual ~Form();

    Form& operator=(const Form&);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredInSign() const;
    int getGradeRequiredInExecute() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& b);
    void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const Form &a);

#endif
