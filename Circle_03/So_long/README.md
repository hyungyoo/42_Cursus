# 2D game

# 함수 설명

1. <void	*mlx_init();>
- 그래픽 시스템과 연결을 하게 해준다!
- 간단한 윈도우 인터페이스 라이브러리
- 이벤트 관리 기능

2. <void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);>
- mlx_ptr은 <mlx_init>으로 받은 반환값을 넣어주면된다!
- 성공시, 리턴값은 새로운 윈도우 식별자 ptr;
- 실패시 NULL반환;

3. <int	mlx_clear_window(void *mlx_ptr, void *win_ptr);>
- 매개변수로 받은 win_ptr을 검은색으로 clear함 ?????

3. <int mlx_destroy_window(void *mlx_ptr, void *win_ptr);>
- 매개변수로 받은 win_ptr로 윈도우를 destroy함

4. <char	*mlx_get_data_adr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);>
- 무슨함수인지 설명을 하나도 못알아 듣겠음

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


