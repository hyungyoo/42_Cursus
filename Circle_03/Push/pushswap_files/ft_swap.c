/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:01:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:01:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	int	tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->num;
	stack_a->num = stack_a->next->num;
	stack_a->next->num = tmp;
	ft_putstr("sa\n");
}

void	ft_sb(t_stack *stack_b)
{
	int	tmp;

	if (!stack_b)
		return ;
	tmp = stack_b->num;
	stack_b->num = stack_b->next->num;
	stack_b->next->num = tmp;
	ft_putstr("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	if (!stack_a || !stack_b)
		return ;
	tmp = stack_a->num;
	stack_a->num = stack_a->next->num;
	stack_a->next->num = tmp;
	tmp = stack_b->num;
	stack_b->num = stack_b->next->num;
	stack_b->next->num = tmp;
	ft_putstr("ss\n");
}
