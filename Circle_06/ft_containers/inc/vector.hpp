#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "utils.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "iterator_traits.hpp"

// std::vector reference
// https://www.cplusplus.com/reference/vector/vector/

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type; 
			typedef Alloc allocator_type; 

			typedef typename allocator_type::reference reference; 
			typedef typename allocator_type::const_reference const_reference; 
			typedef typename allocator_type::pointer pointer; 
			typedef typename allocator_type::const_pointer const_pointer; 

			typedef ft::random_access_iterator<T> iterator; 
			typedef ft::random_access_iterator<const T> const_iterator; 
			typedef ft::reverse_iterator<iterator> reverse_iterator; 
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator; 

			typedef ptrdiff_t difference_type; 
			typedef size_t size_type; 

		private:
			pointer _head;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;

		public:
			explicit vector(const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(1), _alloc(alloc)
			{
				_head = _alloc.allocate(1);
			}

			explicit vector(
				size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
				: _size(n), _capacity(n), _alloc(alloc)
			{
				this->_head = _alloc.allocate(this->_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_head[i], val);
			}

			template <class InputIterator>
			vector(
				InputIterator first,
				InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			: _size(0), _capacity(0), _alloc(alloc)
			{
				this->assign(first, last);
			}

			vector(const vector& x)
			: _size(x._size), _capacity(x._size), _alloc(x._alloc)
			{
				_head = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(&_head[i], x._head[i]);
			}

			~vector()
			{
				clear();
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
			}

			vector& operator=(const vector& x)
			{
				clear();
				_size = x._size;
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
				_head = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_head[i], x._head[i]);
				_capacity < _size ? _capacity = _size : 0;

				return (*this);
			}

			iterator begin() 
			{
				return (iterator(_head));
			}

			const_iterator begin() const
			{
				return (const_iterator(_head));
			}

			iterator end() 
			{
				return (iterator(_head + _size));
			}

			const_iterator end() const
			{
				return (const_iterator(_head + _size));
			}

			reverse_iterator rbegin() 
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend() 
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			
			size_type size() const 
			{
				return (_size);
			}

			size_type max_size() const 
			{
				return (_alloc.max_size());
			}

			void resize(size_type n, value_type val = value_type()) 
			{
				if (n > _capacity)
					reallocate((n > _size * 2) ? n : _size * 2);
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			}

			size_type capacity() const 
			{
				return (_capacity);
			}

			bool empty() const 
			{
				return (_size == 0);
			}

			void reserve(size_type n) 
			{
				if (n > this->max_size())
					throw std::length_error("vector reserve error");
				if (n > _capacity)
					reallocate(n);
			}

			reference operator[](size_type n) 
			{
				return (_head[n]);
			}

			const_reference operator[](size_type n) const
			{
				return (_head[n]);
			}

			reference at(size_type n) 
			{
				if (n >= _size)
					throw std::out_of_range("vector out-of-range");
				return (_head[n]);
			}

			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector out-of-range");
				return (_head[n]);
			}

			reference front() 
			{
				return(_head[0]);
			}

			const_reference front() const
			{
				return(_head[0]);
			}

			reference back() 
			{
				return(_head[_size - 1]);
			}

			const_reference back() const
			{
				return(_head[_size - 1]);
			}

			template <class InputIterator>
			void assign(
				InputIterator first, 
				InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) 
			{
				difference_type n = 0;
				for (InputIterator it(first); it != last; it++)
					++n;
				this->clear();
				this->reserve(n);
				for (;first != last; first++)
					push_back(*first);
			}

			void assign(size_type n, const value_type& val) 
			{
				this->clear();
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

			void push_back(const value_type& val) 
			{
				if (_size == _capacity)
					reallocate(extend(_size + 1));
				_alloc.construct(&_head[_size++], val);
			}

			void pop_back() 
			{
				_alloc.destroy(&_head[--_size]);
			}

			iterator insert(iterator position, const value_type& val) 
			{
				difference_type offset = (position - this->begin());
				if (_size == _capacity)
					reallocate(extend(_size + 1));
				this->insert(this->begin() + offset, 1, val);
				return (this->begin() + offset);
			}

			void insert(iterator position, size_type n, const value_type& val) 
			{
				if (n)
				{
					// offset	itr +/- itr = difference_type;
					difference_type offset = position - this->begin();
					// last position	
					difference_type difference_type_tmp = this->end() - this->begin();
					// capacity
					this->resize(this->_size + n);
					// end iterator for while
					iterator end_iterator = this->end();
					position = this->begin() + offset;
					iterator tmp_end_iterator = this->begin() + difference_type_tmp;
					while (tmp_end_iterator != position)
					{
						--end_iterator;
						--tmp_end_iterator;
						*end_iterator = *tmp_end_iterator;
					}
					while (n--)
						*position++ = val;
					
				}
			}

			template <class InputIterator>
			void insert(iterator position, 
					InputIterator first, 
					InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				difference_type offset = (position - this->begin());
				size_type n = 0;
				InputIterator tmp(first);
				while (tmp != last)
				{
					++tmp;
					++n;
				}
				if ((_size + n) > _capacity)
					reallocate((_size + n > _size * 2) ? _size + n : _size * 2);
				size_type destroyIndex = _size;
				iterator itToInsertPos(&_head[_size]);
				_size += n;
				iterator insertPos(this->begin() + offset);
				iterator itForInsert = this->end();
				while (itToInsertPos >= insertPos)
				{
					*--itForInsert = *--itToInsertPos;
					_alloc.destroy(&_head[destroyIndex--]);
				}
				while (first != last)
					_alloc.construct(&(*insertPos++), *first++);
			}

			iterator erase(iterator position) 
			{
				return (this->erase(position, position + 1));
			}

			iterator erase(iterator first, iterator last) 
			{
				if (this->empty())
					return (last);
				difference_type n = last - first;
				iterator ret(first);
				while (last != this->end())
					*(first++) = *(last++);
				while (n--)
					this->pop_back();
				return (ret);
			}

			void swap(vector& x)
			{
				swap(_size, x._size);
				swap(_capacity, x._capacity);
				swap(_alloc, x._alloc);
				swap(_head, x._head);
			}

			void clear() 
			{
				for (size_type i = 0; i < _size; ++i)
					this->pop_back();
				_size = 0;
			}

			allocator_type get_allocator() const // vector 생성에 필요한 할당자의 복사본을 반환
			{
				return (_alloc);
			}

		private:
			size_type extend(size_type new_size)
			{
				size_type	new_capacity(_capacity);
				if (!new_capacity)
					new_capacity = 1;
				while (new_capacity < new_size)
					new_capacity *= 2;
				return (new_capacity);
			}

			void reallocate(size_type new_capacity)
			{
				pointer new_head = _alloc.allocate(new_capacity);
				size_type	tmp = _size;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&new_head[i], _head[i]);
				clear();
				_size = tmp;
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
				_head = new_head;
				_capacity = new_capacity;
			}

			template<class U>
			void swap(U& u1, U& u2)
			{
				U tmp = u2;
				u2 = u1;
				u1 = tmp;
			}
	};

		template <class T, class Alloc>
		bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template <class T, class Alloc>
		bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs == rhs);
		}

		template <class T, class Alloc>
		bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Alloc>
		bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(rhs < lhs);
		}

		template <class T, class Alloc>
		bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

		template <class T, class Alloc>
		bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs);
		}

		template <class T, class Alloc>
		void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
}

#endif
