/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:12:11 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/06 18:40:09 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	keypress_event(int keycode, t_info *all)
{
	static int	flag;

	if (flag == 0)
		all->count_mouvement = 0;
	flag++;
	all->count_mouvement += 1;
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
	printf("count = %d\n", all->count_mouvement);
	printf("count_collectible = %d\n", all->map.num_collectible);
	return (0);
}

int	keypress(void)
{
	exit(0);
}
