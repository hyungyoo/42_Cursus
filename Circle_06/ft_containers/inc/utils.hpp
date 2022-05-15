#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
		//********************	enable_if **********************//
	//	B가 true일때, type을 생성.
	//	아닐경우, 컴파일 하지않고, 오버로딩 대상을 찾음.

	// typename T = void
	// client code를 위한 더미 파라미터
	template <bool cond, typename T = void>
	struct enable_if {
	};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	//********************	is_integral**********************//
	// intergral type에 해당하는 자료형이 아닌경우 (특수화한 타입의 인자)
	// false 출력
	// true 일경우, SFINAE에 따라, 오버로딩후 type 생성
	template <typename T>
	struct is_integral {
		static const bool value = false;
	};

	// integral type에 해당하는 자료형 타입을 위한 템플릿 특수화
	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<wchar_t> { static const bool value = true; };
	template <> struct is_integral<signed char> { static const bool value = true; };
	template <> struct is_integral<short int> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long int> { static const bool value = true; };
	template <> struct is_integral<long long int> { static const bool value = true; };
	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<unsigned short int> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long int> { static const bool value = true; };
	template <> struct is_integral<unsigned long long int> { static const bool value = true; };

	//********************	lexicographical_compare **********************//
	/* first1(포함)부터 last1 바로 앞까지와 first2(포함)부터 last2 까지를 비교. */
	/* first2 ~ last2사이 데이터들이 사전적으로 fisrt1 ~ last1 사이의 데이터들보다 뒤에 있다면 true, 아니라면 false 리턴 */
	/* If both sequences compare equal until one of them ends, the shorter sequence is lexicographically less than the longer one.*/
	/* first1, last1: Input iterators to the initial and final positions of the first sequence. */
	/* first2, last2: Input iterators to the initial and final positions of the second sequence. */
	/* comp: Binary function that accepts two arguments of the types pointed by the iterators, and returns a value convertible to bool. */

	// default: https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class T1, class T2>
	struct pair {
		public:
			typedef	T1		first_type;
			typedef T2		second_type;

			T1				first;
			T2				second;

		public:
			pair() : first(T1()), second(T2()) {}
			
			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
			
			pair (const first_type& a, const second_type& b) : first(a), second(b) {}

			pair& operator= (const pair& pr) {
				first = pr.first;
				second = pr.second;
				return (*this);
			}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs == rhs));
		}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs < rhs));
	}

	// pair ================================ //
	/* Constructs a pair object with its first element set to x and its second element set to y. */
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}

	// equal ================================ //
	/* Compares the elements in the range [first1,last1) with those in the range beginning at first2, */
	/* and returns true if all of the elements in both ranges match. */

	/* first1, last1: Input iterators to the initial and final positions of the first sequence. */
	/* first2: Input iterator to the initial position of the second sequence.  */
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1!=last1)
		{
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1;
			++first2;
		}
  		return true;
	}

	/* pred: Binary function that accepts two elements as argument (one of each of the two sequences, in the same order), */
	/* 			and returns a value convertible to bool.*/
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1!=last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
  		return true;
	}

}



#endif
