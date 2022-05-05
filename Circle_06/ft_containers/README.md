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

#### 참고자료

- https://www.cplusplus.com/reference/stl/
- https://en.cppreference.com/w/cpp/container
- https://docs.microsoft.com/ko-kr/cpp/standard-library/
- https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/annotated.html
- https://runebook.dev/ko/docs/cpp/-index-

---

#### 벡터(Vector)

- 데이터 추가가 용이하기 때문에 저장할 데이터가 가변적일 때 사용
- 중간 데이터 삽입이나 삭제는 자원 낭비이므로 일어나지 않아도 되는 경우 사용
- 위치를 알고 있다면 데이터 접근 용이

#### 맵(Map)

- 많은 자료를 정렬해야 할 때 사용
- 많은 자료를 저장하고, 검색이 빨라야 할 때 사용
- 빈번한 삽입과 삭제는 자원 낭비이므로 가급적 사용하지 않음
- 중복 키 불가

---

#### STL(Standard Template Library) 표준 템플릿 라이브러리

- 타입 독립적인 자료구조와 알고리즘을 사용하는 일반화 프로그래밍(Generic programming) 개념을 구현하기 위해 개발되었던 C++ 라이브러리를 지칭하는 말
- 컨테이너, 반복자, 알고리즘으로 구성
- https://namu.wiki/w/%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC

---

#### STD(Standard Library) 표준 라이브러리

- C++ 표준 라이브러리는 여러 제네릭 컨테이너들, 그리고 이러한 컨테이너들과 함수 객체, 제네릭 문자열, 스트림(인터렉티브와 파일 입출력을 포함하는), 몇몇 언어 특징 그리고 숫자의 제곱근을 찾는 것 같은 작업을 위한 모든 함수들을 활용하기 위한 함수들을 제공한다. C++ 표준 라이브러리는 또한 ".h"로 끝나는 ISO C90 C 표준 라이브러리의 18 헤더들을 포함하지만 이것들의 사용은 추천되지 않는다. ".h"로 끝나지 않는 헤더는 C++ 표준 라이브러리에는 존재하지 않는다. C++ 표준 라이브러리의 특징은 std 이름공간 (namespace) 내에 선언된다는 것이다.

  C++ 표준 라이브러리는 표준 템플릿 라이브러리(STL : Standard Template Library)에 의해 도입된 관습에 기반하며, 제네릭 프로그래밍과 STL의 개발자들의 연구에 영향을 받았다. 비록 C++ 표준 라이브러리와 STL이 많은 특징들을 공유하지만, 둘 중 어느것도 다른 하나의 상위 집합은 아니다

- https://ko.wikipedia.org/wiki/C%2B%2B_%ED%91%9C%EC%A4%80_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC

---

#### Allocator 할당자

- C++의 표준 라이브러리에서 메모리 할당을 관리하는 객체이다. C++표준 라이브러리에서 이용되는 리스트, 셋 등의 다양한 컨테이너 자료구조들은 용도에 따라 동적 메모리 할당을 요구한다. 할당자는 동적 메모리 할당을 통합 관리하는데 필요한 기능이 정의된 객체이다.
- 주요 멤버 함수
  - allocator : 메모리 공간을 할당하여 그 시작 주소를 반환
  - deallocate : 메모리 공간을 해제
  - construct : 할당된 공간에 요소를 저장
  - destroy : 객체 소멸
  - max_size : 할당할 수 있는 최대 크기 반환
- https://en.cppreference.com/w/cpp/memory/allocator
- https://ko.wikipedia.org/wiki/%ED%95%A0%EB%8B%B9%EC%9E%90

---

#### Iterator 반복자

- 반복자(iterator)란 STL 컨테이너에 저장된 요소를 반복적으로 순회하여, 각각의 요소에 대한 접근을 제공하는 객체입니다.
  즉, 컨테이너의 구조나 요소의 타입과는 상관없이 컨테이너에 저장된 데이터를 순회하는 과정을 일반화한 표현입니다.
- 반복자의 종류 (http://tcpschool.com/cpp/cpp_iterator_category)
  - 입력 반복자(input iterator)
  - 출력 반복자(output iterator)
  - 순방향 반복자(forward iterator)
  - 양방향 반복자(bidirectional iterator)
  - 임의 접근 반복자(random access iterator)
- 반복자 카테고리(iterator category)
  - https://narss.tistory.com/entry/%EB%B0%98%EB%B3%B5%EC%9E%90-%EC%B9%B4%ED%85%8C%EA%B3%A0%EB%A6%ACiterator-category
- http://www.soen.kr/lecture/ccpp/cpp4/39-2-6.htm
- https://ansohxxn.github.io/stl/chapter16-2/
- https://en.cppreference.com/w/cpp/iterator

---

#### friend 키워드 - 연산자 오버로딩을 위한

- http://tcpschool.com/cpp/cpp_encapsulation_friend
- https://genesis8.tistory.com/98
- https://thrillfighter.tistory.com/283
- https://choryeonworkshop.tistory.com/130

---

#### enable_if

- https://hellobird.tistory.com/135
- https://modoocode.com/255

---

#### 템플릿 문법

- https://modoocode.com/219
- https://int-i.github.io/cpp/2020-03-11/cpp-template-review/
- https://blog.naver.com/vjhh0712v/221561418596

---

#### new/delete vs allocator

- https://kldp.org/node/109031

---

#### explict

http://opensw.wikidot.com/cpp-fundamentals-explicit

---

#### avl tree

- https://www.hanbit.co.kr/channel/category/category_view.html?cms_code=CMS9990721111
- https://sangwoo-joh.github.io/avl-tree
- https://blog.naver.com/babobigi/220945417209
- https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

