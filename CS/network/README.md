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


# Switch, Switching? : 경로"선택", 혹은 interface "선택"
>
"switch : Net 자체를 이루는 HOST", "라우터가 하는 일"

![Screen Shot 2022-03-15 at 3 01 56 AM](https://user-images.githubusercontent.com/71254925/158291167-b8668d64-5563-47ad-9116-4b281f89c542.png)

Packet -> 자동
#### routing table -> 이정표 (의사결정의 기준)
#### Network -> 고속도로 : 라우터의 집합체
#### switch -> 교차로 : 라우터
switching -> 선택

# 네트워크 단위 정리

![Screen Shot 2022-03-15 at 3 49 59 AM](https://user-images.githubusercontent.com/71254925/158296129-c2fb6260-674b-4c09-9b8a-4d2e56852232.png)


>
1. User mode에서, process가 file에 stream 데이터를 write한다.
2. user에서 kernel로 내려가서, tcp로 가면, segmentation (분해: 일정 길이로 자르기)화로, segemnt가 된다.
 - 분할하는 길이는 : MSS (maximum segment size) -> packet의 크기에 따라 결정된다 (MTU : Maximum transprot unit : 1500 bytes)
3. H/W수준에서, Frame으로 incapsulation이 된다.

즉, user모드 application process 수준에서는 (socket), stream 데이터이다. (끝을 알수없는 연결된 데이터)
그것을 네트워크로 보낼때에는, 분해가일어나는데, 그것을 segmentation이라고하며, 그 단위를 segment라고 한다.
그것을 인터넷 환경에서 전송가능한 형태로 포장한것을 packet이라고 한다.


# 네트워크 인터페이스 선택 원리와 기준

#### 인터페이스 선택은, PC의 경우 메트릭값(비용)으로 결정이된다.

![Screen Shot 2022-03-15 at 4 01 17 AM](https://user-images.githubusercontent.com/71254925/158297459-8ff553b2-4537-41c1-aa8d-349cfa1d8163.png)


>  
switching : 인터페이스 선택
chrome은 어떤 경로로 두개의 경로중 어느쪽으로 네이버에 접속을 할까?

#### 라우팅 결로 결정순서
https://itaeheon.tistory.com/34#:~:text=Metric%20%EA%B0%92,%EB%8A%94%20%ED%94%84%EB%A1%9C%ED%86%A0%EC%BD%9C%EC%97%90%20%EB%94%B0%EB%9D%BC%20%EB%8B%AC%EB%9D%BC%EC%A7%84%EB%8B%A4

# 웹서비스의 구조


![Screen Shot 2022-03-15 at 4 47 38 AM](https://user-images.githubusercontent.com/71254925/158302352-e0b58468-91e0-466d-8708-8777d93afe4c.png)

#### web의 탄생
> 
티모시 버너스리 (창시자)
문서 (text) + link = HTML (문서양식)
+ HTML (문서양식) + 인터넷 연결 = http 프로토콜
= Web

#### 즉, html (문서구조) + http(송수신 프로토콜) = web service
>
프로그램을 이루는 세가지
1. 인터페이스 = UI
2. 사람에게 보여주고, 사람이 입력할수있도록하는 소프트웨어 = 제어체계
3. 데이터 = 자료구조

#### web client와 web server사이는 tcp/ip"연결"이 되어있으며, 이 연결을 기초로 http통신이 연결이된다.

![Screen Shot 2022-03-15 at 5 14 34 AM](https://user-images.githubusercontent.com/71254925/158305153-639c7005-7727-4f16-a333-d146f2c2d6ee.png)

> 
tcp/ip는 "연결"이 되어야하므로, 상태를 포함한다.
http의 특징 : "stateless"
그러나 tcp/ip 위에서 작동하는 http는 상태의 개념이 없다.

주소 URL에서 R은 리소스이며, 리소스는 html이다.

http.request.method == Get 을 이용하여, 리소스를 요청
그러므로, get은 read의 역활을 한다.

http.response는 web client에게 html을 넘겨준다.
html을 browser가 읽는 순서 (tag가 있기때문에)
1. 구문분석 (parsing)
	- parser가 자료구조(비선형 트리구조)를 생성한다 DOM
2. 화면에 렌더링 (출력)
그렇기에, 브라우저는 "구문분석기"와 "렌더링엔진"로 이루어진다.

초기의 브라우저는 문서뷰어와 같지만, "원격지" 문서 뷰어이다. (단방향 작용 : request -> response)

인터넷이 발전하면서, client로부터 server로의 정보전달(사용자입력)을 포함한 요청도 생겨난다. 
#### 정적

![Screen Shot 2022-03-15 at 5 35 34 AM](https://user-images.githubusercontent.com/71254925/158307278-df7e7919-962c-4923-bb47-e1d90fd221dc.png)

또한, web server가 송수신을 담당하였지만, 처리(연산)을 담당하는 요소가 생겨난다.
tester를 post로 받자마자 web server가 바로 처리담당 요소에게 넘기게된다.


인터넷이 발전하면서, client로부터 server로의 정보전달(사용자입력)을 포함한 요청도 생겨난다. 
-> 양방향 상호작용 -> 문맥(상태 -> 전이) -> http는 stateless이므로, 달라진상태를 기억(기록)할수가없다.
-> 기억이라는 개념을 저장해 놓아야할 필요가 생겼다. -> database

web-server는 처리를 하는 요소를 통해, 데이터베이스에 특정 데이터를 요청하고, 그에 맞는 데이터를 받은 처리요소는
그에따른 새로운 문서를 "생성"한다. 
#### 동적으로 생성이된다.

또한, Web client (브라우저)에서 연산을 할수있는 S/W를 추가한다. -> 자바 스크립트

![Screen Shot 2022-03-15 at 5 48 51 AM](https://user-images.githubusercontent.com/71254925/158308555-5ca8584d-39cc-4174-98df-ebaabca46f42.png)

#### Web-client를 이루는 3요소 : 1, 구문분석하는 parser 2. 그래픽 렌더링 엔진 3.연산주체가 되는 스크립트엔진
또힌, client에서의 기록이되는것은 "cookie"로서 구현이된다.

# WAS, JVM et RESTful API

### WAS
> web-server에서 처리(연산)을 하는 주체는 "WAS" 
![Screen Shot 2022-03-15 at 6 00 08 AM](https://user-images.githubusercontent.com/71254925/158309769-db99f05a-4c12-4651-aa08-9658cbfc7e0b.png)

참고 : https://gmlwjd9405.github.io/2018/10/27/webserver-vs-was.html

### JVM
![Screen Shot 2022-03-15 at 6 08 31 AM](https://user-images.githubusercontent.com/71254925/158310732-e23430db-6d39-4119-8d23-d751a3696cf6.png)

또한, 웹서버의 성능은, WAS와 DATABASE에서, DATABASE의 응답속도, 또는 JVM에서 java byte에 따라 결정된다.
그래서, 이 두가지를 모니터링하는 솔루션이있다. : APM (scouter APM)

![Screen Shot 2022-03-15 at 6 33 10 AM](https://user-images.githubusercontent.com/71254925/158313437-23bb5c2f-53e5-4310-801b-6f7b62e7006b.png)

참고 : 
https://blog.naver.com/hj_kim97/222309537552
https://blueyikim.tistory.com/2177


