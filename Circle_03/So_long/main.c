#include "so_long.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y *data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	int	i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "test");
	data.img = mlx_new_image(mlx, 500, 500);
	data.addr = mlx_get_data_addr(data.img, &data.bit_per_pixel, &data.line_length, &data.endian);
	while (i < 500)
	{
		my_mlx_pixel_put(&data, i, i, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);
	printf("haha\n");
	return (0);
}
