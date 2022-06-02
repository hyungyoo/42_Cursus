#ifndef FT_CONTAINERS_STACK_HPP
# define FT_CONTAINERS_STACK_HPP

# include <iostream>
# include <sstream>
# include "vector.hpp"

/* stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, */
/* providing a specific set of member functions to access its elements. */
/* Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack. */
namespace ft {

	//T: Type of the elements
	//Container: Type of the internal underlying container object where the elements are stored.
	template <class T, class Container = vector<T> > 
	class stack {
		public:
			typedef T										value_type;
			typedef Container								container_type;
			typedef typename container_type::size_type		size_type;

		protected:
			container_type	_ctnr;

		public:
			//getter
			container_type	get_container(void) const {
				return (_ctnr);
			}

			//Constructor
			//ctnr: Container object
			explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

			stack(const stack& x) : _ctnr(x._ctnr) {}
            
			stack& operator=(const stack& x) {
				_ctnr = x._ctnr;
				return (*this);
			}

			~stack() {}

			/* Returns whether the stack is empty: i.e. whether its size is zero. */
			/* return: true if the underlying container's size is 0, false otherwise. */
			bool empty() const {
				return (_ctnr.empty());
			}

			/* Returns the number of elements in the stack.*/
			size_type size() const {
				return (_ctnr.size());
			}

			/* Returns a reference to the top element in the stack. */
			value_type& top() {
				return (_ctnr.back());
			}

			const value_type& top() const {
				return (_ctnr.back());
			}

			/* Inserts a new element at the top of the stack, above its current top element. */
			/* val: Value to which the inserted element is initialized.*/
			void push (const value_type& val) {
				_ctnr.push_back(val);
			}

			/* Removes the element on top of the stack, effectively reducing its size by one.*/
			void pop() {
				_ctnr.pop_back();
			}
	};
	//nonmember relational operator
	/* Performs the appropriate comparison operation between lhs and rhs. */
	/* Each of these operator overloads calls the same operator on the underlying container objects. */
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.get_container() == rhs.get_container());
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.get_container() != rhs.get_container());
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.get_container() < rhs.get_container());
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.get_container() <= rhs.get_container());
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.get_container() > rhs.get_container());
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.get_container() >= rhs.get_container());
	}
}

#endif