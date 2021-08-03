/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:31:29 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/03 18:32:52 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//////////////////////////////////////
/*
1111111111
1100000011
1111111111
1111111110
*/
int	ft_str_wall_row(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_wall_col(t_info *all, int index)
{
	int		i;
	char	cmp;

	i = 0;
	while (i < all->map.num_rows)
	{
		cmp = all->map.map_array[i][index];
		if (cmp != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_map_wall(t_info *all)
{
	int	num_rows;
	int	num_cols;
	int	flag;

	flag = 0;
	num_rows = all->map.num_rows - 1;
	num_cols = all->map.num_cols - 1;
	if (!ft_str_wall_row(all->map.map_array[0], '1'))
		flag++;
	else if (!ft_str_wall_row(all->map.map_array[num_rows], '1'))
		flag++;
	else if (!ft_str_wall_col(all, 0))
		flag++;
	else if (!ft_str_wall_col(all, num_cols))
		flag++;
	if (flag != 0)
	{
		ft_free(all);
		ft_print_error("Error: Map must be closed by Wall");
	}
}
