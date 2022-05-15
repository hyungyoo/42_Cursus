#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "stddef.h"
# include <memory>

namespace ft
{

	// ft namespace안에서 새롭게 생성.
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	//https://www.cplusplus.com/reference/iterator/iterator_traits/
	// standard iterator traits
	// reverse_iterator를 위한 iterator_traits
	template<class Iter> 
	struct iterator_traits {
		public:
			typedef typename Iter::iterator_category	iterator_category;
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;
	};

	// iterator traits for pointer
	/*
	int main() 
	{
		typedef std::iterator_traits<int*> traits;
		if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
			 std::cout << "int* is a random-access iterator";
		return 0;
	}
	*/
	// container를 위한 iterator_traits
	template<class T>
	struct iterator_traits<T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef ptrdiff_t distance_type;
		typedef T *pointer;
		typedef T &reference;
	};

	// iterator traits for const pointer
	template<class T>
	struct iterator_traits<const T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef ptrdiff_t distance_type;
		typedef T *pointer;
		typedef T &reference;
	};


	// https://www.cplusplus.com/reference/iterator/iterator/?kw=iterator
	// iterator
	template <class Category, class T, class Distance = ptrdiff_t,
		           class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	/*
	template<typename Iter>
	inline typename iterator_traits<Iter>::iterator_category
	iterator_category(const Iter&)
	{
		return typename iterator_traits<Iter>::iterator_categoty();
	}
	*/

}



#endif
