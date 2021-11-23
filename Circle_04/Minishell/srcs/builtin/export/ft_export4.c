/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/23 21:17:28 by hyungyoo         ###   ########.fr       */
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

int	ft_size_array_export(t_node *cmd)
{
	int		ret;

	ret = 0;
	if (!cmd)
		return (-1);
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->flag_nospace == 0 && ft_not_type(cmd))
			ret++;
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
	return (ret);
}

char	**ft_array_double_export(t_node *cmd)
{
	char	**array_export;
	int		i;
	int		size_array;

	i = 0;
	size_array = ft_size_array_export(cmd);
	array_export = (char **)malloc(sizeof(char *) * (size_array + 1));
	if (!array_export)
		return (NULL);
	while (i < size_array)
	{
		array_export[i] = NULL;
		if (ft_not_type(cmd))
		{
			while (cmd && ft_not_type(cmd) && cmd->flag_nospace == 1)
			{
				array_export[i] = ft_strjoin_free(array_export[i], cmd->str);
				if (cmd->next)
					cmd = cmd->next;
				else
					break ;
			}
			if (cmd && ft_not_type(cmd))
				array_export[i] = ft_strjoin_free(array_export[i], cmd->str);
			i++;
		}
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
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
	////////////////////////////////////////////////////
	printf("\n\narray_export arg\n");
	int	i = 0;
	while (str[i])
	{
		printf("str %d eme est %s\n", i, str[i]);
		i++;
	}
	///////////////////////////////////////////////////
*/
	ft_check_all(str);      //$PATH=dwq 이라면 PATH만 고를수있다면
	// ft_export3 에서, ft_check_value 45, =전까지만 strstr으로 확인한후에,  비교하기, 그리고 path는 왜 안되지?
	ft_export_set_node(str);
	free_tab2(str);
}
