/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:00:14 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:00:15 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, ft_pop(stack_b));
	ft_putstr("pa\n");
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, ft_pop(stack_a));
	ft_putstr("pb\n");
}
