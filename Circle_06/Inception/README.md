# Inception 


## NGINX
> NGINX 최신 웹의 증가하는 요구를 지원하기위해 개발된 고성능 웹서버 이다.
NGINX는 높은성능, 높은 동시성 그리고 낮은 자원 사용에 중점을 두고있다.

#### NGINX는 역방향 프록시 이다.
역방향 프록시란: 클라이언트의 요청을 받아 웹서버로 전달하여 응답을 받은후, 다시 클라이언트에
전달하는 역활을 수행하는 서버, 즉 클라이언트와 웹서버 사이에 존재하는 서버이다.
즉, 클라이언트의 요청을 중간에 가로채어 응답을 받는 실제 서버에 전달하고 서버에서 응답이 오면
요청을 했던 클라이언트에게 전달하는 역활을 수행한다.

그렇기때문에, 클라이언트들은 직접적으로 실제 서버에는 통신할수없다.
그로인한 이점,
	1. 로드 밸런싱: 특정 서버에만 요청이 몰리지않도록 역활을 한다.
	2. 안정성: NGINX가 공격을 받지만, 실제 서버에는 공격이 들어오는것을 막는다.
	3. 캐싱: NGINX는 콘텐츠를 캐싱할수있어, 결과를 더 빠르게 응답하여, 성능을 높 일수있습니다.

그렇다면,
### nginx가 고성능 웹 서버라고하는데, 웹서버는 무엇일까?
웹 서버는  "클라이언트로 부터 HTTP 요청을 받아 요청에 해당하는 파일을 HTTP를 통해 보내주는 프로그램" 이라고할수있다.
그렇기에, 동적으로 컨텐츠를 바꿀수는없다 (index.html이라는 파일을 전송할뿐, 파라미터에 따라 데이터를 다르게 내려준다거나 할수는 없다)
즉, 웹서버는 그냥 파일을 보내주는, 그 전송 형식이 HTTP라고 보면된다!
WAS같은 정적 컨텐츠와 로직에따라 동적으로 컴텐츠를 변경하는 웹 프레임워크와는 다르게 nginx는 웹서버이자 정적인 컨텐츠 호스팅이다.

### 프록시
nginx는 프록시(proxy)로도 사용할수있다.
프록시는 "클라이언트와 서버사이에서 데이터를 중계하는 시스템이나 프로그램으로, 인터넷을 사용한다는것은 프록시를 사용한다는것과 같다"
프록시의 구분은
1. Forward Proxy
2. Reverse Proxy

#### Forward Proxy
> 포워드 프록시는 클라이언트와 외부리소스 사이에 위치한다. 즉 요청을 날리는 클라이언트에 좀더 가까이 있다고 볼수있다.
즉, VPN이 포워드 프록시를 활용한것이라고 볼수있다. 프록시를 사용하면, 요청자의 IP가 아닌, 서버의 IP로 요청을 하게되므로
일반적인 방법으로는 접근이 불가능한 리소스를 우회해서 가져올수있다.
외부 인터넷접속시 접근할수있는 사이트를 제한할때에도 사용한다.

#### Reverse Proxy
> 리버스 프록시는 외부에 노출시키려는 리소스 앞 단에 위치한다. 
리버스 프록시가 로드밸린스의 기능을 제공한다.

결과: NGINX는 HTTP 서버, 프록시 기능을 가진 웹서버 소프트웨어이다.

## 도커란, 도커와 VM의 차이, 도커와 도커엔진 (소켓의관계)
> https://www.youtube.com/watch?v=LXJhA3VWXFA

## 도커파일, 도커컴포즈, 네트워크 참고 사이트
>
https://medium.com/swlh/wordpress-deployment-with-nginx-php-fpm-and-mariadb-using-docker-compose-55f59e5c1a
https://epicarts.tistory.com/159?category=887103

## nginx config파일 작성 및 ssl인증서 설치 메뉴
>
http://nginx.org/en/docs/http/configuring_https_servers.html
https://cert.crosscert.com/nginx-ssl%EC%9D%B8%EC%A6%9D%EC%84%9C-%EC%84%A4%EC%B9%98-%EB%A7%A4%EB%89%B4%EC%96%BC/

## SHELL SCRIPT 작성법
> https://hand-over.tistory.com/32

## mysql 과 nginx 종료
> 
sudo systemctl disable nginx
sudo systemctl disable mysql

## 종료확인
>
sudo service nginx status
sudo service mysql status

## docker socket에러
> sudo chmod 777 /var/run/docker.sock

## 각 컨테이너에서, mysqld socket에러
> 
https://stackoverflow.com/questions/11990708/error-cant-connect-to-local-mysql-server-through-socket-var-run-mysqld-mysq
명령어 service mysql start

## YAML file 
> https://youtu.be//1uFVr15xDGg

## .env 파일 설정
> 변수값(r value)이 중복되지않도록 설정해야한다.

## mariadb 체크리스트
1. mysql
2. show databases; // wp_db가 있는지 확인
3. use mysql;
4. select user, host from user; // root 유저 확
5. hostname -i // mariadb_ip (wordpress와 연동을 확인하기위해서)

## wordpress 체크리스트
1. mysql -u root -p1234 -h "mariadb_ip" // wp_db 연동확인
2. wp user list --allow-root // user 확인 (administartor, author)

## 에러발생시 확인
> docker logs CONTAINER_ID

## 볼륨연결 확인
> docker volume inspect CONTAINER_ID

## 데이터 연동 확인
> 
1. comment 입력
2. hyungyoo.42.fr/wp-admin 접속
3. comment 확
