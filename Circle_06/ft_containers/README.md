# ft_containers
> STL container의 구현. STL에서, T는 template이며, template는 generic programming의 대표적인 예 이다.
그러므로 이번 프로젝트는 generic programming에 중점을 둔다.

## iterator
> 반복자는 컴테이너 내부의 요소를 가르키는 객체이다. 포인터와 마찬가지로 반복자는 가르키는 요소에 액세스하는데 사용할수 있으며, 컴터에너의 내용을 통해 이동할수있다.

구체적으로, 반복자는 많은 연산자를 제공하는 간단한 "클래스"이다.
1. increment++ : 가리키는 요소의 주변 요소로 이동할수 있어야한다.
2. dereference * : 가리키는 요소의 값에 접근할수 있어야한다. 
3. 포인터와 유사함 (반복자는 포인터의 일반화 이다) 
4. 반복자 사이의 대입연산, 비교연산이 가능해야한다. 따라서 대입, 관계연산자가 정의되어야한다.
즉, 반복자를 기반으로 컨테이너를 검색, 정렬, 계산 및 조작하기 위한 함수 모음이다!

### The nature of iterator
> 
1. Input Iterator : 컨테이너를 한 번만 앞으로 스캔가능, 읽기 전용 // ex: Find()
2. Output Iterator : 컨테이너를 한 번만 앞으로 스캔가능, 쓰기 전용 // ex: Copy()
3. Forward Iterator : Input Iterator + Output Iterator + 컨테이너를 앞으로 여러 번 스캔가능 // ex: Replace()
4. Bidirectional Iterator : Forward Iterator +  컨테이너를 앞뒤로 스캔가능 // ex: Reverse()
5. Random Access Iterator : Bidirectional Iterator + 컨테이너에 비 순차적으로 (즉, 점프하여) 액세스 가능 // ex: sort()
6. Contiguous Iterator : Random Access Iterator + 논리적으로 인접한 요소는 메모리에서도 물리적으로 인접하다. // 


## Red-Black Tree : 균형 이진 탐색 트리
> 레드블랙 트리가 될수있는 5가지 조건
1. 노드는 red or black
2. 루트는 무조건 블랙
3. NIL값은 무조건 블랙
4. 레드 노드의 자식들은 무조건 블랙
5. 각 노드에서 leaf nodes로 가기위해 지나는 블랙노드의 수는 일정해야한다.

