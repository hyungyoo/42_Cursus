/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:26:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 17:15:46 by hyungyoo         ###   ########.fr       */
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

