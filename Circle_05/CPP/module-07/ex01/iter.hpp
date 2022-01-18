#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T* array, std::size_t n, void (*f)(T&))
{
    for (std::size_t i = 0; i < n; ++i)
    {
        f(array[i]);
    }
}

template <typename T>
void iter(const T* array, std::size_t n, void (*f)(const T&))
{
    for (std::size_t i = 0; i < n; ++i)
    {
        f(array[i]);
    }
}

template <typename T>
void sample_func(T& a)
{
    std::cout << a << std::endl;
}

template <typename T>
void sample_func2(const T& a)
{
    std::cout << a << std::endl;
}

#endif
