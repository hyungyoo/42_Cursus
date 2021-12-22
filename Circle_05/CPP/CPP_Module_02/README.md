# CPP_Module_02
> Polymorphisme ad-hoc, overloads et classes canoniques
오버로드는 기본기능외에, 또 다른 기능을 할수있도록 중복정의를 하는!

## Polymarphisme ad-hoc
cppㄴ는 엄격한 자료형을 가지고있지만, 오버로드를 사용할수있다.
하나의 함수에 여러개의 형태를 부여한다는 뜻으로 다형성이라고 한다. 다형성의 장점은
어떤함수를 부를것인지 컴파일러가 결정한다는것이다.
> ad-hor polymorphism에는 두가지가있다.
1. Function overloading
2. Operator overloading

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

예)
```cpp

class Interger
{
	public:
		Interger(int const n);
		~Interger(void);

		int		getValue(void) const;

		Interger & operator=(Interger const & rhs);
		Interger  operator+(Interger const & rhs) const;
	
	private:
		int	_n;

};

std::ostream & operator<<(std::ostream &o, Interger const & rhs);

Interger::Interger(int const n) : _n(n)
{
	std::cout << "Constructor called with value" << n << std::endl;
}

Interger::~Interger(void)
{
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return ;
}

int		Interger::getValue(void) const
{
	return (this->_n);
}

Interger	&Interger::operator=(Interger cosnt & rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();
	return (*this);
}

Interger	Interger::operator+(Interger const & rhs) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return (Interger(this->_n + this.getValue()));
}

std::ostream	&operator<<(std::ostream &0, interger const &rhs)
{
	o << rhs.getValue();
	reutrn (o);
}

/* resultat */
int		main(void)
{
	Interger	x(30);			// Constructor called with value 30
	Interger	y(10);			// Constructor called with value 10
	Interger	z(0);			// Constructor called with value 0

	std::cout << "Value of x: " << x << std::endl;		// Value of x : 30
	std::cout << "Value of y: " << y << std::endl;		// Value of y : 10

	y = Interger(12);											// Constructor called with value 12
																// Assignation operator called from 10 to 12
																// Destructor called with value 12
	std::cout << "Value of y: " << y << std::endl;				// value of y : 12
																																				// this->_n 은 앞에있는것
	std::cout << "Value of z: " << z << std::endl;								// value of z : 0

	z = x + y;																	// Addition operator called with 30 and 12		//in x instance
																				// Constructor called with value 42
																				// Assignation operator called from 0 to 42
																				// Destructor called with value 42
	std::cout << "Value of z: " << z << std::endl;								// value of z : 42
																		
																						// Destructor called with value 42
																						// Destructor called with value 12
																						// Destructor called with value 30

	return (0);
}





```

## 연산자 오버로딩에서 주의할점

####> 1. 단항연산자
```cpp

class Point
{
	private;
		int	x;
		int	y;

	public:
		
		Point(int i, int j)
		{
			x = i;
			y = j;
		}
		
		void	upPrint()
		{
			++x;
			++y;
			std::cout << x << y << std::endl;
		}

		Point	up()
		{
			++x;
			++y;
			return (*this);	/* 리턴형값 Point, 즉 클래스의 자료형이라고한다면, 그 클래스의 모든 멤버 변수들을 "다" 리턴한다는뜻 */
		}

		/* 여기서, up함수는 모든 멤버의 변수들을 다 ++해주는것, 즉 단항 연산자 중첩과 같다 */

		Point operator++()			// 또는 Point operator++(int);
		{
			++x;
			++y;
			return (*this);
		}

}

/* main */

int	main(void)
{
	Point	p1(2, 3);

	++p1;		// Point operator++(); == Point up(); 
				// operator++ == up

	p1++;
	return (0);
}
```

#### 2. 이항연산자
> 이항연산자 중첩에서는 한개의 매개변수가 필요하다.
연산자의 왼쪽 피 연산자가 연산자 함수의 주체가된다! 오른쪽 피연산자만 있으면 되기떄문이다.
즉, 1 + 2는 연산에서 왼쪽 피 연산자 1 이 "+"연산자의 주체이다.
a = 1 + (2);

```cpp

class Point
{
	private:
		int	x, y;
	public:
		Point()
		{
			x = 0;
			y = 0;
		}
		Point(int xx, int yy)	// 생성자 오버로딩
		{
			x = xx;
			y = yy;
		}
		Point operator+(Point ob)		// ob == ob2;
		{
			Point temp;
			temp.x = x + ob.x;
			temp.y = y + ob.y;
			return (temp);
		}
}


int	main(void)
{
	Point ob1(3, 5);	
	Point ob2(4, 6);	
	Point ob3();

	ob3 = ob1 + ob2;
	return (0);
}
```
