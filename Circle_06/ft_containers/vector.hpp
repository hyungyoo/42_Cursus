#ifndef FT_CONTAINERS_VECTOR_HPP
# define FT_CONTAINERS_VECTOR_HPP

# include <iostream>
# include <sstream>

# include "utils.hpp"
# include "iterator/iterator_traits.hpp"
# include "iterator/random_access_iterator.hpp"
# include "iterator/reverse_iterator.hpp"

namespace ft {

	//T 	: type of container's elements 
	//Alloc : Type of the allocator object used to define the storage allocation model.
	//			By default, the allocator class template is used, which defines the simplest memory allocation model and is value-independent.				
	template <class T, class Alloc = std::allocator<T> > /* <typename T> == <class T>*/
	class vector {
		public:
			typedef T									value_type;			//First template parameter (T)
			typedef	Alloc								allocator_type;		//The seconde template parameter (Alloc)
			typedef std::ptrdiff_t						difference_type;	//a signed integral type, same as iterator_traits<iterator>::difference_type and ptrdiff_t (long int)
			typedef size_t								size_type;			//an unsigned integral type that can represent any non-negative value of difference_type, same as size_t

			typedef T&									reference;
			typedef const T&							const_reference;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			
			typedef random_access_iterator<T>			iterator;
			typedef random_access_iterator<const T>		const_iterator;
			typedef reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef reverse_iterator<iterator>			reverse_iterator;

		private:
			size_type				_size;		//Number of T values inside the vector
			size_type				_capacity;	//Capacity allocated (not always as same as size)
			allocator_type		 	_alloc;		//Copy of allocator_type object
			pointer 				_array;		//Pointer on an array of T values
		
		// tool
		private:
			void	reallocate(size_type n) {
				value_type	*tmp = _alloc.allocate(n, &_array);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&tmp[i], _array[i]);
				_alloc.deallocate(_array, _size);
				_capacity = n;
				_array = tmp;
			}

		// getter, setter
		public:
			size_type	get_size(void) const {
				return (_size);
			}
			
			void		set_size(size_type size) { 
				_size = size;
			}
			
			void		set_capacity(size_type capacity) {
				_capacity = capacity;
			}
			
			void		set_pointer(pointer ptr) {
				_array = ptr;
			}
			
		public:
			// Constructor / Destructor ============== //
			
			/* default constructor */
			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _array(NULL) {
			}
			
			/* fill constructor */
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _size(n), _capacity(n), _alloc(alloc), _array(NULL) {
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_array[i], val);
			}

			/* range constructor => iterator needed */ 
			template <class InputIterator>
			vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
			const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _array(NULL) {
				InputIterator tmp(first);
				while (tmp++ != last)
					_size++;
				set_capacity(get_size());
				//As requested, allocated in one call
				_array = _alloc.allocate(get_size()); //get_capacity()
				for (int i = 0; first != last; ++first, ++i)
					_alloc.construct(&_array[i], *first);
			}

			/* copy constructor */
			vector (const vector& x)
				: _size(x._size), _capacity(x._size), _alloc(x._alloc), _array(NULL) {
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < get_size(); i++)
					_alloc.construct(&_array[i], x._array[i]);
			}

			/* destructor */
			~vector() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				_alloc.deallocate(_array, _size);
			}

			/* operator= */
			vector& operator= (const vector& x) {
				if (x == *this)
					return (*this);
				clear();
				insert(end(), x.begin(), x.end());
				return (*this);
			}

			// Iterator ========================================================= //

			iterator begin() {
				return (iterator(&_array[0]));
			}
			
			const_iterator begin() const {
				return (const_iterator(&_array[0]));
			}

			iterator end() {
				return (iterator(&_array[_size]));
			}
			
			const_iterator end() const {
				return (const_iterator(&_array[_size]));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			}
			
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			}


			// Capacity ========================================================= //

			/* Returns the number of elements in the vector. */
			/* Actual objects held in the vector */
			size_type size() const {
				return (_size);
			}

			/* Returns the maximum number of elements that the vector can hold. */
			/* max_size in allocator : Returns the number of elements of type Type that could be allocated by an object of class allocator before the free memory is used up. */
			size_type max_size() const {
				return (_alloc.max_size());
			}

			/* Function resizes the container so that it contains n elements. */
			/* n 	: New container size, expressed in number of elements. */
			/* val	: Object whose content is copied to the added elements in case that n is greater than the current container size.
						If not specified, the default constructor is used instead.*/
			void resize (size_type n, value_type val = value_type()) {
				if (n > capacity())
				{
					if (n <= _size * 2)
						reserve(_size * 2);
					else
						reserve(n);
				}
				for (size_type i = _size; i < n; i++)
					_alloc.construct(&_array[i], val);
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(&_array[i]);
				set_size(n);
			}

			/* Returns the size of the storage space currently allocated for the vector, expressed in terms of elements. */
			size_type capacity() const {
				return (_capacity);
			}

			/* Returns whether the vector is empty (i.e. whether its size is 0). */
			/* don't confuse with vector::clear(), it's not vector::clear() */
			bool empty() const {
				if (_size != 0)
					return (false);
				return (true);
			}

			/* Requests that the vector capacity be at least enough to contain n elements. */
			/* If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater). */
			/* In other case (n <= cap), do nothing */
			/* No effect on _size */
			/* n : Minimum capacity for the vector. */
			void reserve (size_type n) {
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity)
				{
					pointer nptr = _alloc.allocate(n);
					int end = get_size();
					for (int start = 0; start < end; start++)
					{
						_alloc.construct(&nptr[start], _array[start]);
						_alloc.destroy(&_array[start]);
					}
					_alloc.deallocate(_array, _capacity);
					set_pointer(nptr);
					set_capacity(n);
				}
			}

			// Element access =================================================== //

			/* Returns a reference to the element at position n in the vector container. */
			/* n: Position of an element in the container. */
			reference operator[] (size_type n) {
				reference element = *(_array + n);
				return (element);
			}
			const_reference operator[] (size_type n) const {
				const_reference element = *(_array + n);
				return (element);
			}

			/* Returns a reference to the element at position n in the vector. */
			/* n: Position of an element in the container. */
			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("vector");
				reference ret = _array[n];
				return (ret);
			}
			
			const_reference at (size_type n) const {
				if (n >= _size)
					throw std::out_of_range("vector");
				const_reference ret = _array[n];
				return (ret);
			}

			/* Returns a reference to the first element in the vector. */
			reference front() {
				reference ret = *(_array);
				return (ret);
			}
			
			const_reference front() const {
				const_reference ret = *(_array);
				return (ret);
			}

			/* Returns a reference to the last element in the vector. */
			reference back() {
				reference ret = _array[_size - 1];
				return (ret);
			}
			
			const_reference back() const {
				const_reference ret = _array[_size - 1];
				return (ret);

			}

			// Modifiers ======================================================= //

			/* Assigns new contents to the vector, replacing its current contents, */
			/* and modifying its size accordingly. */

			/* (1) the new contents are elements constructed from each of the elements in the range between first and last, in the same order. */
			/* Input iterators to the initial and final positions in a sequence. The range used is [first,last), */
			/* which includes all the elements between first and last, including the element pointed by first but not the element pointed by last. */
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0) {
				size_type n = 0;
				size_type i = 0;
				InputIterator it(first);

				while (it != last)
				{
					n++;
					it++;
				}
				if (!n)
					return ;
				i = 0;
				for(size_type j = 0; j < _size; j++)
					_alloc.destroy(&_array[j]);
				if (n > _capacity)
				{
					size_type _tmp_capacity = _capacity;
					if (n <= _size * 2)
						_capacity = _size * 2;
					else
						_capacity = n;
					_alloc.deallocate(_array, _tmp_capacity);
					_array = _alloc.allocate(_capacity);
				}
				set_size(n);
				i = 0;
				while (first != last)
				{
					_alloc.construct(&_array[i], *first);
					first++;
					i++;
				}
			}
			
			/* (2) the new contents are n elements, each initialized to a copy of val. */
			/* n: New size for the container. */
			/* val: Value to fill the container with. */
			void assign (size_type n, const value_type& val) {
				if (n > _capacity)
					reallocate(n);
				_size = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_array[i], val);
			}

			/* The vector is extended by inserting new elements before the element at the specified position, */
			/* effectively increasing the container size by the number of elements inserted. */
			/* position: Position in the vector where the new elements are inserted. */
			/* val: Value to be copied (or moved) to the inserted elements */
			/* return: An iterator that points to the first of the newly inserted elements. */
			iterator insert (iterator position, const value_type& val) {
				difference_type distance = position.get_ptr() - _array;
				insert(position, 1, val);
				return (iterator(begin() + distance));
			}
			
			/* n: Number of elements to insert. */
			void insert (iterator position, size_type n, const value_type& val) {
				if (!n)
					return ;
				size_type begin_to_pos = 0;
				size_type pos_to_end = 0;
				size_type i = 0;
				iterator it = begin();
				while (it != position)
				{
					begin_to_pos++;
					it++;
				}
				while (it != end())
				{
					pos_to_end++;
					it++;
				}
				if (_size + n > _capacity)
				{
					if (_size + n <= _size * 2)
						reserve(_size * 2);
					else
						reserve(_size + n);
				}
				while (i < pos_to_end)
				{
					_alloc.construct(&_array[begin_to_pos + n + pos_to_end - i - 1], _array[begin_to_pos + pos_to_end - i - 1]);
					_alloc.destroy(&_array[begin_to_pos + pos_to_end - i - 1]);
					i++;
				}
				i = 0;
				while (i < n)
				{
					_alloc.construct(&_array[begin_to_pos + i], val);
					i++;
				}
				set_size(_size + n);
			}
			
			/* first, last: Iterators specifying a range of elements. (including first but not last) */
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0) {
				size_type n = 0;
				size_type begin_to_pos = 0;
				size_type pos_to_end = 0;
				InputIterator Init = first;
				while (Init != last)
				{
					Init++;
					n++;
				}
				iterator it = begin();
				while (it != position)
				{
					begin_to_pos++;
					it++;
				}
				while (it != end())
				{
					pos_to_end++;
					it++;
				}
				if (_size + n > _capacity)
				{
					if (_size + n < _capacity * 2)
						reserve(_capacity * 2);
					else
						reserve(_size + n);
				}
				for (size_type i = 0; i < pos_to_end; i++)
				{
					_alloc.construct(&_array[begin_to_pos + n + pos_to_end - i - 1], _array[begin_to_pos + pos_to_end - i - 1]);
					_alloc.destroy(&_array[begin_to_pos + pos_to_end - i - 1]);
				}
				Init = first;
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(&_array[begin_to_pos + i], *Init);
					Init++;
				}
				set_size(_size + n);
			}
			
			/*Removes from the vector either a single element (position) or a range of elements ([first,last)).*/
			/* This effectively reduces the container size by the number of elements removed, which are destroyed.*/
			/* return: An iterator pointing to the new location of the element that followed the last element erased by the function call.*/
			/* position: Iterator pointing to a single element to be removed from the vector. */
			iterator erase (iterator position) {
				return (erase(position, position + 1));
			}

			/* Iterators specifying a range within the vector] to be removed: [first,last). */
			/* i.e., the range includes all the elements between first and last, including the element pointed by first but not the one pointed by last.*/
			iterator erase (iterator first, iterator last) {
				if (empty())
					return (last);
				difference_type n = last - first;
				iterator	ret(first);
				while (last != end())
					*(first++) = *(last)++;
				while (n--)
					pop_back();
				return (ret);
			}

			/* Adds a new element at the end of the vector, after its current last element. */
			void push_back (const value_type& val) {
				if (_size == capacity())
				{
					if (!_size)
						reserve(1);
					else
						reserve(capacity() * 2);
				}
				_alloc.construct(&_array[_size], val);
				_size++;
			}

			/* Removes the last element in the vector, effectively reducing the container size by one. */
			/* This destroys the removed element. */
			void pop_back() {
				_alloc.destroy(&_array[_size - 1]);
				_size--;
			}

			/* Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ. */
			void swap (vector& x) {
				std::swap(_array, x._array);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
			}

			/* Removes all elements from the vector (which are destroyed), leaving the container with a size of 0. */
			void clear() {
				for(size_type i = 0;i < _size; i++)
					_alloc.destroy(&_array[i]);
				_size = 0;
			}

			// Allocator ======================================================= //
			
			/* Returns a copy of the allocator object associated with the vector. */
			allocator_type get_allocator() const {
				allocator_type copy_allocator(_alloc);
				return copy_allocator;
			}
			
		};

		// Non-member function overloads ======================== //
		/* Performs the appropriate comparison operation between the vector containers lhs and rhs. */

		/* 	The equality comparison (operator==) is performed by first comparing sizes, 
			and if they match, the elements are compared sequentially using operator==, stopping at the first mismatch. */
		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			typename ft::vector<T>::const_iterator first1 = lhs.begin();
			typename ft::vector<T>::const_iterator first2 = rhs.begin();
			while (first1 != lhs.end())
			{
				if (first2 == rhs.end() || *first1 != *first2)
					return (false);
				++first1;
				++first2;
			}
			return (true);
		}

		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (!(lhs == rhs));
		}

		/* The less-than comparison (operator<) behaves as if using algorithm lexicographical_compare, */
		/* which compares the elements sequentially using operator< in a reciprocal manner (i.e., checking both a<b and b<a) */
		/* and stopping at the first occurrence. */
		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
			
		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (rhs < lhs);
		}
			
		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			bool res1 = lhs < rhs;
			bool res2 = lhs == rhs;
			return (res1 || res2);
		}

		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			bool res1 = lhs > rhs;
			bool res2 = lhs == rhs;
			return( res1 || res2);
		}

		/* The contents of container x are exchanged with those of y. */
		/* Both container objects must be of the same type (same template parameters), */
		/* although sizes may differ. */
		/* x,y: vector containers of the same type */
		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
			x.swap(y);
		}

} // end of namespace ft

#endif