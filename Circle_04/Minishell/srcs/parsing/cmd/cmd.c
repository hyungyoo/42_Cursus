/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:26:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 21:41:06 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

void	ft_parsing_cmd(char *str)
{

	/*

	if multi_cmd, parsing_ node

	split ->  | < << > >> double array et multiple_cmd
	if cat infile | grep "lol"
		1er == cmd
		2eme == commence avec - == option
				sinon, arg


		//////////autre fichier
		3. link node (double)
		4. ajouter global pour ft_exit free


	if 

	split multi cmd;
	in there, multi cmd aussi! 
	cmd1 option arg m_cmd cmd2 option arg..
	
	split오류 == 
	pivot이 << >> 은 인식못함!
	그렇기때문에, 좆됨...
	아니면 check_pivot에 strcmp로 <<가 있는지 확인하는것도있는데 그건별로임..
	그리고 cmd1| 이것도 pivot으로 읽을듯
	다른방법을 찾아야함
	다 읽어가면서 앞뒤가 space이며 pivot = "|" < << > >> 인 경우를 기준으로
	split할수있는 함수가 있어야한다.
	아니면 전부다 띄어쓰기로 split한것을 합쳐보면서, 만약에 | << >> > 일떄는 그것까지 합치고
	나머지는 free하는것도 방법인듯함
	좋아!

	cmd1 option arg m_cmd

	cmd2 option arg null

	comme ca, apres
	link all node;
	print all node for check!

	add first node in global value for free
	
	or t_parsing *ft_parsing_cmd(char *str) for free in minishell fucntion
	*/
	return ;
}

