#include "span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span& span) : multiset(span.getMultiset()), maxSize(span.getMaxSize()) {}

Span::~Span() {}

Span& Span::operator=(const Span& span)
{
    multiset = span.getMultiset();
    maxSize = span.getMaxSize();
    return *this;
}

const std::multiset<int>& Span::getMultiset() const
{
    return multiset;
}

unsigned int Span::getMaxSize() const
{
    return maxSize;
}

unsigned int Span::shortestSpan() const
{
    if (multiset.size() <= 1)
    {
        throw std::logic_error("Not enough numbers stored");
    }

    std::multiset<int>::iterator beforeIt = multiset.begin();
    unsigned int shotSpan = UINT_MAX;
    for (std::multiset<int>::iterator it = multiset.begin(); it != multiset.end(); ++it)
    {
        if (it == multiset.begin())
            continue;
        shotSpan = std::min(shotSpan, static_cast<unsigned int>(*it - *beforeIt));
        beforeIt = it;
    }
    return shotSpan;
}

unsigned int Span::longestSpan() const
{
    if (multiset.size() <= 1)
    {
        throw std::logic_error("Not enough numbers stored");
    }
    return *multiset.rbegin() - *multiset.begin();
}

void Span::addNumber(int v)
{
    if (multiset.size() == maxSize)
    {
        throw std::logic_error("Can't store any more");
    }
    multiset.insert(v);
}
