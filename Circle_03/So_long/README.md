# 2D game

# 함수 설명

	1. <void	*mlx_init();>
	- 그래픽 시스템과 연결을 하게 해준다!
	- 간단한 윈도우 인터페이스 라이브러리
	- 이벤트 관리 기능
	
	2. <void	*mlx_new_window(vo(id *mlx_ptr, int size_x, int size_y, char *title);>
	- mlx_ptr은 <mlx_init>으로 받은 반환값을 넣어주면된다!
	- 성공시, 리턴값은 새로운 윈도우 식별자 ptr;
	- 실패시 NULL반환;
	
	3. <int	mlx_clear_window(void *mlx_ptr, void *win_ptr);>
	- 매개변수로 받은 win_ptr을 검은색으로 clear함 ?????
	
	3. <int mlx_destroy_window(void *mlx_ptr, void *win_ptr);>
	- 매개변수로 받은 win_ptr로 윈도우를 destroy함
	
	4. <char	*mlx_get_data_adr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);>
	- 메모리에 이미지를 만든후, img를 조작할수있는 주소를 얻을수있다.
	- 예)
	- mlx_new_image 함수로 두개의 이미지를 만든다.
	- 하나는 player, 다른 하나는 floor
	- 왜? player만 화면에 출력하면, 플레이어를 제외한 TILE_SIZE(즉, pixel)에서 남는 부분들이 검은색으로 출력됨.
	- 그렇다고, 배경위에 player를 덮어씌우면, 플레이어가 배경이랑(floor) 교차되며 깜빡거리게됨.
	- 그렇다면, 플레이어의 xpm파일에서, 플레이어를 제외한 검은색(픽셀이없는부분)을 배경으로 채워줘야함. 그떄 이 함수를 쓴다!
	- 플레이어의 모든 픽셀을 돌면서, 검은색부분은 배경의 부분으로 교체

		while (i < tile_size)
		{
			whle (i < tile_size)
			{
				if (player.addr == 검은색)
					player.addr = floor.addr;
			}
		}

	
	5. <void	*mlx_new_image(void *mlx_ptr, int width, int height);>
	- 메모리에 이미지를 새로만든다.
	- 성공시, image를 조작할수있는 이미지식별자 리턴
	- 실패시, NULL 리턴
	
	6. <int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);>
	- 저장된 컬로로 window의 (x, y)좌표에 픽셀을 그림!
	
	7. <int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, char *string);>
	- 저장된 스트링을 window의 (x, y)좌표에 나타냄!
	
	8. <int	mlx_loop(void *mlx_ptr);>
	- 이벤트를 받기위해서 끝나지 않는 함수
	
	9. <int	mlx_key_hook(void *win_ptr, int (*f_ptr)(), void *param);>
	- f_ptr함수포인터는 해당 이벤트가 발생했을떄, 호출되는 함수포인터!
	- param은 함수가 호출될때 마다, 함수에 전달되고 저장하기 위해 사용됨.
	
# 함수 사용법
	1. <char *mlx_get_data_addr(void *imp_ptr, int *bits_per_pixel, int *size_line, int *endian);>
	- 나는 32x32 픽셀의 플레이어 png파일을 사용하였다. 이 파일을 그냥썼을때, png파일부분에서 플레이어를 제외한 배경부분이 검은색으로 나타남.
	- 검은색 부분을 배경화면으로 채우기위해서, 모든 부분의 픽셀의 색을 확인하며, 만약에 그 픽셀의 색이 검정색이라면, 그 부분은 배경의 색으로 대체함
	- 코드부분, addr가 반환하는 타입은, (char *)값이지만, (int *)으로 casting하여, 구조체에 저장! (rgb를 표현하는데, 4바이트를 쓰기때문에, int *값으로 받으면, 바로 비교가 가능함. 
	- 그렇게 받은 배경 bg.addr와 player.addr를 i와 j를 이용한 이중 루프로 확인하여, 검정색일 경우에, 배경의 색으로 바꿔준다!!!
	
	2. 루프를 돌리기위해서는
	- mlx_hook 함수, 하나는 key, 하나는 mouse
	- main_loop함수를 돌리기위한 mlx_loop_hook함수
	- mlx_loop 함수!
	
	3. main_loop함수 
	- main_loop함수에, 렌더할 이미지를 출력하는 함수들을 위치시키는데, 덮어쓰기 방식으로한다면, 플레이어가 깜빡거림 (배경과 플레이어가 번갈아나타남)
	- 또는 main_loop함수에, 플레이어 이미지를 출력하는 함수만 넣는다면, 플레이어의 이동경로가 다 남음.
	- 그렇기떄문에, 각 픽셀마다, 하나만을 위치시켜야함 (5개 이미지중에서)
	
# 구현 방법
	1. map parsing!

	2. map check!

	3. map의 2중 배열을 가지고, 이미지를 출력

	4. 루프를 돌리기전에, 받은 키값으로 update

	5. 보너스
	- 이미지가 움직이는건, 그냥 다른 이미지 4 가지정도를 받아서 순서대로 출력함
	- 화면에 count를 출력하는건, mlx_string_put 함수를 사용함. 나는 벽위에 출력하도록 하였는데, 벽이랑 string이랑 교차 출력이되어서, 벽을 출력할떄, 벽 출력후에, string이 출력되도록함.
	- enemy == exit
	- main_loop에서, enemy가 움직이는것 까지 같은 횟수로 반복한다면, enemy가 움직이는 속도가
	- 너무 빠르기때문에, 50번에 한번 씩 움직이도록 한다.

# 배운것
	1. leak --> still reachable
	보동 신경쓰지않는 부분이지만, 이번 projet에서 leak이 발생한 경우는
	첫번째, GNL을 중간에서 끊었을때, --> 그래서 모든 라인을 다 읽은후 flag로 결과값을 받음
	두번째, exit함수로 종료했을때, --> free함수를 집어넣음
	세번째, destroy함수를 써야한다.

	2. segmentation fault
	첫번째, 무한 루프
	두번째, free된 메모리에 접근
	세번째, 초기화시켜놓지않은 변수에 접근
