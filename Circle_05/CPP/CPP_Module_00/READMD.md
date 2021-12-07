# CPP Module 00

### Name space
> cpp 에서는, printf 대신에 iostram에서 제공하는 cout를 쓴다. 그런데 cout함수를 쓰기위해서는
전처리기 밑에 using namesapce str;가 필요하다. 또는 std::cout로 사용을 해야한다.
모든 실무에서는 팀으로 진행되는 프로젝트를 하게되며, 나중에는 코드에대해 필요한 코드와 필요하지않은코드를 분리한다.
여러 사람이 작성한 코드중에서 클래스이름이나 훔수의 이름이 같은 경우가 있을것이다. 간단한 add함수를 예를 들자면,
여러 사람들이 add함수를 만들었다고 가정할때, 컴파일당시 문제가 발생하게된다. 그렇기때문에 사용하는것이 name space이다.

사용법

```c

namespace A;

int	main(void)
{
	ADD(1, 2);
	B::ADD(1, 2);
	return (0);
}

```
