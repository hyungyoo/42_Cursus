/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifier_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:57:56 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:57:57 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] - s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_operation(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (!ft_strcmp("sa", operation))
		ft_sa(*stack_a);
	else if (!ft_strcmp("sb", operation))
		ft_sb(*stack_b);
	else if (!ft_strcmp("ss", operation))
		ft_ss(*stack_a, *stack_b);
	else if (!ft_strcmp("pa", operation))
		ft_pa(stack_a, stack_b);
	else if (!ft_strcmp("pb", operation))
		ft_pb(stack_b, stack_a);
	else if (!ft_strcmp("ra", operation))
		ft_ra(stack_a);
	else if (!ft_strcmp("rb", operation))
		ft_rb(stack_b);
	else if (!ft_strcmp("rr", operation))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp("rra", operation))
		ft_rra(stack_a);
	else if (!ft_strcmp("rrb", operation))
		ft_rrb(stack_b);
	else if (!ft_strcmp("rrr", operation))
		ft_rrr(stack_a, stack_b);
	else
		ft_print_error();
}
