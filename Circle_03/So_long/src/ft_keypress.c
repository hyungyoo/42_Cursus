/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:14:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/05 15:46:25 by hyungyoo         ###   ########.fr       */
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
	/*
	else if (keycode == 119)
	up
	else if (keycode == 115)
	down
	else if (keycode == 97)
	left
	else if (keycode == 100)
	right
	*/
	return (0);
}

int	keypress(void)
{
	exit(0);
}
