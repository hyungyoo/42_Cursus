#ifndef SPAN_H
#define SPAN_H

#include <stdexcept>
#include <set>
#include <climits>

class Span
{
private:
    std::multiset<int> multiset;
    unsigned int maxSize;

public:
    Span();
    explicit Span(unsigned int N);
    Span(const Span& span);
    ~Span();

    Span& operator=(const Span& span);

    const std::multiset<int>& getMultiset() const;
    unsigned int getMaxSize() const;

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    void addNumber(int v);

    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end)
    {
        std::size_t remain = maxSize - multiset.size();
        std::size_t dist = std::distance(begin, end);

        if (remain < dist)
        {
            throw std::logic_error("Can't store any more");
        }
        multiset.insert(begin, end);
    }
};

#endif
