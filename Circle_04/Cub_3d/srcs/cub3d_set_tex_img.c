#include "../cub3d.h"

void	load_texture(t_game *game)
{
	t_img	img;

	load_img(game, game->info.texture[TEX_NORTH],
		game->info.tex_path[TEX_NORTH], &img);
	free(game->info.tex_path[TEX_NORTH]);
	load_img(game, game->info.texture[TEX_EAST],
		game->info.tex_path[TEX_EAST], &img);
	free(game->info.tex_path[TEX_EAST]);
	load_img(game, game->info.texture[TEX_WEST],
		game->info.tex_path[TEX_WEST], &img);
	free(game->info.tex_path[TEX_WEST]);
	load_img(game, game->info.texture[TEX_SOUTH],
		game->info.tex_path[TEX_SOUTH], &img);
	free(game->info.tex_path[TEX_SOUTH]);
}

void	load_img(t_game *game, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &img->width,
			&img->height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->size_l, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[img->width * y + x] = img->data[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img->img_ptr);
}
