# 과제 설명
	ipc 중의 하나인 시그널 구현!
	1. server에서 pid를 반환한다. 그 반환한 pid를 client에서 server의 pid와 함께 보내면,
		server STDOUT으로 출력!

	2. sever가 하는일!  pid 반환, client로부터 받은 signal로 문자를 출력
	3. client가 하는일! server pid의 유효성을 확인!, STDIN으로 빧은 출력문자를 signal형태로 server에 보내기
	
# 함수 설명

	1. kill , pid와함께, 함수내장형 인자를받는다!. 이 과제에서는 SIGUSR!, SIGUSR2 두개 사용가능. 사용자 정의의 signal
	2. getpid() , pid받는 함수
	3. usleep() , 일정시간동안 코드를 늦출수있다!
	4. pause() ,  시그널을 수신할때까지, 대기상태로!
	5. signal() ,  시그널과 핸들러함수를 호출! 즉, 시그널 처리방법 설

# 구현 방법

	1. server 구현은 getpid()함수로 server pid 출력!
	2. 받은 pid가 유효한지 확인!
	3. 시그널함수를 호출한후에, pause()함수로, 시그널을 수신할때까지 대기상태로!
	-->
	4. client함수에서는 client함수에 들어올 argv의 행태를 확인!
	5. server의 pid를 이용하여, client에서 받은 문자열을 한개씩, 그리고 8개로 나누어(1 byte == char)
		kill함수를 이용하여, 1 또는 0으로, 즉 SIGUSR1 또는 SIGUSR2로 server에게 전송!
	-->
	6. 받은 시그널과 그 시그널을 처리할 핸들러함수로!
	7. 핸들러함수에서는 8개의 시그널을 한개의 바이트! 즉, char로 받아, 한글자씩 출력!
