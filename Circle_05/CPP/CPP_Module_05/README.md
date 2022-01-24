# try catch

### ex00 
Bureaucrat 클래스를 만든다. 각 bureaucrat는 각 등급을 가지며, 각 등급은 1에서 150 사이 이다. 
#### 1. try, throw, catch 
 Bureaucrat 클래스에는, 다시 exception으로부터 상속받은, GradeTooHighException과 GradeTooLowException 클래스 두개가있다. 이 두가지에는 virtual const char * what() const throw(); 함수가있다.
이것은 what()이라는 exception클래스의 가상멤버함수를 받아, const char * 형태의 반환값을가지며, 이것을 throw한다.
그것을 가장가까운 catch가 받는다. 조건은 catch (const std::exception &e)
여기서 e의 멤버함수인 what()으로 오류를 출력한다.

### ex01
> 이것도 그냥 연습인데, 두개의 클래스가 서로 참조를하거나 또는 함수내에서 쓰이게되면, 구조체처럼 서로의 프로토타입을 써주면됨
또한, beSigned(Bureaucrat const &rhs)함수와 signForm(Form &form)함수를 구현한다.
알고리즘이나 내용이 어려운것은없고, 단지 throw를 어느순간 내보내야하는지, catch를 어느순간 해야하는지만 생각하면된다.

### ex02
> Form으로 부터 상속받는 세가지의 클래스를 만든다. 여기서 execute함수는 가상이며, Form 클래스가 추상클래스가 되어야하므로, 나는 execute함수를 순수 가상함수로 구현하였다. 다른점은 throw부분이 겹치기때문에, 바디부분도 구현하였고, 각 파생클래스의 execute에서 순수가상함수의 바디부분을 가져와 사용하였다. 그리고, 부모의 멤버변수는 private이므로, 파생클래스 생성시, 부모클래스의 생성자를 호출하여, 변수를 초기화한다.

#### 2. Shr
 ascii 트리를 진짜 나무로 만들었는데, 아는듯. module 01에서 했던 ofstream을 다시하면됨.

#### 3. Robo
 50%의 확률로 서로다른 문장을 출력해야하는데, 이를 위해 나는 숫자를 2로 모듈로하여 짝수 홀수를 구하였다. 이걸위해서, random_int 를 선언하고, rand()로 숫자를 가져오지만, 이대로만 한다면, 계속해서 같은수만 나온다. 그렇기때문에,   srand()와 time()를 사용해야한다.

#### 4. presidential
 이건뭐 설명할것도없음. 그냥 출력되고끝

#### 5. up casting
 다른사람들이 한걸봤는데, 나는 다형성을 배우고, 부모클래스의 포인터로 자식클래스로 접근하는 것이, 가상함수, 다형성을 배운 가장 큰 이유라고생각하며, 업캐스팅이 편하기때문에, 이렇게 main을 만들었다. 오버로딩이 아닌 오버라이딩을 하였다!


### ex03
> Intern 클래스에, makeForm 함수를 만든다. 이 함수는 form과 target을 인자로 받아, form을 생성한다. 
아주 쉽지만, 문제는 if, else, switch같은걸 쓰지못함. 즉, 앞에서의 문제에서 처럼 for을 사용해야한다. 작은 문제로는 new를 가진 배열은, 시작하자마자, 자동으로 생성됨.
