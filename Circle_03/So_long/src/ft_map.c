/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:32:45 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/03 18:38:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
* ft_row_col
* check num_row, num_col
* return ret
*/
int	ft_row_col(t_info *all)
{
	char	*line;
	int		r;
	int		count;

	count = 0;
	r = get_next_line(all->map.fd, &line);
	all->map.num_cols = (int)ft_strlen(line);
	while (r > 0)
	{
		if (all->map.num_cols != (int)ft_strlen(line))
		{
			free(line);
			return (0);
		}
		free(line);
		r = get_next_line(all->map.fd, &line);
		count++;
	}
	free(line);
	all->map.num_rows = count;
	return (1);
}

/* 
* ft_map_array
* (char**)map_array
*/
void	ft_map_array(t_info *all)
{
	int		num_rows;
	int		i;
	char	*line;
	int		r;

	i = 0;
	num_rows = all->map.num_rows;
	all->map.map_array = (char **)malloc(sizeof(char *) * num_rows + 1);
	if (!all->map.map_array)
		return ;
	all->map.map_array[num_rows] = '\0';
	r = get_next_line(all->map.fd2, &line);
	while (r > 0)
	{
		all->map.map_array[i++] = ft_strdup(line);
		free(line);
		r = get_next_line(all->map.fd2, &line);
	}
	free(line);
}

void	ft_map_element(t_info *all)
{
	// only 1 0 e p c
	// at least 1 of 5 element
}

/* //////ft_map/////////
* file_open , fd  ok
* check_map and parsing 
* check rect, wall, 5 elements
*/
void	ft_map(char *file_path, t_info *all)
{
	all->map.fd = open(file_path, O_RDONLY);
	if (all->map.fd == -1)
		ft_print_error("Error: file error.");
	all->map.fd2 = open(file_path, O_RDONLY);
	if (all->map.fd2 == -1)
		ft_print_error("Error: file error.");
	if (!ft_row_col(all))
		ft_print_error("Error: map is not rectangular");
	ft_map_array(all);
	ft_map_wall(all);
	ft_map_element(all);
}
