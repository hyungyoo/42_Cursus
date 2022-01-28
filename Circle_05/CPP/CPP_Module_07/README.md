# Template 

## Generic
> 자료형의 일반화 : 함수나 클래스를 일반화시키고, 매개 변수타입을 지정하여, 틀에서 찍어내듯이 함수나 클래스 코드를 생산하는 기법

## Template
> 제네릭 타입을 이용해 함수나 클래스를 일반화하는 "도구", 컴파일 단계에서 확인가
#### 템플릿 함수
> 다른속성의 매개변수에 대해 같은 방식의 행위를 갖는 함수를 정의하기위해 함수를 일반화
#### 템플릿 클래스
> 다른 속성을 유지하나, 같은 방식의 행위를 갖는 클래스를 정의하기위해 클래스를 일반화

## 템플릿의 특수화
> int, double같은 모든 합산이가능한 타입에대해서는 템플릿함수가 유용하다. 하지만 char * 값은?

```cpp

template<typename T>
T add(T const &a, T const &b)
{
	return (a + b);
}

// 그러나 두개의 변수가 char *이라면?
template<>		// 특수화에서는 typename을 쓰지않는다.
char *add(char * const &a, char * const &b)
{
	int	strlenL = strlen(a);
	int	strlenR = strlen(b);
	char *strRet = new char[strlenL + strlenR + 1];

	strcpy_s(strRet, strlenL + 1, a);
	strcpy_s(strRet, strlenR + 1, b);
	return (strRet);
}

```

```cpp

#include <iostream>

float	arraySum(const float arr[], int size)
{
	float	sum(0);
	int	i(0);
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

int	arraySum(const int arr[], int size)
{
	int	sum(0);
	int	i(0);
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

// 이렇게 각 타입마다 새롭게 함수를 오버로딩하는것보다는, 템플릿을 쓸수있다.
template <typename T>
T	arraySum(const T arr[], int size)
{
	T sum(0);
	int	i(0);
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};
	int	sum = arraySum(arr, 5);
	
	float	farr[5] = {1.2, 2.3 3.4, 4.5, 5.6};
	float	fsum = arraySum(farr, 5);
	
	//	int	sum = arrSum<int>(arr, 5);
	//	float	sum = arrSum<float>(farr, 5);
	return (0);
}


```

```cpp

#include <algorithm>
#include <iostream>

int	main(void)
{
	int	MaxI = std::max<int>(1, 5);
	float	MaxF = std::max<float>(1, 5);
	double	MaxD = std::max<double>(1, 5);
	return (0);
}
```
## ex00
> 함수템플릿을 만들어, 템플릿함수를 만든다.
어려운건 하나도없고, 그냥 기본적인 구현이다. 
딱 한가지, 과제에도 명시되어있듯, 함수템플릿의 선언과 구현(정의)부분은 .hpp함수에 해야한다. 이전 과제에서는 선언은 .hpp에, 멤버함수의 정의부분은 .cpp에 하였지만, 템플릿함수의 구현은 이렇게 나눠서 한다면, 컴파일이 되지않는다.

## ex01
> 이것또한 간단하다. 그저함수와 배열, 배열의 사이즈를 iter라는 함수의 인자로 넣은 템플릿함수를 구현한다.

## ex02
> 클래스 템플릿을 만든다. canonical형식으로 class를 구현한다. 
멤버 변수인 "_ arr"는 new로 할당받은 배열이므로, 복사를 할경우, 깊은복사를 해야한다.
또한 operator[]에 관하여, const 와 non-const를 구별하여 선언 및 정의한다.
