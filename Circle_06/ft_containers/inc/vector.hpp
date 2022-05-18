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
			typedef T value_type; // vector에 저장된 데이터 형식을 나타내는 형식
			typedef Alloc allocator_type; // vector 개체의 allocator 클래스를 나타내는 형식

			typedef typename allocator_type::reference reference; // vector에 저장된 요소에 대한 참조를 제공하는 형식
			typedef typename allocator_type::const_reference const_reference; // 위와 동일, 하지만 요소의 변경을 원하지 않는 경우 사용
			typedef typename allocator_type::pointer pointer; // vector에 저장된 요소에 대한 포인터를 제공하는 형식
			typedef typename allocator_type::const_pointer const_pointer; // 위와 동일, 하지만 요소의 변경을 원하지 않는 경우 사용

			typedef ft::random_access_iterator<T> iterator; // vector에 있는 모든 요소를 읽거나 수정할 수 있는 반복자를 제공하는 형식
			typedef ft::random_access_iterator<const T> const_iterator; // 위와 동일, 하지만 요소의 변경을 원하지 않는 경우 사용
			typedef ft::reverse_iterator<iterator> reverse_iterator; // vector에 있는 모든 요소를 읽거나 수정할 수 있는 역반복자를 제공하는 형식
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator; // 위와 동일, 하지만 요소의 변경을 원하지 않는 경우 사용

			typedef ptrdiff_t difference_type; // vector 개체 내에서 두 요소 주소의 차이를 제공하는 형식
			typedef size_t size_type; // vector의 요소 수를 계산하는 형식

		private:
			pointer _head;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;

		public:
		  // default constructor (1)
			// 요소 없는 빈 vector 생성
			explicit vector(const allocator_type& alloc = allocator_type())
				: _size(0), _capacity(1), _alloc(alloc)
			{
				_head = _alloc.allocate(1);
			}

			// constructor overloading (2)
			// vector의 초기 크기(n)지정, T 타입의 초기 값을 지정
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

			// constructor overloading (3)
			// iterator가 지정한 구간(first~last)의 요소를 복사하여 vector 생성
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

			// constructor overloading (4)
			// 복사생성자, vector x의 요소를 그대로 복사
			vector(const vector& x)
			: _size(x._size), _capacity(x._size), _alloc(x._alloc)
			{
				_head = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(&_head[i], x._head[i]);
			}

			// destructor
			~vector()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_head[i]);
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
			}

			// asign operator
			vector& operator=(const vector& x)
			{
				_size = x._size;
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
				_head = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_head[i], x._head[i]);
				_capacity < _size ? _capacity = _size : 0;

				return (*this);
			}

			// iterators
			iterator begin() // vector의 첫번째 요소를 가리키는 iterator 반환
			{
				return (iterator(_head));
			}

			const_iterator begin() const
			{
				return (const_iterator(_head));
			}

			iterator end() // vector의 마지막 요소를 가리키는 iterator 반환
			{
				return (iterator(_head + _size));
			}

			const_iterator end() const
			{
				return (const_iterator(_head + _size));
			}

			reverse_iterator rbegin() // vector의 첫번째 요소를 가리키는 reverse_iterator 반환
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend() // vector의 마지막 요소를 가리키는 reverse_iterator 반환
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			// capacity
			size_type size() const // vector에 있는 요소 수를 반환
			{
				return (_size);
			}

			size_type max_size() const // vector의 최대 길이를 반환
			{
				return (_alloc.max_size());
			}

			void resize(size_type n, value_type val = value_type()) // vector의 새 크기를 지정
			{
				if (n > _capacity)
					reallocate((n > _size * 2) ? n : _size * 2);
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			}

			size_type capacity() const // vector가 현재 상태에서 포함할 수 있는 최대 요소 수를 반환
			{
				return (_capacity);
			}

			bool empty() const // vector가 비어있는 상태인지 확인
			{
				return (_size == 0);
			}

			void reserve(size_type n) // vector의 저장 공간을 확정, 필요하면 재할당
			{
				if (n > this->max_size())
					throw std::length_error("vector reserve error");
				if (n > _capacity)
					reallocate(n);
			}

			// element access operator
			reference operator[](size_type n) // vector의 지정된 위치의 요소에 대한 참조를 반환
			{
				return (_head[n]);
			}

			const_reference operator[](size_type n) const
			{
				return (_head[n]);
			}

			reference at(size_type n) // vector의 지정된 위치의 요소에 대한 참조를 반환
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

			reference front() // vector의 첫번째 요소에 대한 참조를 반환
			{
				return(_head[0]);
			}

			const_reference front() const
			{
				return(_head[0]);
			}

			reference back() // vector의 마지막 요소에 대한 참조를 반환
			{
				return(_head[_size - 1]);
			}

			const_reference back() const
			{
				return(_head[_size - 1]);
			}

			// modifiers
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) // vector의 요소를 모두 삭제하고 first부터 last까지의 요소를 빈 벡터에 복사
			{
				difference_type n = 0;

				InputIterator tmp(first);
				while (tmp != last)
				{
					++tmp;
					++n;
				}
				this->clear();
				this->reserve(n);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void assign(size_type n, const value_type& val) // vector의 요소를 모두 삭제하고 val을 n개만큼 빈 벡터에 복사
			{
				this->clear();
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

			void push_back(const value_type& val) // vector의 끝에 요소를 추가
			{
				if (_size == _capacity)
					reallocate(extend(_size + 1));
				_alloc.construct(&_head[_size++], val);
			}

			void pop_back() // vector의 끝에 있는 요소를 삭제
			{
				_alloc.destroy(&_head[--_size]);
			}

			iterator insert(iterator position, const value_type& val) // vector의 position에 val을 삽입
			{
				difference_type shift = (position - this->begin());
				if (_size + 1 > _capacity)
					reallocate(extend(_size + 1));
				this->insert(iterator(this->begin() + shift), 1, val);
				return (iterator(this->begin() + shift));
			}

			void insert(iterator position, size_type n, const value_type& val) // vector의 position에 val을 n개만큼 삽입
			{
				if (n == 0)
					return;
				difference_type shift = position - this->begin();
				difference_type tmp = this->end() - this->begin();
				this->resize(this->_size + n);
				iterator end = this->end();
				position = this->begin() + shift;
				iterator tmp_end = this->begin() + tmp;
				while (tmp_end != position)
				{
					--end;
					--tmp_end;
					*end = *tmp_end;
				}
				while (n--)
					*position++ = val;
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) // vector의 position에 first부터 last까지 삽입
			{
				difference_type shift = (position - this->begin());
				size_type n = 0;

				InputIterator tmp(first);
				while (tmp != last)
				{
					++tmp;
					++n;
				}
				if (_size == 0)
					reallocate(_size + n);
				if ((_size + n) > _capacity)
					reallocate((_size + n > _size * 2) ? _size + n : _size * 2);
				_size += n;
				iterator it(&_head[_size - n]);
				iterator insert_pos(&_head[shift]);
				iterator it_end = this->end();
				while (it >= insert_pos)
					*--it_end = *--it;
				while (first != last)
					_alloc.construct(&(*insert_pos++), *first++);
			}

			iterator erase(iterator position) // vector에서 position의 요소를 삭제
			{
				return (this->erase(position, position + 1));
			}

			iterator erase(iterator first, iterator last) // vector에서 first부터 last까지 요소를 삭제
			{
				if (this->empty())
					return (last);

				size_type n = last - first;
				iterator ret(first);
				while (last != this->end())
					*(first++) = *(last++);
				while (n--)
					_alloc.destroy(&_head[--_size]);
				return (ret);
			}

			void swap(vector& x) // 동일한 유형의 다른 vector의 요소를 이 vector의 요소로 교체
			{
				swap(_size, x._size);
				swap(_capacity, x._capacity);
				swap(_alloc, x._alloc);
				swap(_head, x._head);
			}

			void clear() // vector의 모든 요소를 삭제
			{
				for (size_t i = 0; i < _size; ++i)
					_alloc.destroy(&_head[i]);
				_size = 0;
			}

			allocator_type get_allocator() const // vector 생성에 필요한 할당자의 복사본을 반환
			{
				return (_alloc);
			}

		private:
			// new_size 와 기존 capacity 비교 후 용량 늘릴지 여부 결정
			size_type extend(size_type new_size)
			{
				size_type	new_capacity = (_capacity > 0 ? _capacity : 1);

				while (new_capacity < new_size)
					new_capacity *= 2;
				return (new_capacity);
			}

			// 배열에 capacity 만큼 할당하고 값 복사
			void reallocate(size_type new_capacity)
			{
				pointer new_vector = _alloc.allocate(new_capacity);

				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(&_head[i]);
					_alloc.construct(&new_vector[i], _head[i]);
				}
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
				_head = new_vector;
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

		// non-member function overloads
		// relational operators start
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
		// relational operators end

		template <class T, class Alloc>
		void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
}

#endif
