/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:31:57 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/04 16:55:25 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

/*
* line * ~ *
* ft_print_error.c
*/
int	main(int argc, char **argv)
{
	t_info	all;

	if (!(argc == 2 && ft_file_name(argv[1], ".ber")))
		ft_print_error("to use :./so_long maps/*.ber");
	ft_map(argv[1], &all);
	all.mlx.mlx = mlx_init();
	all.mlx.win_mlx = mlx_new_window(all.mlx.mlx, all.mlx.window_width, all.mlx.window_height, "So_Long");
	ft_init_xpm(&all);

	// key and mouse event
	//// mouvement -> 
	//player x , y -> swap with wall
	//option ///////
	// si c est pas mur
	// s il gagne collectible, enlever collectible et num_collectible--



	// loop -> funtion appler main_loop
	/////////////main_loop//////
	//update
	//setup
	////////////////////////////

	mlx_loop(all.mlx.mlx);
	ft_free(&all);
	return (0);
}
