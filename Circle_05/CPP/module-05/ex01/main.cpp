#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        Bureaucrat bur("bur", 10);
        std::cout << bur << std::endl;
        Form form("form", 20);
        std::cout << form << std::endl;
        form.beSigned(bur);
        std::cout << form << std::endl;
    }

    std::cout << "-----" << std::endl;

    {
        Bureaucrat bur("bur", 10);
        std::cout << bur << std::endl;
        Form form("form", 20);
        std::cout << form << std::endl;
        bur.signForm(form);
        std::cout << form << std::endl;
    }

    std::cout << "-----" << std::endl;

    {
        Bureaucrat bur("bur", 10);
        std::cout << bur << std::endl;
        Form form("form", 5, 20);
        std::cout << form << std::endl;
        bur.signForm(form);
        std::cout << form << std::endl;
    }

    std::cout << "-----" << std::endl;

    try
    {
        Form form(-1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form form(151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bur(100);
        Form form(1);
        form.beSigned(bur);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
