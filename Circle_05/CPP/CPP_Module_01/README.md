### Mudule01

### 과제
> 
#### ex00
new와 delete를 이용한 동적할당과 메모리해제!
#### ex01

### 참조형 변수 (Reference variable)
> 지금까지는 c언어에서 일반변수, 그리고 포인터 두가지의 변수타입이 있었다.
CPP에서는 세번째 변수타입이있다.

> C++ 는 세가지의 참조형을 지원함
1. non-const
2. const
3. r-value

#### non-const
> 
```cpp

/* 여기서 &는 주소를 의미하는것이아니라, 참조를 의미한다.*/
int value = 5;		//	일반변수
int &ret = value;	//	참조형 변수

/* ref와 value는 동의어로 취급됨*/
value = 6;			//	value == 6
ret	=	7;			//	value == 7

/* 참조형에 주소연산자(&)를 사용하는 참조되는 값의 주소가 나온다.*/
std::cout << &value;	//	prints 0012FF7C
std::cout << &ref;		//	prints 0012FF7C

/*
* References must be initialized
* 참조형은 선언과 동시에 반드시 초기화해야한다.
*/
int	value = 5;
int& ref = value;

//or

int& invallidRef;	// invalid

// Null값을 저장할수있는 포인터와는 다르게, NULL 참조 같은것은 없다.

int	x = 5;
int& ref1 = x;	// okay, x is an non-const l-value

const int y = 7;
int& ref2 = y;	// not okay, y is a const l-value

int& ret3 = 6;	// not okay, 6 is a r-value

int value1 = 5; 
int value2 = 6; 

int& ref = value1; // okay, ref is now an alias for value1 
ref = value2; // assigns 6 (the value of value2) to value1 -- does NOT change the reference!

```

### References vs pointers

참조형과 포인터는 흥미로운 관계에 있다. 참조형은 접근할 때 암시적으로 역참조되는 포인터와 같은 역할을 한다. (참조형은 내부적으로 포인터를 사용하여 컴파일러서 구현된다.)

```cpp

int value = 5;
int* const ptr = &value;
int& ref = value;
//*ptr과 ref는 동일하게 평가된다. 그러므로 다음 두 명령문은 같은 효과를 낸다.

*ptr = 5;
ref = 5;
//참조형은 선언과 동시에 유효한 객체로 초기화해야 하고, 일단 초기화되면 변경할 수 없으므로 포인터보다 사용하는 것이 훨씬 안전하다. (널 포인터를 역참조하면 위험하다.)

//주어진 문제가 참조형과 포인터 둘 다로 해결할 수 있다면 참조형을 사용하는게 더 좋다.


```


레퍼런스 선언
- 변수는 새로운 메모리 공간에 이름을 부여하지만 레퍼런스는 반드시 이미 이름을 지니고 있는 메모리 공간에 레퍼런스 이름을 부여해야한다.

- 따라서 레퍼런스값에는 상수가 올 수 없고 변수 이름이 와야한다.

- 레퍼런스는 선언과 동시에 반드시 초기화되어야 한다.

```cpp

int a=10;

int &b=10  (x)   //레퍼런스는 상수값으로 초기화 할 수 없다.

int &c=a   (o)

int &d;      (x)   //레퍼런스는 선언과 동시에 초기화 해야한다.

```
