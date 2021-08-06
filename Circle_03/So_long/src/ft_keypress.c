/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:14:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/06 17:21:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//ft_mouvement_player
	// ft_mouvement_player(all, keycode)
	// 1) on a gange collectible -> chagment floor + player, collectible--;
	// si collectible == 0, flag_exit = 1;
	// -> (C -> P)

	// 2) encore collectible, exit != 1;
	// -> E -> P+E  ou bien exit(0);
	
	// 3) floor,
	// -> (P -> 0), (0 -> F) swap

	// 
void	ft_player_move(t_info *all, char c)
{
	printf("x = %d, y = %d\n", all->map.p_x, all->map.p_y);
	if (c == 'U')
		printf("up\n");
	else if (c == 'D')
		printf("down\n");
	else if (c == 'L')
		printf("left\n");
	else if (c == 'R')
		printf("right\n");
}

int	keypress_event(int keycode, t_info *all)
{
	static int	flag;

	if (flag == 0)
		all->count_mouvement = 0;
	flag++;
	all->count_mouvement += 1;
	printf("count = %d\n", all->count_mouvement);
	printf("keycode : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119)
		ft_player_move(all, 'U');
	else if (keycode == 115)
		ft_player_move(all, 'D');
	else if (keycode == 97)
		ft_player_move(all, 'L');
	else if (keycode == 100)
		ft_player_move(all, 'R');
	return (0);
}

int	keypress(void)
{
	exit(0);
}
