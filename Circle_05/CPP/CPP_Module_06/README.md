# < CAST > CPP module 06

> 이 모듈에서는, 캐스팅과, 참조값, 포인터에 대한 공부를 다시한번 하게된다.

#### 묵시적, 명시적 캐스팅
캐스팅에는 묵시적 캐스팅 그리고 명시적 캐스팅이있다.
묵시적캐스팅은 int 값이 자동으로 char로 캐스팅되는 부분을 예로 들수있다.
```cpp
int i = 48; ==> print("%c\n", i);
```
명시적 캐스팅은 말그대로 명시적으로 캐스팅을 해주는 경우이다.
```cpp
int	i = 48;
(char)i;
```
이것을 설명하는이유는 c++에서 명시적캐스팅을 뜻하는건, static_cast이기 때문이다.
하지만, static_cast는 "명시적" 이며, 동시에 "안전"하다. 

#### 참조값
> 참조값은 새롭게 변수에 할당된값을 복사해서 쓰지않고, 그대로 접근해서 쓸수있기때문에, 메모리에 자원을 절약할수있다는 점에서 아주 좋은 방법이다.

```cpp
// 함수의 파라미터로서의 참조값
void	ft_exemple(int i, int j); // int i, int j는 함수가 불리면 새롭게 메모리 공간을 차지함

void	ft_exemple(int &i, int &j); // int i, int j는 함수가 불리면 새롭게  메모리 공간을 차지하지않음

// 함수의 반환값으로서의 참조값  -> 댕글링 참조자
int	&ft_exemple(void)
{
	...
	return (ret);
}

// 반환값으로서의 참조자, 그러나 받는 변수에따라 ..
int	&ref = ft_exemple(i);
int	ref_2 = ft_exemple(i);

ref2는 그냥 값을 받은것뿐, ref는 참조자로서 값을 받음

// const , non-const
const int &ex = 42;		// 가능, 임시 변수생성후에 할당
int &ex = 42;			// 안됨, 변수로 만든후에 넣어줘야함.

// 참조자는 변수를 만든후에, 그 변수값을 r_value에 넣어줘야함. r_value는 원래가 메모리에 잠깐있다가 사라지는 개념이라, l_value의 값이 필요함. 그래야지 참조자의 역활처럼 메모리를 다른이름으로 공유함.
```

## ex00 : static_cast
> 명시적이며, 안전한 캐스팅. 컴파일시에 오류및 실행가능여부를 판단한다.

#### 1. 구현과정
1. 처음은 Convert 클래스를 생성한다.
2. double이 8바이트이므로, 오버플로가 발생하지않도록, input을 double로 바꿔준다.
(생성자에서 바꿔서 num을 초기화해줘야함)
3. 다른숫자들도 다 그렇게 바꿔준다.
4. 4.0과 같이 .0으로 끝나는 수들은, cout에서 .0을 제외하고 출력한다. 그러므로, static_cast<int>(num)의 값과 float 또는 double 값을 확인하여, .0으로 끝난다면, double은 .0, float는 .0f를 붙여준다. 
5. nan, inf값은 isnan 또는 isinf 함수로확인가능하다. <cmath> 헤더 참조
6. try, catch는 char의 변형에서만 사용해도 충분하다.
7. setprecision을 사용해서 double과 float를 출력한다. <iomanip> 헤더 참조
8. ostream을 이용하여 출력

## ex01 : reinterpret_cast, uintptr_t
>  uintptr_t 는 uintptr_t 는 데이터 포인터를 저장할 수있는 부호없는 정수 유형이다.
reinterpret cast를uintptr에 저장한다. (Serialization), 반대는 deserialize

## ex02 : dynamic_cast
> dynamic_cast는 부모클래스 포인터에서 자식클래스 포인터로 다운캐스팅을 할때, 주로 사용된다. 또한 런타임에 실행된다.
너무나도 당연하게, 부모클래스의 포인터가 자식의 클래스를 업캐스팅한다는건, 가상함수를 가진것이며, 이것은 다형성의 형태이다.
그렇다면, 런타임에 정말로 다운캐스팅하려는 자식클래스가, 정말로 부모가 업캐스팅하고있던 자식클래스인지 확실하게 알아야한다.
이떄 사용하는게 dynamic_cast이며, 안전하다. 왜? 다운캐스팅이 잘못된다면, null을 반환한다.

#### 실패할 경우(new_type = pointer) : null pointer
#### 실패할 경우(new_type = reference) : bad_cast (exception 처리)
