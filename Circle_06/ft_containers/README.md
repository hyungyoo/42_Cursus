# ft_containers

## OPP (Object-Oriented Programming)
> 객체 지향 프로그래밍
c++로 할수있는 프로그래밍 스타일은 절차적 프로그래밍, 객체 지향 프로그래밍 그리고 Generic Programming이 있다.
Generic Programming은
1. 템플릿을 이용하면 총칭화된 타입을 사용하는 클래스와 함수를 만들수있다.
2. 템플릿을 사용하면 타입에 제약읇 받지 않는 로직을 기술할수있다.
Generic Programming을 하기위해서는 템플릿이 꼭 필요하다. 그런데 STL은 무엇으로 만들어졌는가?
바로 템플릿이다. 
#### STL은 Generic Programming으로 만들어진 가장 대표적인 예다.
즉, contariners 프로젝트에서 구현하는 STL은 generic programming으로 구현한다.


## Generic Programming
> generic programming의 장점은, 유지보수가 쉽다는 것이다.
두개의 파라미터를 받고, 비교하여 큰값을 반환하는 max라는 함수가 있다고 가정하자.
이때, 파라미터의 값은 int, float, double 등등이 있다. 이 모든 함수들은 오버로딩을 이용하여
구현이 가능하지만, 템플릿을 이용하면, 유지보수가 쉬우며, 오버로딩을 이용하여 여러개의 함수를 만들어 중복정의를 하지않아도된다.

```cpp

template <typename T>
T	max(T a, T b)
{
	retutn (a > b ? a: b);
}

// 개선점
// 1. const 의 사용 : 인자의 변경을 막는다.
// 2. 참조의 사용 :  구조체나 클래스로 만들어진 크기가 큰 변수를 사용할때는,
// 참조로 전달하는것이 훨씬 빠르다.

template <typename T>
const T	&max(const T &a, const T &b)
{
	retutn (a > b ? a: b);
}


```
## 전문화 함수
>
```cpp

template <> const double &max(const double &a, const double &b)
{
	return (a > b ? a : b);
}

```

호출순서
1. 전문화 함수와 맞는지 검사한다.
2. 템플릿 함수와 맞는지 검사한다.
3. 일반 함수와 맞는지 검사한다.

## 클래스 템플릿
> 클래스 템플릿을 사용하는방법

```cpp

template <typename T>
class	A
{
};

int	main(void)
{
	A<int> a;
	A<double> b;
	...
	return (0);
}

```

## non-type 파라미터의 사용

```cpp

template <typename T, int Size>
class	A
{
	private:
		_a;
	
	public:
		a(void)
		{
			_a = 20;
		}

		a_a(void)
		{
			_a += Size;
		}

};

// non-type 파라미터값을 디폴트로 저장
template <typename T, int Size=100>
class	A
{
	private:
		_a;
	
	public:
		a(void)
		{
			_a = 20;
		}

		a_a(void)
		{
			_a += Size;
		}

};

int	main(void)
{
	A<double, 100> a; // or A<double> a;
	a.a_a();
	// a == 20 + Size == 120;
	return (0);
}
```

# List


## list의 자료구조
> list는 자료구조중 "연결리스트"를 템플릿으로 구현한것이다.
1. 고정길이인 배열에 비해 길이가 가변적이다.
2. 중간에 데이터삽입, 삭제가 용이하다.

