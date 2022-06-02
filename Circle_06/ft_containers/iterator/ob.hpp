#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			referance;

		protected:
			iterator_type	_curr;
		
		public:
			/* default */
			reverse_iterator() : _curr() {}

			/* initialization */
			explicit reverse_iterator (iterator_type it) : _curr(it) {}

			/* copy */
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _curr(rev_it._curr) {}

	};
}

#endif