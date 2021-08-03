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
	int		px;
	int		py;
	t_data k;
	t_data deux;
}				t_mlx;

int	keypress(void)
{
	exit(1);
}

int	keypress_event(int keycode, t_mlx *mlx)
{
	mlx->count += 1;
	printf("count : %d\n", mlx->count);
	printf("keycode : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	else if (keycode == 97)
	{
		mlx->px -= 32;
		printf("%d\n", mlx->px);
	}
	else if (keycode == 100)
	{
		mlx->px += 32;
		printf("%d\n", mlx->px);
	}

	return (0);
}


int	ft(t_mlx *mlx)
{
	// ici

	int i = 0;
	int j;

	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			if (i == mlx->px && j == mlx->py)
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->k.img, i, j);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->deux.img, i, j);
			j += 32;
		}
		i += 32;
	}
	return (0);
}


int	main(void)
{
	t_mlx	mlx;
	//t_data	deux;
	//t_data	k;

	int	i = 0;
	mlx.px = 0;
	mlx.py = 0;
	int	j;
	mlx.count = 0;
	int	img_width;
	int img_height;
	int	img_width1;
	int img_height1;

	printf("avant mlx\n");

	mlx.mlx = mlx_init();	// mlx_void ptr
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1000, 1000, "test"); // window_ptr
	printf("mlx_xpm_to_file\n");

	mlx.deux.img = mlx_xpm_file_to_image(mlx.mlx, "./img/sol.xpm", &img_width, &img_height);
	if (mlx.deux.img == NULL)
		printf("faile\n");

	mlx.k.img = mlx_xpm_file_to_image(mlx.mlx, "./img/k.xpm", &img_width1, &img_height1);
	if (mlx.k.img == NULL)
		printf("faile\n");
	
	mlx.deux.addr = (int*)mlx_get_data_addr(mlx.deux.img, &mlx.deux.bit_per_pixel, &mlx.deux.line_length, &mlx.deux.endian);
	mlx.k.addr = (int*)mlx_get_data_addr(mlx.k.img, &mlx.k.bit_per_pixel, &mlx.k.line_length, &mlx.k.endian);
	
/*
	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.deux.img, i, j);
			j += 32;
		}
		i += 32;
	}
*/
	printf("addr chage\n");

	i = 0;
	j = 0;
	int b = mlx.k.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (mlx.k.addr[i * img_width + j] == b)
				mlx.k.addr[i * img_width + j] = mlx.deux.addr[i * img_width + j];
			j++;
		}
		i++;
	}
	
	printf("mlx_hook\n");


	printf("put image\n");
	
	//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, k.img, mlx.px, mlx.py);
	
	//ft(t_mlx *mlx)

	//key
	mlx_hook(mlx.mlx_win, 2, 1L<<0, &keypress_event, &mlx);
	
	// mouse
	mlx_hook(mlx.mlx_win, 17, 0, &keypress, 0);
	
	mlx_loop_hook(mlx.mlx, &ft, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_image(mlx.mlx, mlx.deux.img);
	mlx_destroy_image(mlx.mlx, mlx.k.img);
	return (0);
}
