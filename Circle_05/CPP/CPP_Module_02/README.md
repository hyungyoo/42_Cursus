# CPP_Module_02
> Polymorphisme ad-hoc, overloads et classes canoniques
오버로드는 기본기능외에, 또 다른 기능을 할수있도록 중복정의를 하는!

## Polymarphisme ad-hoc
cppㄴ는 엄격한 자료형을 가지고있지만, 오버로드를 사용할수있다.
하나의 함수에 여러개의 형태를 부여한다는 뜻으로 다형성이라고 한다. 다형성의 장점은
어떤함수를 부를것인지 컴파일러가 결정한다는것이다.

```cpp

add(1, 20)		// int int 			호출
add(9.9, 42.42)	// double double 	호출 

```
## Overloads
> 함수를 오버로드 한다는 말은, 함수의 이름 하나에 여러개의 함수를 적재하겠다는말이다.

``` cpp

int 	add(int a, int b);
int 	add(int a, int b, int c);
double 	add(double a, double b);
double 	add(int a, double b);
double 	add(double a, int b);

```
이와같이, CPP에서는 함수의 이름이 같고 매개변수가 다르거나, 매개변수의 숫자가 다르면,
	오버로드라고 한다.

반환값만 다르고, 매개변수가 같다면, 오버로드라고할수없다.

> 즉, 함수의 오버로드를 사용하면, 하나의 함수이름으로 매개변수가 다른 여러개의 함수를 만들수있다.
다양한 형태를 만든다고해서, cpp은 다형성의 특성을 갖는다.

## Operator overload
> 연산자 오버로드에 대한 규칙
1. ** 와 같은 새로운 연산자를 정의할수는 없다.
2. 기본 제공 데이터 형식에 적용할때, 연산자의 의미를 다시 정의할수없다.
3. 오버로드 된 연산자는 비정적(non-static)클래스 멤버 함수거나 전역함수이어야한다.
4. 연산자 오버로딩은 함수이다. 예) +를 대체해서 할수있는 함수를 사용한다.

> 연산자 오버로딩의 잇점
1. 연산자 고유의 의미를 유지할수있다.
2. 간략한 표기가 가능하다. A.Add() 와 같이 함수를 쓰지 않고 +를 사용, 즉 가독성이 좋아진다.

> 형식 --> 리턴형 operator 연산자(매개변수들...)
예)	int operator+(A& refClassA);
즉, test1.operator+(test2); --> test1 + test2

> 오버로딩은 이항연산자를 사칙연산으로 오버로딩하거나, 단항연산자인 증가연산자++를 전치형 또는 후치형으로 오버로딩한다.
전치형 -- operator++(){}
후치형 -- operator++(int random){}
		
