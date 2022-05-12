#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "utils.hpp"
#include "iterator_traits.hpp"
// https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a02021.html
// 누가만든건지 ㅅㅂ

namespace  ft
{
// template <class Iterator> class reverse_iterator;
template<typename Iter>
class reverse_iterator : public ft::iterator<typename ft::iterator_traits<Iter>::iterator_category,
	typename ft::iterator_traits<Iter>::value_type,
	typename ft::iterator_traits<Iter>::difference_type,
	typename ft::iterator_traits<Iter>::pointer,
	typename ft::iterator_traits<Iter>::reference >
{
// typename for reverse_iterator

protected:
	Iter	_current;

public:
	typedef Iter	iterator_type;
	typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_categoty;
	typedef typename ft::iterator_traits<Iter>::value_type		value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer		pointer;
	typedef typename ft::iterator_traits<Iter>::reference		reference;

	// https://en.cppreference.com/w/cpp/iterator/reverse_iterator/reverse_iterator
	// https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/
	
	// default constructor
	reverse_iterator()	: _current(NULL) {}

	// initialization constructor
	explicit reverse_iterator(iterator_type	x): _current(x) {}

	reverse_iterator( const reverse_iterator &x ) : _current(x.base()) {}

	// copy / type-cast construcor
	template< class U >
	reverse_iterator( const reverse_iterator<U> &other ): _current(other.base()) {}

	~reverse_iterator() {}


	template< class U >
	reverse_iterator  &operator=(reverse_iterator<U> const &other)
	{
		this->_current = other.base();
		return (*this);
	}

	iterator_type	base() const
	{
		return (this->_current);
	}

	/* 병신같이 참조자로 내보내면 큰일남 
	 * 병신짓 기념으로 여기서 한시간날림 ㅎㅎ
	 * 행복하다
	 */
	reference operator*() const
	{
		/* 대입 연산자는 메모리 소비
		 * 복사생성자에 인자로 넣어서 바로 리턴
		 */
		iterator_type tmp(this->base());
		return ( *(--tmp) );
	}

	reverse_iterator	operator+(difference_type n) const
	{
		return (reverse_iterator(_current - n));
	}

	reverse_iterator &operator++()
	{
		--_current;
		return (*this);
	}
	
	reverse_iterator operator++(int)
	{
		reverse_iterator	tmp = *this;
		--_current;
		return (tmp);
	}

	reverse_iterator &operator+=(difference_type n)
	{
		_current -= n;
		return (*this);
	}

	reverse_iterator	operator-(difference_type n) const
	{
		return (reverse_iterator(_current + n));
	}

	reverse_iterator &operator--()
	{
		++_current;
		return (*this);
	}
	
	reverse_iterator operator--(int)
	{
		reverse_iterator	tmp = *this;
		++_current;
		return (tmp);
	}

	reverse_iterator &operator-=(difference_type n)
	{
		_current += n;
		return (*this);
	}

	/* Iter에 있는 -> 접근자 사용
	 */
	pointer operator->() const
	{
		return ( &(operator*()) );
	}

	reference	operator[](difference_type n) const
	{
		return (*((*this) + n));
	}

};

	template<typename Iter>
	inline bool
	operator==(const reverse_iterator<Iter> &lhs,
		   const reverse_iterator<Iter> &rhs)
	{ return lhs.base() == rhs.base(); }
		
	template<typename Iter>
	inline bool
	operator!=(const reverse_iterator<Iter> &lhs,
		   const reverse_iterator<Iter> &rhs)
	{ return lhs.base() != rhs.base(); }
	
	template<typename Iter>
	inline bool
	operator<(const reverse_iterator<Iter> &lhs,
		   const reverse_iterator<Iter> &rhs)
	{ return lhs.base() < rhs.base(); }
	
	template<typename Iter>
	inline bool
	operator<=(const reverse_iterator<Iter> &lhs,
		   const reverse_iterator<Iter> &rhs)
	{ return lhs.base() <= rhs.base(); }
	
	template<typename Iter>
	inline bool
	operator>(const reverse_iterator<Iter> &lhs,
		   const reverse_iterator<Iter> &rhs)
	{ return lhs.base() > rhs.base(); }
	
	template<typename Iter>
	inline bool
	operator>=(const reverse_iterator<Iter> &lhs,
		   const reverse_iterator<Iter> &rhs)
	{ return lhs.base() >= rhs.base(); }

	template <class Iter>
	reverse_iterator<Iter> operator+(
			typename reverse_iterator<Iter>::difference_type n,
			const reverse_iterator<Iter>& rev_it)
	{
		reverse_iterator<Iter> tmp(rev_it.base() - n);
		return (tmp);
	}

	template <class Iter>
	reverse_iterator<Iter> operator-(
			const reverse_iterator<Iter>& lhs,
			const reverse_iterator<Iter>& rhs)
	{
		return (rhs.base() - lhs.base());
	}


}

#endif
