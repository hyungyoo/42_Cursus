# CPP Module 00

### Name space
> cpp 에서는, printf 대신에 iostram에서 제공하는 cout를 쓴다. 그런데 cout함수를 쓰기위해서는
전처리기 밑에 using namesapce str;가 필요하다. 또는 std::cout로 사용을 해야한다.
모든 실무에서는 팀으로 진행되는 프로젝트를 하게되며, 나중에는 코드에대해 필요한 코드와 필요하지않은코드를 분리한다.
여러 사람이 작성한 코드중에서 클래스이름이나 훔수의 이름이 같은 경우가 있을것이다. 간단한 add함수를 예를 들자면,
여러 사람들이 add함수를 만들었다고 가정할때, 컴파일당시 문제가 발생하게된다. 그렇기때문에 사용하는것이 name space이다.

사용법

```cpp

namespace A
{
	inline int ADD(int a, int b)
	{
		return (a + b);
	}
}

int	main(void)
{
	ADD(1, 2);
	B::ADD(1, 2);
	return (0);
}

```

### 멤버 private 선언
> 1. 문법의 일관성 : 함수로만 멤버에 접근시, "멤버", '멤버'.. 등등 문법적고민이 필요없다.
2. 접근제어 : 접근 권한을 컨트롤할수있다.
3. 캡슐화 : 내부 데이터접근시 카운팅, 알람 팝업, 접근시 메세지전달... 등등
> 이렇게 선언된 private 변수는 accessors 함수를 이용하여 접근가능
``` cpp
class Sample {

	public:
		Sample(void);
		~Samplie (void);

		int		getfoo(void) const;
		void	setfoo(void);

	private:

		int	foo;
}
```

### 왜 struct가 아닌, classe (c++ 에서는 struct에 함수를 선언할수있다)
> private가 없다. struct에서는 모든 멤버가 public으로 선언된다. (접근 지시 제어자 없음)

### Comparaisons C++
> 다른 인스턴스를 가져와서 비교할수있다.
``` cpp

int	 Sample::compare(Sample *other) const
{
	if (this->foo > other->getFoo())
		return (-1);
	else if (this->foo < other->getFoo())
		return (0);
	else
		return (1);
}

// in main

int	main(void)
{
	Sample instance_1(42);
	Sample instance_2(-42);

	if (!instace_1.compare(&instace_2))
		std::cout << "instance_1 and instance_2 are structually equa" << std::endl;
	return (0);
}
```

### static
> 얼마나 많은 인스턴스를 만들어냈는지 기록가능

``` cpp

class Sample
{
	public:
		Sample(void);
		~Sample(void);

		static int		getNbInstance(void);

	private:
		static int		_nbInstance;
};

// class.cpp

Sample::Sample(void)					//생성자
{
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInstance += 1;
}

Sample::~Sample(void)					//소멸자
{
	std::cout << "Destructor called" << std::endl;
	Sample::_nbInstance -= 1;
}

int		Sample::getNbInstance(void)
{
	return (Sample::_nbInstance);
}

int		Sample::_nbInstance = 0;		//static 초기화

```

### Pointer to members

``` cpp::sample.hpp

#ifndef	SAMPLE_CLASS_H
# define SMAPLE_CLASS_H

class	Sample
{
	public:
		int	foo;

		Sample(void);
		~Sample(void);
		
		void	bar(void) const;
};

#endif


#include <iostream>
#include "sample.hpp"

int	main(void)
{
	Sample		instance;
	Smaple		*instance_p = &instance;

	int	Sample::*p	= NULL;
	p = &Sample::foo;

	std::cout << "Value of member foo: " << instance.foo << std::endl;		//value of member foo: 0
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl;		//value of member foo: 21
	instance_p->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;		//value of member foo: 42

	void	(Sample::*f)(void) const;
	f = &Sample::bar;

	(instance.*f)();														// member function bar called
	(instance_p->f)();														// member function bar called

	return (0);
}

```
