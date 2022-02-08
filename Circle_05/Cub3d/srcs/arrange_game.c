#include "cub3d.h"

/*
 * set the img & texture for the game map 
 *
 * */

void	arrange_game(t_info *all)
{
	set_player_direction(all);
	all->mlx = mlx_init();
	allocate_game_buf(all);
	load_texture(all);
	all->img.ptr = mlx_new_image(all->mlx,
			all->window_width, all->window_height);
	all->img.data = (int *)mlx_get_data_addr
		(all->img.ptr, &all->img.bpp, &all->img.size_line, &all->img.endian);
}

/*
 * 방향 벡터 구하기( 회전행렬) 
 * player 의 방향 
 * camera 의 방향 (plan_x, plan_y)
 * */
void	rotate_player(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) \
					- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + \
					player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - \
					player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed) + \
					player->plane_y * cos(rot_speed);
}

/*
 * allocate the game height & width size
 * manage the calloc error
 * 탁유정 잘못으로 여기서 삼십분 고생함
 */
void	allocate_game_buf(t_info *all)
{
	int	i;

	all->render_buf = ft_calloc(all->window_height, sizeof(int **));
	if (!all->render_buf)
		ft_strexit("Error: malloc game map height failed!");
	i = 0;
	while (i < all->window_height)
	{
		all->render_buf[i] = ft_calloc(all->window_width, sizeof(int *));
		if (!all->render_buf[i])
			ft_strexit("Error: malloc game map width failed!");
		i++;
	}
}

void	load_texture(t_info	*all)
{
	t_img	img;

	load_image(all, all->env.tex[WEST], all->env.path[WEST], &img);
	free(all->env.path[WEST]);
	load_image(all, all->env.tex[EAST], all->env.path[EAST], &img);
	free(all->env.path[EAST]);
	load_image(all, all->env.tex[SOUTH], all->env.path[SOUTH], &img);
	free(all->env.path[SOUTH]);
	load_image(all, all->env.tex[NORTH], all->env.path[NORTH], &img);
	free(all->env.path[NORTH]);
}

void	load_image(t_info *all, int	*texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->ptr = mlx_xpm_file_to_image(all->mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr
		(img->ptr, &img->bpp, &img->size_line, &img->endian);
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
	mlx_destroy_image(all->mlx, img->ptr);
}
