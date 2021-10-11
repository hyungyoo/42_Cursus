/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:26:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/11 13:12:23 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
char	*ft_parsing_cmd(char *str)
{
	char *cmd;


	return (cmd);
}

char	**ft_parsing_cmd_option(char *str)
{
	char **cmd_parsing;

	return (cmd_parsing);
}

char	**ft_parsing_arg(char *str)
{
	char**arg;

	return (arg);
}

char	*ft_parsing_multi_cmd(char *str)
{
	char *multi_cmd;

	return (multi_cmd);
}

t_parsing	*ft_newnode(char *str)
{
	t_parsing *parsing;
	static int	count_node;

	g_info.count_node = ++count_node;
	parsing = NULL;
	parsing = (t_parsing*)malloc(sizeof(t_parsing));
	if (!parsing)
		return (NULL);
	ft_init_node(parsing);
	paring->cmd = ft_parsing_cmd(str);
	parsing->cmd_option = ft_pasing_cmd_option(str);
	parsing->arg = ft_pasing_arg(str);
	parsing->next_multi_cmd = ft_parsing_multi_cmd(str);
	parsing->next = parsing;
	parsing->prev = parsing;
	return (parsing);
}
*/
void	ft_parsing_cmd(char *str)
{
	char **split_cmd;
	char	**split_str;

	split_str = ft_split(str, ' ');
	split_cmd = ft_split_cmd(split_str);

	int	i = 0;
	while (split_cmd[i])
		printf("%s\n", split_cmd[i++]);
	
	ft_free_double(split_cmd);
}
/*
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	아니면 전부다 띄어쓰기로 split한것을 합쳐보면서, 만약에 | << >> > 일떄는 그것까지 합치고
	나머지는 free하는것도 방법인듯함
	좋아!

	이걸위해서는 add_split함수로 그안에있는것들을 <|<<>>>일때, 합치도록!
	strjoin함수로!

	cmd1 option arg m_cmd

	cmd2 option arg null

	

	comme ca, apres
	link all node;
	print all node for check!

	add first node in global value for free
	
	or t_parsing *ft_parsing_cmd(char *str) for free in minishell fucntion
	*/

