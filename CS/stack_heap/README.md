# 메모리 구조

## 구조체와 패팅
```cpp

struct e
{
	int	a;
	double b;
	char c;
};


```
위 구조체의 사이즈는? 4 + 8 + 1 ? 아니다. 24바이트이다. 왜? 구조체는 구조체에서 가장크기가 큰 인자의 배수로 끝난다. 그렇기때문에 가장큰 사이즈는 8이며, int 와 char도 각각 8의 배수로서 끝나게되며, 나머지 자리는 패딩으로 채워진다.

```cpp

struct e
{
	double b;
	char c;
	int	a;
};


```
따라서, 다음과같은 구조체는 16비트가 되어진다. 그러나 cpu의 os비트에따라(캐시 라인) 구조체의 크기를 결정하는 부분도 있다. 만약에 캐시라인의 배수가아니거나, 중간에 구조체가 나눠지게된다면, "alignas"를 이용하여 구조체의 크기를 정해줄수도있다.

예) struct alignas(32) Test {};


## call stack, stack frame
> 스택에 변수나 함수가 쌓이는 형태는, 각각의 변수가 선언될때마다, 스택에 쌓이는것이아니라, main과 그안에있는 여러함수들이 각각의 "스택 프레임"으로써 스택에 쌓이게 된다.

대략적인 stack frame의 형태는 다음과같다.

---------------------------------------
return address, next instructor address (function call이 끝난다음 실행시킬 명령어의 주소)
---------------------------------------
변수 1
---------------------------------------
변수 2
---------------------------------------
파라미터
---------------------------------------

## class stack, stack frame with CLASS

```cpp

class Dog
{
	public:
		Dog(); {_age = 1}
		~Dog();
		void addAge() {_age++;}
	
	private:
		_age;
};

int	main(void)
{
	Dog dog;
	dog.addAge(1);
}
```
1. main의 stack frame이 stack에 올라간다. (dog의 age는 아직 설정되지않음)
2. Dog의 생성자가 불린다. (main에 있는 dog객체의 age는 1이 된다)	// (후에 사라짐)
3. addAge()가 불린다. 이 스택프레임에는 return, intructor addess, 1, this(member varialbe control) // (main에 \
		있는 age에 1이 더해진다. 그리고 사라짐)
4. 소멸자후에, main끝남

"즉, 멤버 함수에는 this가 stack frame에 함께 쌓인다"

## heap
왜 heap을 사용하나?

### 1. life cycle
> 스택프레임에 선언된 데이터가, 스택프레임의 역활이 끝남과동시에 사라질수도있기때문
### 2. large size
> 큰 사이즈가 stack(한정된 메모리공간)에 쌓이지않는다.
### 3. dynamic (run time)
> stack의 메모리는 컴파일시간에 결정된다. 예를들면, 우리가 한개의 클래스로 몇개의 객체를만들지 알지못한다. 이런 경우를 위해, heap메모리를 사용한다.
	
