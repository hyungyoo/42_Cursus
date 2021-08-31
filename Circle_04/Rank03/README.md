### Rank03

## 구현순서
	1. 전역변수 사용가능! 공통되는 변수들은 전역변수로!
	2. ft_error함수	
		err 값을 3가지로 나눈다!
		- argc != 2 --> Error: argument
		- file open error (FILE *fd) --> Error: Operation file corrupted
		- "fscanf" --> Error: Operation file corrupted
		이렇게 두가지 문제를 출력한다음 main함수를 리턴값 1과 함께 종료!
	3. 일단 가로 세로의 그림판의 크기만큼, memset함수를 이용하여, 그림판을 배경으로 전부다 초기화함
	4. mini_paint의 경우, 원을 만드는  프로그램
		sqrtf함수로, 픽셀판에서 각각의 점과 원의 중심사이의 거리를 구한다.
		이를 distance라 칭하면, distance(임의점 x,y와 원의 중심사이의 거리) <= cir.r(원의 반지름) 일떼,
		임의점 x,y는 원안에 존재한다!
		또한 이경우에 두가지로 나눌수있다.
		- char c의 타입이 'c'일떄! 이 경우에는 원의 둘레만 출력되야하기때문에,
		float값인 distance에 1을 더하고, 이 값이 cir.r을 넘는지 확인한다.
		넘는다면, 둘레에 위치 (distance + 1 > cir.r) && cir.c == 'c'
		- char c의 타입이 'C'일때, 이미 임의점 x,y는 원안애 존재하며, 내부를 채우는 원이기 때문에
		바로 출력!
	5. micro_paint의 경우, 사각형을 출력함
		임의점 x, y 일떄, rec.x <= x <= rec.x + rec.w의 규칙을 지켜야함!
		내부가 채워져있는 R을 가진 사각형도, 테두리를 얻어야한다!
	6. 가장중요한 free! free하지않으면, 통과못함
