#include "so_long.h"

typedef struct	s_data
{
	void	*img;
	int		*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		count;
}				t_mlx;

int	keypress_event(int keycode, t_mlx *mlx)
{
	mlx->count += 1;
	printf("count : %d\n", mlx->count);
	printf("keycode : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y *data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/
int	main(void)
{
	t_mlx	mlx;
	//t_data	data;
	t_data	deux;
	t_data	k;

	int	i = 0;
	mlx.count = 0;
	int	img_width;
	int img_height;

	mlx.mlx = mlx_init();	// mlx_void ptr
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1000, 1000, "test"); // window_ptr
	
	// for pixel, initialize img, addr etc
	//k.img = mlx_new_image(mlx.mlx, 32, 32); // create image
	//k.addr = mlx_get_data_addr(k.img, &k.bit_per_pixel, &k.line_length, &k.endian);

	// draw with funtion "my_mlx_pixel_put"
	//while (i < 500)
	//{
	//	my_mlx_pixel_put(&data, i, i, 0x00FF0000);
	//	i++;
	//}
	// put image to window
	//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, data.img, 0, 0);

	// key event + X11 event types , + keymask
	mlx_hook(mlx.mlx_win, 2, 1L<<0, &keypress_event, &mlx);

/*
*	c'est a dire, pour afficher "sprite", 
*	mlx_xpm_file_to_image--> return img ptr,
*	avec img_ptr, mlx_put_image_to_window
*/
	// images, xpm files
	k.img = mlx_xpm_file_to_image(mlx.mlx, "./img/k.xpm", &img_width, &img_height);
	if (k.img == NULL)
		printf("faile\n");
	
	deux.img = mlx_xpm_file_to_image(mlx.mlx, "./img/sol.xpm", &img_width, &img_height);
	if (deux.img == NULL)
		printf("faile\n");

	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, k.img, 300, 300);
	k.addr = (int*)mlx_get_data_addr(k.img, &k.bit_per_pixel, &k.line_length, &k.endian);
	i = 0;
	int j;

	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (k.addr[i * k.line_length + j] == 0)
				k.addr[i * k.line_length  + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}


	
	int h = 0;
	//int j;

	while (h < 600)
	{
		j = 0;
		while (j < 600)
		{
			if (!(j == 64 && h == 64))
				mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, deux.img, h, j);
			j += 32;
		}
		h += 32;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, k.img, 400, 400);
	
	mlx_loop(mlx.mlx);

	printf("haha\n");
	printf("w: %d, h: %d\n", img_width, img_height);
	return (0);
}
