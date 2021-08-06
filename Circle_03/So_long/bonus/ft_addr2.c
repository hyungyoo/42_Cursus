/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:07:55 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/06 20:59:35 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
* ft_change_addr
* intialize black area
*/
void	ft_change_addr_enemy0(t_info *all, int img_width, int img_height)
{
	int	i;
	int	j;
	int	c;
	int	w;

	w = img_width;
	i = 0;
	c = all->enemy0.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (all->enemy0.addr[i * w + j] == c)
				all->enemy0.addr[i * w + j] = all->floor.addr[i * w + j];
			j++;
		}
		i++;
	}
}

void	ft_change_addr_enemy1(t_info *all, int img_width, int img_height)
{
	int	i;
	int	j;
	int	c;
	int	w;

	w = img_width;
	i = 0;
	c = all->enemy1.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (all->enemy1.addr[i * w + j] == c)
				all->enemy1.addr[i * w + j] = all->floor.addr[i * w + j];
			j++;
		}
		i++;
	}
}

void	ft_change_addr_enemy2(t_info *all, int img_width, int img_height)
{
	int	i;
	int	j;
	int	c;
	int	w;

	w = img_width;
	i = 0;
	c = all->enemy2.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (all->enemy2.addr[i * w + j] == c)
				all->enemy2.addr[i * w + j] = all->floor.addr[i * w + j];
			j++;
		}
		i++;
	}
}

void	ft_change_addr_enemy3(t_info *all, int img_width, int img_height)
{
	int	i;
	int	j;
	int	c;
	int	w;

	w = img_width;
	i = 0;
	c = all->enemy3.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (all->enemy3.addr[i * w + j] == c)
				all->enemy3.addr[i * w + j] = all->floor.addr[i * w + j];
			j++;
		}
		i++;
	}
}

void	ft_change_addr_enemy(t_info *all, int img_width, int img_height)
{
	ft_change_addr_enemy0(all, img_width, img_height);
	ft_change_addr_enemy1(all, img_width, img_height);
	ft_change_addr_enemy2(all, img_width, img_height);
	ft_change_addr_enemy3(all, img_width, img_height);
}
