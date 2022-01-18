#include "span.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(INT_MAX);
        sp.addNumber(INT_MIN);
        sp.addNumber(0);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(INT_MIN);
        sp.addNumber(INT_MAX);
        sp.addNumber(0);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(10000);
        for (int i = 0; i < 10000; ++i)
        {
            sp.addNumber(i);
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(5);
        for (int i = 0; i < 5; ++i)
        {
            sp.addNumber(i);
        }
        try
        {
            sp.addNumber(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(5);
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        sp.addNumber(0);
        try
        {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(10000);
        std::vector<int> vec(9999, 2);
        sp.addNumber(vec.begin(), vec.end());
        sp.addNumber(100);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(5);
        std::vector<int> vec(5, 2);
        try
        {
            sp.addNumber(vec.begin(), vec.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "------------" << std::endl;
    {
        Span sp = Span(5);
        std::vector<int> vec(6, 2);
        try
        {
            sp.addNumber(vec.begin(), vec.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
