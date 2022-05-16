#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

// https://www.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator
// https://wetodev.rd.tuni.fi/wetoextra/cpp/en/cpp/iterator/reverse_iterator.html


template <class Iterator>
class reverse_iterator : public ft::iterator<
						 typename ft::iterator_traits<Iterator>::iterator_category,
						 typename ft::iterator_traits<Iterator>::value_type,
						 typename ft::iterator_traits<Iterator>::difference_type,
						 typename ft::iterator_traits<Iterator>::pointer,
						 typename ft::iterator_traits<Iterator>::reference>
{
	public:
		typedef Iterator													iterator_type;
		typedef	typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef	typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		protected:
			iterator_type	_current;
		
		// https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/
		public:
			// default constructor
			reverse_iterator() : _current() {}
			
			// initialization
			explicit reverse_iterator (iterator_type it) : _current(it) {}

			// copy
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _current(rev_it.base()) {}
			
			~reverse_iterator(void) {}

			// https://wetodev.rd.tuni.fi/wetoextra/cpp/en/cpp/iterator/reverse_iterator/operator%3D.htmla
			// c++11, 필요없음
			reverse_iterator &operator=(const reverse_iterator &rhs)
			{
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			}

			iterator_type base() const 
			{
				return (this->_current);
			}

			reference operator*() const 
			{
				// 0? 1 2 4 5?일때,
				// iterator begin 은 0, end는 '5?'
				// reverse_iterator begin은 4, end는 '5?'
				// _current이 가르키는곳은 begin이므로, end iterator ('5?')에서 하나 뒤로가야한다.
				iterator_type tmp = _current;
				tmp--;
				return (*tmp);
			}
			
			reverse_iterator operator+(difference_type n) const 
			{
				return (reverse_iterator(this->_current - n));
			}

			reverse_iterator& operator++() 
			{
				--_current;
				return (*this);
			}

			reverse_iterator  operator++(int) 
			{
				reverse_iterator tmp = *this;
				_current--;
				return tmp;
			}

			reverse_iterator &operator+=(difference_type n) 
			{
				_current -= n;
				return (*this);
			}

			reverse_iterator operator-(difference_type n) const 
			{
			    return (reverse_iterator(_current + n));
			}

			difference_type operator-(const reverse_iterator &rhs) const 
			{
			    return (rhs._current - _current);
			}

			reverse_iterator &operator--() 
			{
				_current++;
				return (*this);
			}

			reverse_iterator  operator--(int) 
			{
				reverse_iterator tmp = *this;
				_current++;
				return (tmp);
			}

			reverse_iterator& operator-=(difference_type n) 
			{
				_current += n;
				return (*this);
			}

			pointer operator->() const 
			{
				return (&(operator*()));
			}

			reference operator[] (difference_type n) const 
			{
				return (*(_current - n - 1));
			}

			bool operator==(const reverse_iterator &rhs) const 
			{
				return (_current == rhs._current); 
			}

			bool operator!=(const reverse_iterator &rhs) const 
			{ 
				return (_current != rhs._current); 
			}
			
			bool operator<(const reverse_iterator &rhs) const 
			{ 
				return (_current > rhs._current); }
			
			bool operator<=(const reverse_iterator &rhs) const 
			{ 
				return (_current >= rhs._current); }
			
			bool operator>(const reverse_iterator &rhs) const 
			{ 
				return (_current < rhs._current); }
			
			bool operator>=(const reverse_iterator &rhs) const 
			{ 
				return (_current <= rhs._current); }
	};

	template<class Iter1, class Iter2>
	bool operator==(const reverse_iterator<Iter1>& lhs, 
					const reverse_iterator<Iter2>& rhs) 
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator!=(const reverse_iterator<Iter1>& lhs, 
					const reverse_iterator<Iter2>& rhs) 
	{
		return lhs.base() != rhs.base();
	}

	template<class Iter1, class Iter2>
	bool operator<(const reverse_iterator<Iter1>& lhs, 
					const reverse_iterator<Iter2>& rhs) 
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator>(const reverse_iterator<Iter1>& lhs, 
					const reverse_iterator<Iter2>& rhs) 
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator<=(const reverse_iterator<Iter1>& lhs, 
					const reverse_iterator<Iter2>& rhs) 
	{
		return (lhs.base() >= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator>=(const reverse_iterator<Iter1>& lhs, 
					const reverse_iterator<Iter2>& rhs) 
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(
			typename reverse_iterator<Iterator>::difference_type n, 
			const reverse_iterator<Iterator> &it) {
		return (reverse_iterator<Iterator>(it.base() - n));
	}
	
	template <typename Iterator>
	reverse_iterator<Iterator> operator-(
			typename reverse_iterator<Iterator>::difference_type n, 
			const reverse_iterator<Iterator> &it) {
		return (reverse_iterator<Iterator>(it.base() + n));
	}
}

#endif
