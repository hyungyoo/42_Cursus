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

# IP 주소와 Net-mask

![Screen Shot 2022-03-15 at 2 19 47 AM](https://user-images.githubusercontent.com/71254925/158287193-f75eba54-88e6-43c4-99a6-e172d3baaf66.png)

### IP 주소 : Internet Protocol
> HOST에 대한 식별자 : Network에서의 각각의 HOST를 식별하는 주소
1. IPv4 : 주소길이가 32 비트 : 2의 32승 : 43억개
2. IPv6 : 주소길이가 128 비트

![Screen Shot 2022-03-15 at 2 28 56 AM](https://user-images.githubusercontent.com/71254925/158287994-db139a25-c166-4202-837d-6177f7cb5b20.png)

### IP주소는 Network ID 와 HOST ID로 나뉜다.
> IP주소에서 Network ID의 주소 길이를 나타내는게, subnet mask이다.


![Screen Shot 2022-03-15 at 2 28 56 AM](https://user-images.githubusercontent.com/71254925/158287994-db139a25-c166-4202-837d-6177f7cb5b20.png)

즉, IP주소에 서브넷마스크를 and연산 한다면, 연산의 결과는 network ID 이다.

![Screen Shot 2022-03-15 at 2 34 52 AM](https://user-images.githubusercontent.com/71254925/158288510-e0ba4b32-b852-4698-972b-17350dec932d.png)

192.168.60.14 이고, 서브넷마스크가 255.255.255.0이라면,
and연산의 결과는 192.168.60.0 이며, 이는 network ID이다.
또한 192.168.60.14/24 로 나타낼수있다.

# 개발자 입장에서의 Port 번호 : Process 식별자, service, interface...
> 
Port 번호는 16bit이다. 대략, 0 ~ 65535 (0과 65535는 사용하지않는다) 
또한 port 번호는 socket에 바인딩 된다.

![Screen Shot 2022-03-15 at 2 43 18 AM](https://user-images.githubusercontent.com/71254925/158289330-1725749a-6b4d-4bfb-a005-a026f784f915.png)




