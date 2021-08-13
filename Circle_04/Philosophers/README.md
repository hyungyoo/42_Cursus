# Philosophers

## 배경 지식

### 1. Process 와 Thread의 차이! 
	프로세스는 os로 부터 자원을 할당받는 작업의 단위
	여기서 할당받는 시스템 자원은 --> cpu시간, 운영되기위해 필요한 주소공간, 
	그리고 code, data, stack, heap의 구조로 되어있는 독립된 메모리영역!
	각 프로세스는 별도의 주소강간에서 실행되며, 
	한 프로세스는 다른 프로세스의 변수나 자료구조에 접근할수없다!
	접근하려면, IPC사용 --> pipex, minitalk 과제

	스레드는 할당받은 자원을 이용하는 실행의 단위이고 프로세스내에 여려개 생길수 있음.
	프로세스 내에서 실행되는 여러 흐름의 단위, 프로세스의 특정한 수행경로 또는 
	프로세스가 할당받은 자원을 이용하는 실행의 단위!
	스레드는 프로세스 내에서 각각 stack만 따로 할당받고, code, data, heap영역은 공유한다.
	즉 각각의 스레드는 별도의 레지스터와 스택을 갖고있지만, 힙 메모리는 서로 읽고 쓸수있다.

### 2. Context Switching, Multi Process, Multi Thread, Tread Safe
	1. Context Switching : CPU에서 여러 프로세스를 돌아가면서 작업을 처리하는 과정을 뜻함.
	 동작중인 프로세스가 대기를 하면서, 해당 프로세스의 상태(context)를 보관하고 있다가 
	 다시 실행시 복구하는 비용을 말함.
	 context는 process가 가용되고 있는 상태를 뜻한다! 이건 PCB(process control block)에 저장되어있다.
	 interrupt가 일어났을 때, running process의 CONTEXT + PC(programme count)를 저장해놓고, ready queue에 있다가 restore한다.
	 즉, 현재 프로세스의 context state를 저장하고, cpu를 다시 점유할 프로세스를  restore함! 

	2. Multi Process : 하나의 프로그램을 여러개의 프로세스로 구성하여, 각 프로세스가 
	 하나의 작업처럼 처리를 하는것!, 하나의 프로세스가 잘못되어도 프로그램을 작동한다는 장점이 있는반면
	 context switching의 비용이 발생한다.
	 time sharing --> scheduling Queues (FIFO) --> ready queue
	 running상태에서는 ready queue로 돌아가거나, waiting상태로 가던가(i/o event)
	
	3. Multi thread : 프로그램의 여러개의 쓰레드로 구성하고, 각 쓰레드가 작업을 처리하는것
	처리 비용의 감소, 쓰레드간의 공유영역이 생기지만, 반대로 동기화 이슈 또는 하나의 쓰레드오류가 
	전체 프로세스의 문제발생으로 이어질수있다.
	
	4. Thread Safe : 여러 thread가 동시에 사용되어도 안전하다는것을 뜻함.
	예로는 동기화, Mutext, Semaphore, synchronized가 있다.

### 3. 



