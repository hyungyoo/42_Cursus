#ifndef VECTOR_RANDOM_ACCESS_ITERATOR_HPP
# define VECTOR_RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

namespace ft {
	
template <typename T>
class random_access_iterator 
{
	public:
		typedef	std::random_access_iterator_tag		iterator_category;
		typedef	T									value_type;
		typedef	T*									pointer;
		typedef	T&									reference;
		typedef	std::ptrdiff_t						difference_type;
		typedef random_access_iterator<T>			iterator;
		typedef random_access_iterator<const T>		const_iterator;
	
	protected:
		pointer	_ptr;
		
	public:
		random_access_iterator(void) : _ptr(NULL) {}
		
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		
		random_access_iterator(const random_access_iterator &x) 
		{ 
			*this = x; 
		}
		
		operator const_iterator() const 
		{ 
			return const_iterator(_ptr); 
		}
		
		random_access_iterator &operator=(const random_access_iterator &x) 
		{
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}
		
		~random_access_iterator(void) {}

		pointer base(void) const 
		{
			return (_ptr);
		}
	
		reference operator*(void)
		{
			return (*_ptr);
		}
		
		bool operator==(const iterator &rhs) const 
		{
			return _ptr == rhs._ptr;
		}
		
		bool operator!=(const iterator &rhs) const 
		{
			return _ptr != rhs._ptr;
		}
			
		pointer operator->(void) 
		{
			return (_ptr);
		}

		iterator &operator++(void) 
		{
			++_ptr;
			return (*this);
		}
			
		iterator operator++(int) 
		{
			iterator tmp(*this);
			++_ptr;
			return (tmp);
		}

		iterator &operator--(void)
		{
			--_ptr;
			return (*this);
		}

		iterator operator--(int) 
		{
			iterator tmp(*this);
			--_ptr;
			return (tmp);
		}

		iterator operator+(difference_type n) const 
		{
			return iterator(_ptr + n);
		}			

		difference_type operator+(const iterator &rhs) const 
		{
			return s(_ptr + rhs._ptr);
		}

		iterator operator-(const difference_type &n) const 
		{
			return iterator(_ptr - n);
		}
		
		difference_type operator-(const iterator &rhs) const 
		{
			return (_ptr - rhs._ptr);
		}

		bool operator<(const iterator &rhs) const 
		{
			return (_ptr < rhs._ptr);			
		}

		bool operator>(const iterator &rhs) const 
		{
			return (_ptr > rhs._ptr);
		}
	
		bool operator<=(const iterator &rhs) const 
		{
			return (_ptr <= rhs._ptr);
		}

		bool operator>=(const iterator &rhs) const 
		{ 
			return (_ptr >= rhs._ptr);
		}

		iterator &operator+= (int n) 
		{
			_ptr += n;
			return (*this);
		}

		iterator &operator-= (int n) 
		{
			_ptr -= n;
			return (*this);
		}

		reference operator[](const difference_type n) const 
		{
			return (_ptr[n]);
		}
};

template<class Iterator>
random_access_iterator<Iterator> operator+(
		typename random_access_iterator<Iterator>::difference_type n, 
		const random_access_iterator<Iterator> &it) 
{
	return (random_access_iterator<Iterator>(it.base() + n));
}

template<class Iterator>
random_access_iterator<Iterator> operator-(
		typename random_access_iterator<Iterator>::difference_type n, 
		const random_access_iterator<Iterator> &it) 
{
		return (random_access_iterator<Iterator>(it.base() - n));
}

template<class iter1, class iter2>
bool operator==(const random_access_iterator<iter1> &lhs, 
				const random_access_iterator<iter2> &rhs) 
{
	bool res = lhs.base() == rhs.base();
	return (res);
}

template <class iter1, class iter2>
bool operator!=(const random_access_iterator<iter1> &lhs, 
				const random_access_iterator<iter2> &rhs) 
{
	bool res = lhs.base() != rhs.base();
	return (res);
}

template <class iter1, class iter2>
bool operator<(const random_access_iterator<iter1> &lhs, 
				const random_access_iterator<iter2> &rhs)	
{
	bool res = lhs.base() < rhs.base();
	return (res);
}

template <class iter1, class iter2>
bool operator<=(const random_access_iterator<iter1> &lhs, 
				const random_access_iterator<iter2> &rhs) 
{
	bool res = lhs.base() <= rhs.base();
	return (res);
}

template <class iter1, class iter2>
bool operator>(const random_access_iterator<iter1> &lhs, 
				const random_access_iterator<iter2> &rhs) 
{
	bool res = lhs.base() > rhs.base();
	return (res);
}

template <class iter1, class iter2>
bool operator>=(const random_access_iterator<iter1> &lhs,
				const random_access_iterator<iter2> &rhs) 
{
	bool res = lhs.base() >= rhs.base();
	return (res);
}

}

#endif
