/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/21 02:40:16 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_arg(t_node *node)
{
	while (node && node->type != PIPE)
	{
		if (ft_strcmp(node->str, "") && (node->type == ARG
			|| node->type == SINQ || node->type == DOUQ))
			return (1);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (0);
}

int	ft_size_node_export(t_node *cmd)
{
	int		ret;

	ret = 0;
	if (!cmd)
		return (-1);
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->next)
		{
			ret++;
			cmd = cmd->next;
		}
		else
			break ;
	}
	return (ret + 1);
}

char	**ft_array_double_export(t_node *cmd)
{
	char	**array_export;
	int		i;
	int		size_node;

	i = 0;
	size_node = ft_size_node_export(cmd);
	if (!cmd)
		return (NULL);
	array_export = (char **)malloc(sizeof(char *) * (size_node + 1));
	if (!array_export)
		return (NULL);
	while (i < size_node)
	{
		array_export[i] = ft_strdup(cmd->str);
		cmd = cmd->next;
		i++;
	}
	array_export[i] = NULL;
	return (array_export);
}

// 1. array 만들기
// 2. ft_check_all
// 3. ft_export_set_node

void	ft_export(t_node **cmd)
{
	char	**str;

	if (!cmd || !*cmd)
		return ;
	else if (!ft_check_arg(*cmd))
	{
		ft_export_env();
		return ;
	}
	(*cmd) = (*cmd)->next;
	str = ft_array_double_export(*cmd);
	g_info.exit_code = 0;

	/*
	int	i = 0;
	while (str[i])
	{
		printf("str %d eme est %s\n", i, str[i]);
		i++;
	}
	*/
	ft_check_all(str);
	//ft_export_set_node(str);
	free_tab2(str);
}
