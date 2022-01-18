#ifndef Array_H
#define Array_H

#include <stdexcept>

template <typename T>
class Array
{
private:
    T* array;
    unsigned int n;

public:
    Array() : n(0)
    {
        array = new T[0];
        if (!array)
        {
            throw std::runtime_error("new failed");
        }
    }

    Array(unsigned int n) : n(n)
    {
        array = new T[n];
        if (!array)
        {
            throw std::runtime_error("new failed");
        }
    }

    Array(const Array<T>& a)
    {
        array = new T[a.size()];
        if (!array)
        {
            throw std::runtime_error("new failed");
        }
        for (unsigned int i = 0; i < a.size(); ++i)
        {
            array[i] = a[i];
        }
        n = a.size();
    }

    ~Array()
    {
        delete[] array;
    }

    Array<T>& operator=(const Array<T>& a)
    {
        T* tmp = new T[a.size()];
        if (!tmp)
        {
            throw std::runtime_error("new failed");
        }
        for (unsigned int i = 0; i < a.size(); ++i)
        {
            tmp[i] = a[i];
        }
        delete[] array;
        array = tmp;
        n = a.size();
    }

    T& operator[](unsigned int n)
    {
        if (this->n <= n)
        {
            throw std::exception();
        }
        return array[n];
    }

    const T& operator[](unsigned int n) const
    {
        if (this->n <= n)
        {
            throw std::exception();
        }
        return array[n];
    }

    unsigned int size() const
    {
        return n;
    }
};

#endif
