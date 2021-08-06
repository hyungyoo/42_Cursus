/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:32:17 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/06 18:40:44 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_print_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}

/*
* file_name: *.ber
* return : 1 / T,     0 / F 
*/
int	ft_file_name(char *file_name, char *cmp)
{
	int		name_point;
	int		i;

	i = 0;
	if (ft_strlen(file_name) < 5)
		return (0);
	name_point = (int)ft_strlen(file_name) - 4;
	while (file_name[name_point] && cmp[i])
	{
		if (file_name[name_point] != cmp[i])
			return (0);
		name_point++;
		i++;
	}
	return (1);
}
