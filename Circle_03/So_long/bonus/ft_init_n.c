/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:45:01 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/09 21:03:01 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_init_n(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == '0')
			{
				map->n_x = i;
				map->n_y = j;
				map->map_array[i][j] = 'N';
				return ;
			}
			j++;
		}
		i++;
	}
	ft_print_error2("Error: pas de place pour enemy", map);
}
