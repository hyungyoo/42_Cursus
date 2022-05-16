#ifndef VECTOR_RANDOM_ACCESS_ITERATOR_HPP
# define VECTOR_RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {
	
	template <typename T>
	class random_access_iterator 
	{
		public:
			typedef	std::random_access_iterator_tag	iterator_category;
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	std::ptrdiff_t					difference_type;
			typedef random_access_iterator<T>		iterator;
			typedef random_access_iterator<const T>	const_iterator;

		protected:
			pointer	_ptr;
		
		public:
			random_access_iterator(void) : _ptr(NULL) {}
			
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			
			random_access_iterator(const random_access_iterator &x) { *this = x; }
			
			operator random_access_iterator<value_type const>() const { return random_access_iterator<value_type const>(_ptr); }
			
			random_access_iterator &operator=(const random_access_iterator &x) {
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}
			virtual ~random_access_iterator(void) {}

			/*
			pointer	get_ptr(void) const {
				return (_ptr);
			}
			*/

			pointer base(void) const {
				return (_ptr);
			}
	
			/* a == b; a != b */
			bool operator== (const iterator &rhs) const {
				return _ptr == rhs._ptr;
			}
		
			bool operator!= (const iterator &rhs) const {
				return _ptr != rhs._ptr;
			}

			/* *a; *a = t */
			reference operator* (void) {
				return (*_ptr);
			}

			/* a->m; */
			pointer operator-> (void) {
				return (_ptr);
			}

			/* ++a; a++; *a++ */
			iterator &operator++ (void) { //++a
				++_ptr;
				return (*this);
			}
			
			iterator operator++ (int) { //a++
				iterator tmp = *this;
				++_ptr;
				return (tmp);
			}

			/* --a; a--; *a-- */
			iterator &operator-- (void) { //--a
				--_ptr;
				return (*this);
			}

			iterator operator-- (int) { //a--
				iterator tmp = *this;
				--_ptr;
				return (tmp);
			}

			/* a + n */
			iterator operator+(difference_type n) const {
				iterator res = _ptr + n;
				return (res);
			}			

			/* n + a */
			difference_type operator+(const iterator &rhs) const {
				difference_type res = _ptr + rhs._ptr;
				return (res);
			}

			/* a - n */
			iterator operator- (const difference_type &n) const {
				return iterator(_ptr - n);
			}

			/* a - b */
			difference_type operator- (const iterator &rhs) const {
				return (_ptr - rhs._ptr);
			}

			/* a < b */
			bool operator< (const iterator &rhs) const {
				return (_ptr < rhs._ptr);
			}

			/* a > b */
			bool operator> (const iterator &rhs) const {
				return (_ptr > rhs._ptr);
			}
	
			/* a <= b */
			bool operator<= (const iterator &rhs) const {
				return (_ptr <= rhs._ptr);
			}

			/* a >= b */
			bool operator>= (const iterator &rhs) const { 
				return (_ptr >= rhs._ptr);
			}

			/* a += n */
			iterator &operator+= (int n) {
				_ptr += n;
				return (*this);
			}

			/* a -= n */
			iterator &operator-= (int n) {
				_ptr -= n;
				return (*this);
			}

			/* a[n] */
			reference operator[](const difference_type n) const {
				return (_ptr[n]);
			}
	};

	//nonmember functions
	template<class Iterator>
	random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &it) {
		return (random_access_iterator<Iterator>(it.base() + n));
	}

	template<class Iterator>
	random_access_iterator<Iterator> operator-(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &it) {
		return (random_access_iterator<Iterator>(it.base() - n));
	}

	template<class iter1, class iter2>
	bool operator==(const random_access_iterator<iter1> &lhs, const random_access_iterator<iter2> &rhs) {
		bool res = lhs.base() == rhs.base();
		return (res);
	}

	template <class iter1, class iter2>
	bool operator!=(const random_access_iterator<iter1> &lhs, const random_access_iterator<iter2> &rhs) {
		bool res = lhs.base() != rhs.base();
		return (res);
	}

	template <class iter1, class iter2>
	bool operator<(const random_access_iterator<iter1> &lhs, const random_access_iterator<iter2> &rhs) {
		bool res = lhs.base() < rhs.base();
		return (res);
	}

	template <class iter1, class iter2>
	bool operator<=(const random_access_iterator<iter1> &lhs, const random_access_iterator<iter2> &rhs) {
		bool res = lhs.base() <= rhs.base();
		return (res);
	}

	template <class iter1, class iter2>
	bool operator>(const random_access_iterator<iter1> &lhs, const random_access_iterator<iter2> &rhs) {
		bool res = lhs.base() > rhs.base();
		return (res);
	}

	template <class iter1, class iter2>
	bool operator>=(const random_access_iterator<iter1> &lhs, const random_access_iterator<iter2> &rhs) {
		bool res = lhs.base() >= rhs.base();
		return (res);
	}
}

#endif
