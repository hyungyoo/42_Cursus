/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:31:57 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/04 08:22:31 by hyungyoo         ###   ########.fr       */
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
	
	//////mlx_xpm_file_to_imgae, mlx_get_data_addr/////
	//ft_xpm_to_image(&(all.mlx));
	///////////////////////////////////////////////////

	// create ptr_mlx and win (with pixel_size * rows and cols of map)


	// create image of xpm

	// change xpm of p, c, e

	// main_loop
	/*
	* render 1, 0, e, p, c ->each put xpm
	*/
	

	// key and mouse event
	/*
	* key event
	* update
	*/

	mlx_loop(all.mlx.mlx);
	ft_free(&all);
	return (0);
}
