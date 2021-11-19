/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/19 18:58:51 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_arg(t_node *node)
{
	while (node && node->type != PIPE)
	{
		if (node->type == ARG || node->type == SINQ || node->type == DOUQ)
			return (1);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (0);
}

void	ft_export(t_node **cmd)
{
	char	*all_str;
	char	**str;

	if (!cmd || !*cmd)
		return ;
	else if (!ft_check_arg(*cmd))
	{
		ft_export_env();
		return ;
	}
	(*cmd) = (*cmd)->next;
	all_str = ft_all_arg(cmd);
	str = ft_split(all_str, ' ');
	// 이거말고 ft_array_double_env를 이용해서, 만들기!
	free(all_str);
	if (!ft_check_all(str))
		return ;
	ft_export_set_node(str);
	free_tab2(str);
	g_info.exit_code = 0;
}
