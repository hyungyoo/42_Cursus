#ifndef FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_HPP
# define FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_HPP

# include <iostream>
# include "iterator_traits.hpp"
# include "../node.hpp"

namespace ft {

	template<typename T, typename node_pointer>
    class const_bidirectional_iterator;

	template <typename T, typename node_pointer>
    class bidirectional_iterator
    {
        public:
            typedef T                                   value_type;
            typedef T*                                  pointer;
            typedef T&                                  reference;
            typedef std::ptrdiff_t                      difference_type;
            typedef std::bidirectional_iterator_tag     iterator_category;

        private:
            node_pointer  _ptr; 

		public:
			// X is bidirectional iterator type, a and b are objects of this iterator type
			// t is an object of the type pointed by the iterator type.
			
			/* X a; X b(a); b = a; */
			bidirectional_iterator() : _ptr(NULL) {}
            bidirectional_iterator(node_pointer ptr) : _ptr(ptr) {}
            bidirectional_iterator(bidirectional_iterator const &x) : _ptr(x._ptr) {}
            bidirectional_iterator& operator=(const bidirectional_iterator&x) {
                _ptr = x._ptr;
                return (*this);
            }
            virtual ~bidirectional_iterator() {}

			operator bidirectional_iterator<const T, node_pointer>() const {
				return bidirectional_iterator<const T, node_pointer>(this->_ptr);
			}
			
			//getter
			node_pointer get_ptr(void) {
				return (_ptr);
			}

			node_pointer get_ptr(void) const {
				return (_ptr);
			}
			
			/* a == b */
			template<typename Iter>
			bool operator==(const bidirectional_iterator<Iter, node_pointer> &b) const {
				return (_ptr == b.get_ptr());
			}

			/* a != b */
            template<typename Iter>
			bool operator!=(const bidirectional_iterator<Iter, node_pointer> &b) const { 
				return (_ptr != b.get_ptr());
			}
			
			/* *a; a->m; *a = t */
			reference operator*() const {
				return (_ptr->value);
			}

			reference operator* () {
                return (_ptr->value);
            }

			pointer	operator->() const {
				return (&_ptr->value);
			}

			pointer operator->() {
                return &_ptr->value;
            }
			
			/* ++a; a++; *a++ */
			bidirectional_iterator &operator++() {
                if (_ptr->right)
				{
                    _ptr = _ptr->right;
                    while (_ptr->left)
                        _ptr = _ptr->left;
                    return (*this);
				}
				else
                {
                    node_pointer tmp = _ptr;
                    _ptr = _ptr->parent;
                    while (_ptr->left != tmp)
                    {
                        tmp = _ptr;
                        _ptr = _ptr->parent;
                    }
                }
                return (*this);
            }

            bidirectional_iterator operator++(int) {
                 bidirectional_iterator tmp;

                tmp = *this;
                ++(*this);
                return (tmp);
            }
			
			/* --a; a--; *a-- */
			bidirectional_iterator& operator--() {
                if (_ptr->left)
                {
                    _ptr = _ptr->left;
                    while (_ptr->right)
                        _ptr = _ptr->right;
                    return (*this);
                }
                else
                {
                    node_pointer tmp = _ptr;
                    _ptr = _ptr->parent;
                    while (_ptr->right != tmp)
                    {
                        tmp = _ptr;
                        _ptr = _ptr->parent;
                    }
                }
                return (*this);    
            }

            bidirectional_iterator operator--(int) {
                bidirectional_iterator tmp;

                tmp = *this;
                --(*this);
                return (tmp);
            }
 	};

	template <typename T, typename node_pointer>
    class const_bidirectional_iterator
    {
        public:
            typedef T                                    value_type;
            typedef const T*                            pointer;
            typedef const T&                            reference;
            typedef std::ptrdiff_t                      difference_type;
            typedef std::bidirectional_iterator_tag     iterator_category;

        private:
            node_pointer  _ptr; 

        public:
            const_bidirectional_iterator() : _ptr(NULL) {}
            const_bidirectional_iterator(node_pointer ptr) : _ptr(ptr) {}
            const_bidirectional_iterator(const_bidirectional_iterator const &x) : _ptr(x._ptr) {}
            const_bidirectional_iterator& operator=(const const_bidirectional_iterator&rhs) {
                _ptr = rhs._ptr;
                return (*this);
            }
            virtual ~const_bidirectional_iterator() {}

            operator const_bidirectional_iterator<const T, node_pointer>() const {
                return const_bidirectional_iterator<const T, node_pointer>(this->_ptr);
            }

            const_bidirectional_iterator get_node() const { return this->_ptr; }
			
			//getter
			node_pointer get_ptr(void) {
				return (_ptr);
			}

			node_pointer get_ptr(void) const {
				return (_ptr);
			}

			/* a == b */
			template<typename Iter>
			bool operator==(const const_bidirectional_iterator<Iter, node_pointer> &b) const {
				return (_ptr == b.get_ptr());
			}

			/* a != b */
            template<typename Iter>
			bool operator!=(const const_bidirectional_iterator<Iter, node_pointer> &b) const { 
				return (_ptr != b.get_ptr());
			}

			/* ++a; a++; *a++ */
            const_bidirectional_iterator operator++(int) {
                 const_bidirectional_iterator tmp;

                tmp = *this;
                ++(*this);
                return tmp;
            }

            const_bidirectional_iterator &operator++() {
                if (_ptr->right)
				{
                    _ptr = _ptr->right;
                    while (_ptr->left)
                        _ptr = _ptr->left;
                    return (*this);
				}
				else
                {
                    node_pointer tmp = _ptr;
                    _ptr = _ptr->parent;
                    while (_ptr->left != tmp)
                    {
                        tmp = _ptr;
                        _ptr = _ptr->parent;
                    }
                }
                return (*this);
            }

			/* --a; a--; *a-- */
            const_bidirectional_iterator operator--(int) {
                const_bidirectional_iterator tmp;

                tmp = *this;
                --(*this);
                return tmp;
            }

            const_bidirectional_iterator& operator--() {
                if (_ptr->left)
                {
                    _ptr = _ptr->left;
                    while (_ptr->right)
                        _ptr = _ptr->right;
                    return (*this);
                }
                else
                {
                    node_pointer tmp = _ptr;
                    _ptr = _ptr->parent;
                    while (_ptr->right != tmp)
                    {
                        tmp = _ptr;
                        _ptr = _ptr->parent;
                    }
                }
                return (*this);    
            }

			/* *a; a->m; *a = t */
            reference operator* () {
                return (_ptr->value);
            }

            reference operator* () const {
                return (_ptr->value);
            }

            pointer operator->() {
                return (&_ptr->value);
            }

            pointer operator->() const {
                return (&_ptr->value);
            }
    };
}

#endif