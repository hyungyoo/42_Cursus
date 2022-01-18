#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
    int randam_value = std::rand() % 3;
    Base* base;

    switch (randam_value)
    {
    case 0:
        base = new A;
        break;
    case 1:
        base = new B;
        break;
    case 2:
        base = new C;
        break;
    default:
        base = NULL;
    }
    return base;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...) {}
}

int main()
{
    std::srand(std::time(NULL));
    Base* base = generate();
    Base non_inherit;

    identify(base);
    identify(NULL);
    identify(&non_inherit);

    identify(*base);
    identify(&non_inherit);
    delete base;
}
