# TCP/IP Network

## 개념 vs 사실
>
개념은 "abstraction", 사실은 "implementation"
개념은 "사람", 사실은 "유형준"
개념은 "이상", 사실은 "실체"
#### "사실은 개념의 실체이다."
OSI 7 Layer는 "이상"에 해당한다. 즉, "개념어" 이다.



# OSI 7 Layer

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

![Screen Shot 2022-03-15 at 1 13 55 AM](https://user-images.githubusercontent.com/71254925/158281330-140274a8-ac29-4178-9342-626c1b6c411c.png)

#### FILE : Kernel부분의 TCP/IP이 네트워크이며, TCP의 구성요소를 유저모드가 접근할수있도록 파일의 형식으로 추상화한 인터페이스를  "소켓" 이라고 부른다.

#### L4, L3, L2 에서의 식별자
>
1. Port 번호: 
	- S/W 개발 관리 입장(User mode)에서는, PORT는 "프로세스식별자"이다
	- Network 관리자 (Kernel mode L4)의 입장에서는, PORT는 "Service"이다. (http에서 80포트인, http service를 사용)
	- H/W 에서는, "인터페이스 번호"이다(공유기 단자의 번호) 
2. IP 주소:
	- "HOST"에 대한 식별자 (HOST: "인터넷에 연결된" 컴퓨터)
3. MAC 주소:
	- NIC (LAN 카: 유/무선)에 대한 식별자
	- NIC하나에 여러개의 IP주소를 "바인딩"할수있다
	- MAC주소는 변경 가능하다.


# HOST, SWITCH et NETWORK

![Screen Shot 2022-03-15 at 1 49 34 AM](https://user-images.githubusercontent.com/71254925/158284522-f9e0d804-4a69-4a3f-9bb7-d6215316392e.png)


### HOST
> "network"에 연결된 컴퓨터 = Computer + Network
- Net 자체를 이루는 HOST = SWITCH
	- Router
	- 
- Net 이용주체로서의 HOST = End-Point (단말기)
	- Peer
	- server
	- client

### NerWork = Internet = Router + DNS
> internet = router의 거대한 집합체
> internet은 크게 router와 DNS로 이루어져있다

### SWITCH
>
1. Router : 경로 선정
	- MAC : L2 switch
	- IP : L3 switch
	- TCP port : L4 switch
2. F/W : 보안
3. IPS : 보안

### 공유기도 스위치일까? 그렇다면 어떤 레이어에 위치할까?
> 
