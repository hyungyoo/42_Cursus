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

}

#endif
