#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(std::time(NULL));
    Bureaucrat bru("bru", 1);

    {
        Intern someRandomIntern;
        Form* rrf;

        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        if (rrf)
        {
            bru.signForm(*rrf);
            bru.executeForm(*rrf);
            delete rrf;
        }
    }

    {
        Intern someRandomIntern;
        Form* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            bru.signForm(*rrf);
            bru.executeForm(*rrf);
            delete rrf;
        }
    }

    {
        Intern someRandomIntern;
        Form* rrf;

        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        if (rrf)
        {
            bru.signForm(*rrf);
            bru.executeForm(*rrf);
            delete rrf;
        }
    }

    {
        Intern someRandomIntern;
        Form* rrf;

        rrf = someRandomIntern.makeForm("a", "Bender");
        if (rrf)
        {
            bru.signForm(*rrf);
            bru.executeForm(*rrf);
            delete rrf;
        }
    }
}
