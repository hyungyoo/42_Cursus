# TCP/IP Network

## 개념 vs 사실
>
개념은 "abstraction", 사실은 "implementation"
개념은 "사람", 사실은 "유형준"
개념은 "이상", 사실은 "실체"
#### "사실은 개념의 실체이다."
OSI 7 Layer는 "이상"에 해당한다. 즉, "개념어" 이다.



## OSI 7 Layer

User mode (운영체제) : S/W의영역

L7    									프로세스
L6
L5
										FILE (Kernel의 구성요소를 유저모드
												어플리케이션으로 추상화할때에는
												FILE의 형태로 추상화를한다)
 ==================================================
Kernel mode	: S/W의 영역

L4(Transport) 							TCP/IP
L3(Network)								

										Driver (NIC 하드웨어를 움직일수있는
												디바이스 드라이버)
 ==================================================
H/W의 영역 : 

L2										NIC (network interface card)
L1

![Screen Shot 2022-03-15 at 1 07 48 AM](https://user-images.githubusercontent.com/71254925/158280796-6c703000-5e27-4490-ba5d-73accbabc29c.png)


#### FILE : Kernel부분의 TCP/IP이 네트워크이며, TCP의 구성요소를 유저모드가 접근할수있도록 파일의 형식으로 추상화한 인터페이스를  "소켓" 이라고 부른다.

