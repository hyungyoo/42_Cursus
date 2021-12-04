/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_rearrange_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:58:17 by seyun             #+#    #+#             */
/*   Updated: 2021/12/02 22:42:48 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rearrange_game(t_game *game)
{
	apply_player_orientation(game);
	game->mlx = mlx_init();
	allocate_buffer(game);
	load_texture(game);
	game->img.ptr = mlx_new_image(game->mlx, game->width, game->height);
	game->img.data = (int *)mlx_get_data_addr(game->img.ptr, \
			&game->img.bpp, &game->img.size_l, &game->img.endian);
}

void	apply_player_orientation(t_game *game)
{
	int	degree;

	degree = 0;
	if (game->player.dir == 'N')
		degree = 90;
	else if (game->player.dir == 'S')
		degree = 270;
	else if (game->player.dir == 'E')
		degree = 0;
	else if (game->player.dir == 'W')
		degree = 180;
	rotate_player(&game->player, degree * (PI / 180));
}

void	allocate_buffer(t_game *game)
{
	int	i;

	game->buf = ft_calloc(game->height, sizeof(int **));
	if (!game->buf)
		ft_strexit("ERROR: Malloc Fail!");
	i = 0;
	while (i < game->height)
	{
		game->buf[i] = ft_calloc(game->width, sizeof(int *));
		if (!game->buf[i])
			ft_strexit("ERROR: Malloc Fail!");
		i++;
	}
}

void	load_texture(t_game *game)
{
	t_img	img;

	load_image(game, game->tex.tile[WEST], game->tex.path[WEST], &img);
	free(game->tex.path[WEST]);
	load_image(game, game->tex.tile[EAST], game->tex.path[EAST], &img);
	free(game->tex.path[EAST]);
	load_image(game, game->tex.tile[SOUTH], game->tex.path[SOUTH], &img);
	free(game->tex.path[SOUTH]);
	load_image(game, game->tex.tile[NORTH], game->tex.path[NORTH], &img);
	free(game->tex.path[NORTH]);
}

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->ptr = mlx_xpm_file_to_image(game->mlx, path, \
			&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, \
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
	mlx_destroy_image(game->mlx, img->ptr);
}
