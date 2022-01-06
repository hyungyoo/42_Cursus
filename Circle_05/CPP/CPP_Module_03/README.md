# 상속

## 상속 코드 예
```cpp

class CTest
{
	public:
		CTest()
		{
			std::cout << "CTest()" << std::endl;
		}

		void	TestFunc(void)
		{
			std::cout << "CTest::TestFunc()" << std::endl;
		}
};

class CTestEx : public CTest
{
	public:
		CTestEx()
		{
			std::cout << "CTestEx()" << std::endl;
		}

		// 재정의
		void	TestFunc(void)
		{
			std::cout << "CTestEx::TestFunc()" << std::endl;
		}
};

int		main(void)
{
	CTest  a;
	a.TestFunc();

	CTestEx b;
	b.TestFunc(); 
	/* 결과값은
	* b에 기본클래스 생성자도 호출된다.
	* CTest()
	* CTest::TestFunc()
	* CTest()
	* CTestEx()
	* CTestEx::TestFunc()
	*/

	CTestEx a;
	
	CTest &b = a;
	b.TestFunc();

	/* 
	   파생형식 <- 기본형식
	   학생 	<- 사람

	   사람의 파생형식에는 '학생'이 있다.
	   학생은 사람이다.

	return (0);
}

```

## 메서드
> 메서드: 일반 --> [접근형식]
		 virtual -> [실형식]
		 static
메서드가 일반이면 접근형식을 따라간다.
메서드가 virtual이면 실형식을 따른다.

##  생성자의 호출순서와 생성순서
> 상속에서, 생성자의 call 순서와 실행순서는 다르다.
먼저 call된 생성자가 가장 나중에 실행된다.

### 생성자는 객체 자신 '만을' 초기화한다.
상속에서 파생형 생성자(자식 생성자)에서 부모 멤버를 초기화하는건 안된다!!

```cpp

class A
{
	A생성자 //3   //4(실행)
};

class B : public A
{
	B생성자 //2	 //5(실행)
};

int	main(void)
{
	B b;   //1
	return (0);
}

```

## 부모와 자식 포인터 접근
A   =   [ A ][   ]  --> A * 가능, B * 상향접근이라 오류  (B로 접근할수있는 메모리가 비어있음, 세그폴트)
b   =   [ A ][ B ]  --> A * , B * 둘다 접근가능


## 가상함수
> '미래'를 호출한다.
메서드 : 1. 일반
		 2. 가상 : 3. 순수가상함수

### 일반가상함수와 순수가상함수의 차이
> 순수가상함수는 '선언'(컴파일)만 있다. 정의(링크)는 없다(함수의 바디구현부분)
접근 형식 (포인터, 참조자..) , 실형식

"일반 메서드는 참조형식을 따른다. 가상함수는 실형식을 따른다"

예) A * ptr   = new B;
	접근형식 = 실형식

이러한 상황에서;

```cpp

class A
{
	int	TestFuc();
};

class B : public A
{
	int	TestFunc() --> 재정의
};

int	main(void)
{
	A *pdata = new B;

	pdata->TestFunc(); -->이때의 TestFunc는 A의 TestFunc이다.

	return (0);
}	

```


```cpp

class A
{
	virtual int	TestFuc();
};

class B : public A
{
	int	TestFunc() --> 재정의
};

int	main(void)
{
	A *pdata = new B;

	pdata->TestFunc(); -->이때의 TestFunc는 B의 TestFunc이다.

	return (0);
}	

```

## 상속에서의 소멸자

```cpp

class A
{
};

class A : public B
{
};

int main(void)
{
	A *pdata = new B;
	delete pdata;		//호출되는 소멸자는? 접근형식이기에 A가 불린다. 실형식의 B의 소멸자는 호출이 되지않는다. 실형식을 호출하려면 A의 소멸자에 virtual을 붙인다.
						// 소멸자는 실행순서와 호출순서가 같다. 그래서 B 다음에 A가 호출된다.

	return (0);
}

```

## 순서가상 함수
> 선언은 있다. 하지만 정의는 없다. (함수의 바디부분이 없다)
	c언어에서는 링크오류가 발생한다. 
	예를 들면, 동물이라는 부모 클래스에, 자식클래스들은 각각의 동물로서 부모클래스를 상속받는다.
	여기서 순수 가상함수는 울음 이라는 함수이며, 동물이라는 클래스에서 구체적으로 구현할수있는 울음 이라는 메소드는 없기때문에,
	순수 가상함수로서 선언만 하게된다.

```cpp

virtual int GetData(void) const = 0;	//선언 방

```
