# Templated containers, iterators, algorithms

## array 와 vector의 차이
> array stack에 vetor는 heap에 연속된 공간이 할당된다. 즉, array는 compile에 stack frame에서 할당이되며, vetor는 run time에 할당된다.
이때, vetor는 stack에 24bytes(8bytes pointer, 8bytes size and 8bytes capacity)를 할당한후에, heap에 메모리할당 (flexible size)

### array
1. fast
2. complie
3. fixed size
4. limited to stackframe

### vector
1. heap
2. run time
3. flexible size
4. huge memory size
5. The complexity (efficiency) of common operations on vectors is as follows:
> Random access - constant 𝓞(1) 
	Insertion or removal of elements at the end - amortized constant 𝓞(1) 
Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n)


## deque
1. o(1)의 random access를 지원한다. Double ended queue
2. The complexity (efficiency) of common operations on deques is as follows:
> Random access - constant O(1)
	Insertion or removal of elements at the end or beginning - constant O(1)
Insertion or removal of elements - linear O(n)

## set
1. red-black structure
2. sorted


## ex00
> easyfind라는 함수를 만든다. 함수의 리턴값은 iterator이다.
즉, vector, deque, array등등의 iterator를 받아야하므로, 반환값은 "typename T::iterator" 로 한다.
```cpp

template<typename T>
typename T::iterator easyfind(T &c, int v)
{
	// 반환값을 선연할떄는 typename T::iterator로 선언
	// typename이 없다면, error: missing 'typename' prior to dependent type name 'T::iterator'
	// std::vector<T>::iterator is a dependent name, so you need a typename here to specify that it refers to a type. 
	// Otherwise it is assumed to refer to a non-type:	
	...
}


```

## ex01
> Span 클래스를 만들고, 각 벡터내부의 리스트중를 이용하여, shortestSpan 그리고 longestSpan을 만든다.
전혀 어렵지않음
1. try, throw and catch
2. vector with begin(), end(), sort(), copy(), max_element, min_element...

## ex02
> stack은 컨테이너에 대한 접근을 제어하는 목적으로 사용된다. 즉, iterator를 제공하지않는다.
이번과제에서는 iterator를 받아야한다.(begin(), end())

template< class T, class Container = std::deque<T>
 class stack;

 즉, stack은 deque를 기반으로만들어졌고, stack에는 c라는 container 변수가있다.

 우리는 iterator에 접근하기위해, c변수(deque)를 이용하여, iterator에 접근할수있다.
 MutantStack은 stack으로부터 상속받는다.


