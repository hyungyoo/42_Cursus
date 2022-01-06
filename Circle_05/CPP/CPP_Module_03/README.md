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
