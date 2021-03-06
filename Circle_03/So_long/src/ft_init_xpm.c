/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:00:57 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/06 18:11:27 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
* initialize img for each struct
*/
void	ft_mlx_xpm_to_image(t_info *all, int *img_width, int *img_height)
{
	all->player.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/player.xpm", img_width, img_height);
	if (all->player.img == NULL)
		ft_print_error("Error: Not player image");
	all->wall.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/wall.xpm", img_width, img_height);
	if (all->wall.img == NULL)
		ft_print_error("Error: Not wall image");
	all->exit.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/exit.xpm", img_width, img_height);
	if (all->exit.img == NULL)
		ft_print_error("Error: Not exit image");
	all->floor.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/floor.xpm", img_width, img_height);
	if (all->floor.img == NULL)
		ft_print_error("Error: Not floor image");
	all->collectible.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/collectible.xpm", img_width, img_height);
	if (all->collectible.img == NULL)
		ft_print_error("Error: Not collectible image");
	all->player_exit.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/player.xpm", img_width, img_height);
	if (all->player_exit.img == NULL)
		ft_print_error("Error: Not Player image");
}

/*
* ft_get_data_addr.c
* for get addr 
*/
void	ft_get_data_addr(t_info *all)
{
	all->player.addr = (int *)mlx_get_data_addr(all->player.img,
			&(all->player.bit_per_pixel), &(all->player.line_length),
			&(all->player.endian));
	all->exit.addr = (int *)mlx_get_data_addr(all->exit.img,
			&(all->exit.bit_per_pixel), &(all->exit.line_length),
			&(all->exit.endian));
	all->collectible.addr = (int *)mlx_get_data_addr(all->collectible.img,
			&(all->collectible.bit_per_pixel), &(all->collectible.line_length),
			&(all->collectible.endian));
	all->floor.addr = (int *)mlx_get_data_addr(all->floor.img,
			&(all->floor.bit_per_pixel),
			&(all->floor.line_length), &(all->floor.endian));
	all->player_exit.addr = (int *)mlx_get_data_addr(all->player_exit.img,
			&(all->player_exit.bit_per_pixel),
			&(all->player_exit.line_length), &(all->player_exit.endian));
}

/*
*	initialize mlx_xpm_file_to_image and mlx_get_data_addr
*/
void	ft_init_xpm(t_info *all)
{
	int	img_width;
	int	img_height;

	ft_mlx_xpm_to_image(all, &img_width, &img_height);
	ft_get_data_addr(all);
	ft_change_addr_player(all, img_width, img_height);
	ft_change_addr_collectible(all, img_width, img_height);
	ft_change_addr_pl_ex(all, img_width, img_height);
}
