#pragma once

# include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {
		public:
			typedef Iterator													iterator_type;
			typedef	typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef	typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

		protected:
			iterator_type	_curr;
		
		public:
			// Constructor / Destructor ============== //
			//default
			reverse_iterator() : _curr() {}
			
			//initialization
			explicit reverse_iterator (iterator_type it) : _curr(it) {}

			//copy
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _curr(rev_it.base()) {}
			
			virtual ~reverse_iterator(void) {}

			reverse_iterator &operator=(reverse_iterator const &x)
			{
				if (this != &x)
					_curr = x._curr;
				return (*this);
			}


			// Member functions ============== //
			/* Returns a copy of the base iterator. */
			iterator_type base() const {
				return (_curr);
			}

			/* operator* : *a */
			/* Returns a reference to the element pointed to by the iterator. */
			reference operator*() const {
				iterator_type tmp = _curr;
				tmp--;
				return (*tmp);
			}
			/* operator+ : a + n */
			reverse_iterator operator+ (difference_type n) const {
				return (reverse_iterator(_curr - n));
			}

			/* operator++ : ++a, a++ */
			/* Advances the reverse_iterator by one position.*/
			/* decrements the base iterator kept by the object (as if applying operator-- to it). */
			reverse_iterator& operator++() {
				--_curr;
				return (*this);
			}

			reverse_iterator  operator++(int) {
				reverse_iterator tmp = *this;
				_curr--;
				return tmp;
			}

			/* operator+= : a += n */
			/* Advances the reverse_iterator by n element positions. */
			// reverse_iterator& operator+= (difference_type n) {
			// 	_curr -= n;
			// 	return (*this);
			// }

			reverse_iterator<Iterator> &operator+=(difference_type n) {
				_curr -= n;
				return (*this);
			}

			/* operator- : a - n */
			/* Returns a reverse iterator pointing to the element located n positions before the element the iterator currently points to. */
			// reverse_iterator operator- (difference_type n) const {
			// 	return (reverse_iterator(_curr + n));
			// }

			reverse_iterator<Iterator> operator- (difference_type n) const {
			    return (reverse_iterator(_curr + n));
			}

			difference_type operator-(const reverse_iterator &rhs) const {
			    return (rhs._curr - _curr);
			}

			/* operator-- : --a, a-- */
			/*  increments the base iterator kept by the object (as if applying operator++ to it). */
			reverse_iterator& operator--() {
				_curr++;
				return (*this);
			}

			reverse_iterator  operator--(int) {
				reverse_iterator tmp = *this;
				_curr++;
				return (tmp);
			}

			/* operator-=: a -= n */
			/* Descreases the reverse_iterator by n element positions. */
			reverse_iterator& operator-= (difference_type n) {
				_curr += n;
				return (*this);
			}

			/* operator->: a-> */
			/* Returns a pointer to the element pointed to by the iterator (in order to access one of its members). */
			pointer operator->() const {
				return (&(operator*()));
			}

			/* operator[]: a[n] */
			/* Accesses the element located n positions away from the element currently pointed to by the iterator. */
			/* If such an element does not exist, it causes undefined behavior. */
			reference operator[] (difference_type n) const {
				return (*(_curr - n - 1));
			}

			bool operator==(const reverse_iterator &rhs) const {
				return (_curr == rhs._curr); 
			}

			bool operator!=(const reverse_iterator &rhs) const { 
				return (_curr != rhs._curr); 
			}
			
			bool operator<(const reverse_iterator &rhs) const { 
				return (_curr > rhs._curr); }
			
			bool operator<=(const reverse_iterator &rhs) const { 
				return (_curr >= rhs._curr); }
			
			bool operator>(const reverse_iterator &rhs) const { 
				return (_curr < rhs._curr); }
			
			bool operator>=(const reverse_iterator &rhs) const { 
				return (_curr <= rhs._curr); }
	};

	/* Non-member function overloads */
	template<class Iter1, class Iter2>
	bool operator == (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator != (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return lhs.base() != rhs.base();
	}

	template<class Iter1, class Iter2>
	bool operator< (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() > rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator> (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() < rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator<= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator>= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it) {
		return (reverse_iterator<Iterator>(it.base() - n));
	}
	
	template <typename Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it) {
		return (reverse_iterator<Iterator>(it.base() + n));
	}
}