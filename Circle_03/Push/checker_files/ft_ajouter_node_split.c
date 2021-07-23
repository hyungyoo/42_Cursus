/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajouter_node_split.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:55:34 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:55:36 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_ajouter_node_split(t_stack **stack, char *num)
{
	char	**num_split;
	int		i;

	i = 0;
	num_split = ft_split(num);
	while (num_split[i])
	{
		ft_ajouter_node(stack, ft_new_node(num_split[i]));
		i++;
	}
	ft_free_split(num_split);
	num_split = NULL;
}
