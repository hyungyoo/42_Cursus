#include "so_long.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y *data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_mlx	mlx;
	t_data	data;
	t_data	img;

	int	i = 0;
	mlx.count = 0;
	int	img_width;
	int img_height;

	mlx.mlx = mlx_init();	// mlx_void ptr
	mlx.mlx_win = mlx_new_window(mlx.mlx, 500, 500, "test"); // window_ptr
	
	// for pixel, initialize img, addr etc
	data.img = mlx_new_image(mlx.mlx, 500, 500); // create image
	data.addr = mlx_get_data_addr(data.img, &data.bit_per_pixel, &data.line_length, &data.endian);

	// draw with funtion "my_mlx_pixel_put"
	while (i < 500)
	{
		my_mlx_pixel_put(&data, i, i, 0x00FF0000);
		i++;
	}
	// put image to window
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, data.img, 0, 0);

	// key event + X11 event types , + keymask
	mlx_hook(mlx.mlx_win, 2, 1L<<0, &keypress_event, &mlx);

/*
*	c'est a dire, pour afficher "sprite", 
*	mlx_xpm_file_to_image--> return img ptr,
*	avec img_ptr, mlx_put_image_to_window
*/
	// images, xpm files
	img.img = mlx_xpm_file_to_image(mlx.mlx, "./img/test.xpm", &img_width, &img_height);
	if (img.img == NULL)
		printf("faile\n");
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);

	mlx_loop(mlx.mlx);
	printf("haha\n");
	return (0);
}
