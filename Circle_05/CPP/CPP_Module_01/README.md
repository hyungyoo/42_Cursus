## Mudule01

## 과제
> 
### ex00
## new와 delete를 이용한 동적할당과 메모리해제!
> malloc / free 와는 다르다.
new와 delete는 메모리를 할당하고 해제하지만, 생성자와 소멸자를 호출한다.

### ex01
## new[] 와 delete[] 의 사용
> new / delete, new[] / delete[] 를 맞춰서 써야한다.
-  new와 delete의 수행방식
> 
(test *)malloc(4);
test *t1 = new test;
--> new가 test의 객체의 크기를 추론하여, malloc에 넘겨준다.  malloc은 os에 해당크기만큼의 메모리 할당을 요청한다.
os가 유효한 주소를 넘겨주고, heap manager는 어느주소에 얼마의 크기를 할당해주었는지 기록한다.
주소를 받은 malloc()은 객체 포인터에게 주소값을 반환한다.
new가 할당받은 곳에 객체의 생성자를 호출

free(t1);
delete t1;
--> delete가 객체소멸자를 호출하고, free에게 포인터를 넘겨줌.
free는 heap manager에게 t1의 주소로 메모리 해제요청을 준다.

- new[] 와 delete[]의 수행방식
> (test * )malloc(20 + 4);	// 24 bytes = 20 for 5 * 4 + 4(객체의 개수)
test * t1 = new test[5];

free(t1 - 4);
delete[]
delete[]가 t1 -4 의 주소를 넘겨준다

### ex02
#### 참조자와 포인터의 구분

### ex03
#### 참조자와 포인터의 사용
> 참조자는 초기화를 꼭해야한다. * 또는 &를 사용할필요가없으며, alias의 역활을 하기때문에, 메모리 자원을 쓰지않는다.
그러나, 꼭 초기화를해야하므로, null로 초기화될 경우에는 포인터를 사용해준다.
HumanA는 참조자, HumanB는 포인터

### ex04
#### 파일 입출력 스트림
> 파일입출력은 ifstream, ofstream 두가지를 이용한다.
1. 파일 입력 (ifstream)
	인자로 받은 파일이름과 "./"를 합쳐, 경로를 만든다.
	std의 함수이므로, std::ifstream ifs로 객체를 생성한후, ifs.open(파일경로)로 파일 오픈. 에러는 ils.fail()로 확인
2. 파일 출력 (ofstream)
	in file과 마찬가지로, std::ofstream ofs = outfile; 로 선언한다.

#### 구현과정

3. s1 과 s2의 replace
	find함수와 std::string::npos를 이용한다.
	getline으로 파일입력 스트림에서 한 줄씩 받아온다. (std::getline(ifs, str);
	받아온 str을 find함수를 이용하여, s1을 찾는다. 만약에 있다면, 즉, pos값이 (find리턴값) npos와 같지않다면, 성공
	이때, 찾았다면(str에 s1이 존재), erase함수와 insert함수를 이용하여, 교체
	그 다음 pos값은 pos = str.find(str, pos); 와 같은 형태로 찾는다. pos는 find의 리턴값이자, s1의 인덱스값이므로,
	두번째부터는 찾은 다음 pos를 찾아야하기때문에, 인자로 넣어준다.
	마지막은 ofs << str !!


### ex05
#### 멤버함수 포인
> c언어와 c++의 함수포인터는 다르다.
1. c언어의 함수포인터
```c

void	f()(...);

int	main(void)
{
	void (*p)();	//함수포인터 선언
	p = f;
	p = &f;

	p();
	(*p)();

	/* 4가지 방법이 다 맞다. ㅂㅅ같음 */

	return (0);
}

```

2. cpp의 함수포인터

```cpp

void	foo()(...);

class A
{
	private:
		void	(A::*fpr)
};

```


## 함수 사용 및 이론

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
