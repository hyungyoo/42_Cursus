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
	 interrupt가 일어났을 때, running process의 CONTEXT + PC(programme count)를 저장해놓고, 
	 ready queue에 있다가 restore한다.
	 즉, 현재 프로세스의 context state를 저장하고, cpu를 다시 점유할 프로세스를  restore함! 

	2. Multi Process : 하나의 프로그램을 여러개의 프로세스로 구성하여, 각 프로세스가 
	 하나의 작업처럼 처리를 하는것!, 하나의 프로세스가 잘못되어도 프로그램을 작동한다는 장점이 있는반면
	 context switching의 비용이 발생한다.
	 time sharing --> scheduling Queues (FIFO) --> ready queue
	 running상태에서는 ready queue로 돌아가거나, waiting상태로 가던가(i/o event)
	
	3. Multi thread : 프로그램의 여러개의 쓰레드로 구성하고, 각 쓰레드가 작업을 처리하는것
	처리 비용의 감소, 쓰레드간의 공유영역이 생기지만, 반대로 동기화 이슈 또는 하나의 쓰레드오류가 
	전체 프로세스의 문제발생으로 이어질수있다.
	 스레드는 lightweight process이다. 또한 가장 기본적인 cpu점유단위!
	 실제로는 cpu를 점유하는것은 pid가 아닌 tid이다!
	 스레드가 공유하는것 : code, data, files
	 공유하지 않는것 : registers, pc, stack
	 responsivensess : may allow continued execution
	 resource sharing : threads share resources of process
	 economy : cheaper than process creation! thread switching lower overhand than context switching
	 scalability : process can take advantage of multiprocessor architectures
	 
	
	4. Thread Safe : 여러 thread가 동시에 사용되어도 안전하다는것을 뜻함.
	예로는 동기화, Mutext, Semaphore, synchronized가 있다.

### 3.  프로세스 동기화
	1. critical section.
	 임계영역! --> n개의 프로세스가있을때, 어떠한 segment of code 를 critical section이라고한다.
	 하나의 프로세스가 임계영역을 점유하고있다면, 다른 프로세스들은 접근할수없도록 해야한다.
	 entry-section
	 critical-section -> 도중에 코드가 끝나지않도록 해야한다. race condition 발생
	 exit-section
	 remainder-section
	 
	 while (true)
	 	entre section
			critical section
		exit section
			remainder section
	
	2. 3 solutions for critical section
	- 1. mutual exclusion (상호 배제): if process P1 is executing in its critical section,
	then no other processes can be executing in their critical section.
	- 2. Deadlock : 대기하는 다른 프로세스들이 critical section에 진입하지 못함
	- 3. Starvation : 프로세스들이 기다리는 시간을 한정시켜야한다. 그냥 순서대로 진입하게되면,
	 마지막에 있는 프로세스는 진입하지못함.
	 
	3. Peterson's solution --> but no guarantees (entry section에서 context switching)
	int	turn;
	int	flag[2];
	
	void	*producer(void *param)
	{
		int	k;
		for (k = 0; k < 10000; k++)
		{
			/*entry section */
			flag[0] = true;
			turn = 1;
			while (flag[1] && turn == 1)
				;
			/* critical section */
			sum++;
			
			/*exit section */
			flag[0] = false;
			
			/* remainder section*/
		}
		pthread_exit(0);
	}
	
	void	*consumer(void *param)
	{
		int	k;
		for (k = 0; k < 10000; k++)
		{
			/*entry section */
			flag[1] = true;
			turn = 0;
			while (flag[0] && turn == 0)
				;
			/* critical section */
			sum++;
			
			/*exit section */
			flag[1] = false;
			
			/* remainder section*/
		}
		pthread_exit(0);
	}
	
	int	main(void)
	{
		pthread_t tid1, tid2;
		pthread_create(&tid1, NULL, producer, NULL);
		pthread_create(&tid2, NULL, consumer, NULL);
		pthread_join(tid1, NULL);
		pthread_join(tid2, NULL);
		printf("sum = %d\n, sum)l
		return (0);
	}
	
	4. Higher-level software tools to solve the CSP
	- mutex(MUTual EXclusion) locks : the simplest tools for synchronization.
		to protect critical section and prevent race condition.
		a process must acquire the lock before entrering a critical section.
		releases the lock when it exits the critical section.
		 예)
		 
		 acquire()
		 {
		 	while (!available)
				busy waiting;
			available = false;
		 }
		 
		 release ()
		 {
		 	available = true;
		 }
		 
		 while (true)
		 {
		 	acquire lock
				critical section
			release lock
				remainder section
		 }
		 
		 * 어떤 프로세스가 CS에 들어가기위해서, 무한루프속에서 기다려야한다.
		 그것이 busy waiting! 원하는 자원을 얻기위해서 기다리는것이아니라,
		 권한을 얻을 때까지 확인하는것을 의미한다. 그러나 권한의 획득을 위하여,
		 많은 cpu의 낭비가 예상되므로, sleeping이라는 방법을 사용하기도한다.
		 기다리는 시간이 예측불가능할 경우에, 사용하지만, wait queue에 넣는 비용과
		 context switching의 비용이 드는 단점이있다.
		 
		 코드 예제)
		 
		 int	sum = 0; //a shared variable
		 pthread_mutex_t mutex;
		 
		 void	*counter(void *param)
		 {
		 	int	k;
			for (k = 0; k < 10000; k++)
			{
				/* entry section */
				pthread_mutex_lock(&mutex);
		 		/* critical section */
				sum++;
				/*exit section */
				pthread_mutex_unlock(&mutex);
			}
			pthread_exit(0);
		}
		
		 int	main(void)
		 {
		 	pthread_t tid1, tid2;
			pthread_mutex_init(&mutex, NULL);
			pthread_create(&tid1, NULL, counter, NULL);
			pthread_create(&tid2, NULL, counter, NULL);
			pthread_join(tid1, NULL);
			pthread_join(tid2, NULL);
			printf("sum = %d\n", sum);
			return (0);
		}
		 
		 하지만, 이 코드로는 아직까지 Deadlock, Starvation의 위험성이 남아있음.
		 
	- semaphore : more robust, convenient, and effective tool.
		
