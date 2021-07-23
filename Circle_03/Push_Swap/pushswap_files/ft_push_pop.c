/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:00:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:00:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * pop
 * return : node qui est eleve
 * function : enlever node au top
 */
t_stack	*ft_pop(t_stack **stack)
{
	t_stack	*node_enleve;

	if (!stack)
		return (0);
	if (!*stack)
		return (0);
	node_enleve = *stack;
	if (*stack == (*stack)->next)
		*stack = 0;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
		node_enleve->prev = node_enleve;
		node_enleve->next = node_enleve;
	}
	return (node_enleve);
}

/*
 * push
 * return : void
 * funtion : ajouter node au top
 * 
 * ft_push(&stack_a, ft_pop(&stack_b); + ft_putstr("pa\n") == ft_pa
 */
void	ft_push(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	if (*stack)
	{
		(*stack)->prev->next = node;
		node->prev = (*stack)->prev;
		(*stack)->prev = node;
		node->next = *stack;
	}
	*stack = node;
}
