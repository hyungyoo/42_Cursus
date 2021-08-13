# Inter Process Communication
	1. 프로세스간의 통신문제!
	Cooperating processes require an IPC mechanism
	- that will allow them to exchange data
	- that is, send data to and receive data from each other
	
	2. 두가지 방법
	- shared memory
	  to allow producer and consomer to run concurrently, 
	  let a "buffer" of items be available
	  a shared memory is a region of memory(by OS),  
	  that is shared by the producer(fill the buffer)
	  and consummer(empty the buffer) processes. 
	- message passing
	  send, receive message
	  
	 3. IPC의 예
	 - shared memory = POSIX Shared memory
	 POSIX : Portable Operating System Interface (for Unix)
	 memory-mapped file을 이용함 --> fd를 할당받아, 한곳에서는 보내고
	 한곳에서는 받는다.
	 - Pipe
	 unidirection!!!  
	 그리고 프로세스는 parent-child 관계이다. 
	 
	 
# 함수 설명

	1. access
	#include <unistd.h>
	int	main(void)
	{
		char	*path = "./txt";
		int	maode = R_OK | W_OK;
		if (acess(path, mode) = 0)
			읽고 쓸수있음
		else
			권한이 없거나 존재하지않음
	}

	9. wait
		자식 프로세스를 고아프로세스로 만들지않기위해서 부모 프로세스에게 사용하는 함수

	11. pipe
		파이프를 생성하며, 파이프에 쓰고 읽을수있는 스트림 디스크립터 두개를 생성한다
		포식스의 숫자와는 반대
	
	13. dup2
		함수형태 : int	dup2(int fd1, int fd2);
		fd2를 fd1으로 redirection한다!
	
	14. execve
		실행함수, 받는 인자는 (경로, 명령어, 환경변수)
		경로 : 우리가 사용하는 명령어 자체도 모두다 실행파일로 볼수있다.
		shell에 env라고 명령어를 치면, PATH 환경변수가 나옴!
		":"으로 나눠져있기때문에, :를 기준으로 스플릿후에,
		명령어와함께 "access"함수로 읽고 사용가능한지 확인가능
	
	15. fork
		프로세스는 실행프로그램을 실행하는순간, 그 전의 프로세스로 돌아갈수없다
		그렇기 떄문에, 자식 프로세스를 만든다.
		자식 프로세스는 부모프로세스의 모든 환경변수를 복제해서 만들어진다 (즉, 같은 환경으로 시작)
		반환 PID (pid_t형) 으로 자식인지(0), 부모인지 ( > 0) 또는 실패인지 ( < 0) 알수있다.
		
		예) fork()를 사용했을때, 부모함수가 wait()함수를 사용하는것과같음.
		 =====예==== 그러나 Multi process는 다른 프로세스의 변수나 자료구조에 접근못함
		 int j = 0;

		 int main(void)
		 {
		   pid_t pid = fork();
		   if (pid > 0)
		   {
			wait();
			return (0);
		   }
		   else if (pid == 0)
			j += 15;
		   printf("%d\n", j);
		   return (0);
		 }
		 결과값 ==>>> 0;

	16. perror
		원래는 erron 번호를 부여받고, stderr함수를 쓰려고했는데,
		perror는 그 둘을 한번에 사용할수있는 함수!
	
	
	17. write, read, open, close
		이 네가지 시스템콜 함수들은 많이 사용해봤으니 설명 필요없음!
	
	
# 과제 목표
	내 생각에, 이 과제는 ipc와 프로세스들 사이의 관계를 공부하는 프로젝트이다.
	프로세스들은 간단하게, 실행중인 프로그램을 의미한다.
	ipc를 통하여, minitalk처럼 signal을 주거나, pipe처럼 프로세스간의 데이터를 주고받을수있는 방법이 있다.

# 구현 방법
	자식프로세스는 부모프로세스보다 먼저 실행파일(명령어)를 수행하고, 종료되어야하기때문에, 첫번째 명령어는 자식프로세스로!
	두번쨰는 부모프로세스로

	* < file_in cmd1 | cmd2 > file_out

	1. 자식 프로세스
	* < file_in --> dup2(fd_file_in, STDOUT_FILENO): 표준출력을을 file_in으로 redirection
	
	* 부모 프로세스로 파이프 연결 -> dup2(fd_WRITE_pipe, STDIN_FILENO); 표준입력을 ft_write_pip로 redirection
	
	* execve함수 (경로는 env에서 PATH를 받아, parsing);

	2. 부모도 비슷하게!

# 구현 순서

	1. fork함수로 pid를 받아, 부모프로세스 , 자식프로세스 만들
	2. pipe_fd 로 두개의 스트림 디스크립터를 받아 연결!
	3. 명령어가 /로 시작할때, 아닐때 구분 (주소를 가지고있는지)
	4. envp에서 주소를 가져온후에, :로 parsing후에, 명령어와 strjoin 후에, access함수확인
	5. 있다면, execve 함수로, 아니면 error 출력

# Tester Pipex
	https://github.com/vfurmane/pipex-tester.git
