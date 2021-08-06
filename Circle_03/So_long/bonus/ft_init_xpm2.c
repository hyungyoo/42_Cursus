/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_xpm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:00:57 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/06 22:57:12 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
* initialize img for each struct
*/
void	ft_mlx_xpm_to_image2(t_info *all, int *img_width, int *img_height)
{
	all->enemy0.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/enemy0.xpm", img_width, img_height);
	if (all->enemy0.img == NULL)
		ft_print_error("Error: Not enemy image");
	all->enemy1.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/enemy1.xpm", img_width, img_height);
	if (all->enemy1.img == NULL)
		ft_print_error("Error: Not enemy image");
	all->enemy2.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/enemy2.xpm", img_width, img_height);
	if (all->enemy2.img == NULL)
		ft_print_error("Error: Not enemy image");
	all->enemy3.img = mlx_xpm_file_to_image(all->mlx.mlx,
			"./img/enemy3.xpm", img_width, img_height);
	if (all->enemy3.img == NULL)
		ft_print_error("Error: Not enemy image");
}

/*
* ft_get_data_addr.c
* for get addr 
*/
void	ft_get_data_addr2(t_info *all)
{
	all->enemy0.addr = (int *)mlx_get_data_addr(all->enemy0.img,
			&(all->enemy0.bit_per_pixel), &(all->enemy0.line_length),
			&(all->enemy0.endian));
	all->enemy1.addr = (int *)mlx_get_data_addr(all->enemy1.img,
			&(all->enemy1.bit_per_pixel), &(all->enemy1.line_length),
			&(all->enemy1.endian));
	all->enemy2.addr = (int *)mlx_get_data_addr(all->enemy2.img,
			&(all->enemy2.bit_per_pixel), &(all->enemy2.line_length),
			&(all->enemy2.endian));
	all->enemy3.addr = (int *)mlx_get_data_addr(all->enemy3.img,
			&(all->enemy3.bit_per_pixel), &(all->enemy3.line_length),
			&(all->enemy3.endian));
}
