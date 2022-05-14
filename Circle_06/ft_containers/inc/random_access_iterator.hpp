#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template<class T>
class random_access_iterator {

public:
    typedef std::random_access_iterator_tag        iterator_category;
    typedef T*                                     pointer;
    typedef T&                                     reference;
    typedef std::ptrdiff_t                         difference_type;
    typedef T                                      value_type;

protected:
    pointer _ptr;

public:
    random_access_iterator() : _ptr(NULL) {}

    random_access_iterator(pointer ptr) : _ptr(ptr) {}

    random_access_iterator(random_access_iterator const &other) : _ptr(other._ptr) { }
    
	random_access_iterator& operator=(random_access_iterator const &other)
    {
        this->_ptr = other._ptr;
        return (*this);
    }
    
    ~random_access_iterator() {}
    
	pointer base() const
    {
        return (_ptr);
    }

    bool operator==(random_access_iterator const &rhs) const
    {
		return (this->_ptr == rhs._ptr);
    }

    bool operator!=(random_access_iterator const &rhs) const
    {
		return (this->_ptr != rhs._ptr);
    }

    reference operator*()  const
	{
		return ( *(this->_ptr) ); 
	}
    
    pointer operator->() const
    {
        return (this->_ptr);
    }

    random_access_iterator &operator++()
    {
        this->_ptr++;
        return (*this);
    }

    random_access_iterator operator++(int)
    {
        random_access_iterator tmp(*this);
        ++(*this);
        return (tmp);
    }
    
	random_access_iterator &operator--() 
    { 
        this->_ptr--; 
        return (*this); 
    }

    random_access_iterator operator--(int)
    {
        random_access_iterator tmp(*this);
		(*this)--;
        return (tmp);
    }

    random_access_iterator operator-(difference_type const &x) const 
	{ 
		return ( random_access_iterator(_ptr - x) ); 
	}
    
	difference_type operator-(random_access_iterator const &rhs) const 
	{ 
		return (this->_ptr - rhs._ptr);	
	}

    friend random_access_iterator operator+(difference_typen, random_access_iterator const &rhs) 
	{ 
		return ( rhs.operator+(n) ); 
	}
    
	random_access_iterator operator+(int const n) const 
	{ 
		return ( random_access_iterator(_ptr + n) ); 
	}
    
    
    bool operator>(random_access_iterator const &rhs) const 
	{ 
		return (this->_ptr > rhs._ptr); 
	}
    
	bool operator>=(random_access_iterator const &rhs) const 
	{ 
		return (this->_ptr >= rhs._ptr); 
	}
	
	bool operator<(random_access_iterator  const &rhs) const 
	{ 
		return (this->_ptr < rhs._ptr); 
	}
    
    bool operator<=(random_access_iterator const &rhs) const 
	{
		return (this->_ptr <= rhs._ptr); 
	}

    random_access_iterator& operator+=(int n) 
	{ 
		_ptr += n; 
		return (*this); 

	}

    random_access_iterator &operator-=(int n) 
	{ 
		_ptr -= n; 
		return (*this); 
	}
    
    reference operator[] (int index)
    {
        return *(_ptr + index);
    }

};

template<class Iterator>
random_access_iterator<Iterator> operator+(
		typename random_access_iterator<Iterator>::difference_type n, 
		random_access_iterator<Iterator>  const &it)
{
    return random_access_iterator<Iterator>(it.base() + n);
}

template<class Iterator>
random_access_iterator<Iterator> operator-(
		typename random_access_iterator<Iterator>::difference_type n, 
		random_access_iterator<Iterator> const &it)
{
    return random_access_iterator<Iterator>(it.base() - n);
}

template<class it1, class it2>
bool operator==(
		random_access_iterator<it1> const &lhs, 
		random_access_iterator<it2> const &rhs)
{
    bool res = lhs.get_ptr() == rhs.get_ptr();
    return (res);
}

template <class it1, class it2>
bool operator!=(
		random_access_iterator<it1> const &lhs, 
		random_access_iterator<it2> const &rhs)
{
    bool res = lhs.get_ptr() != rhs.get_ptr();
    return res;
}

template <class it1, class it2>
bool operator<(
		random_access_iterator<it1> const &lhs, 
		random_access_iterator<it2> const &rhs)
{
    bool res = lhs.get_ptr() < rhs.get_ptr();
    return res;
}

template <class it1, class it2>
bool operator<=(
		random_access_iterator<it1> const &lhs, 
		random_access_iterator<it2> const &rhs)
{
    bool res = lhs.get_ptr() <= rhs.get_ptr();
    return res;
}

template <class it1, class it2>
bool operator>(
		random_access_iterator<it1> const &lhs, 
		random_access_iterator<it2> const &rhs)
{
    bool res = lhs.get_ptr() > rhs.get_ptr();
    return res;
}

template <class it1, class it2>
bool operator>=(
		random_access_iterator<it1> const &lhs, 
		random_access_iterator<it2> const &rhs)
{
    bool res = lhs.get_ptr() >= rhs.get_ptr();
    return res;
}

}

#endif
