/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 03:39:15 by keulee            #+#    #+#             */
/*   Updated: 2021/12/02 16:39:40 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*init_cmd(void)
{	
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->size = 0;
	cmd->cmd_start = NULL;
	return (cmd);
}

void	insert_node(t_cmd **cmd, int type, char *str)
{
	t_node	*new;
	t_node	*tmp;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->prev = NULL;
	new->next = NULL;
	new->str = str;
	new->type = type;
	new->flag_nospace = 0;
	tmp = (*cmd)->cmd_start;
	if (tmp == NULL)
		(*cmd)->cmd_start = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	(*cmd)->size++;
}

void	free_list(t_cmd **cmd)
{
	t_node	*tmp;

	while ((*cmd)->cmd_start)
	{
		tmp = (*cmd)->cmd_start->next;
		free((*cmd)->cmd_start->str);
		(*cmd)->cmd_start->str = NULL;
		free((*cmd)->cmd_start);
		(*cmd)->cmd_start = tmp;
	}
	free(*cmd);
	(*cmd) = NULL;
}

int	get_listsize(t_node **node)
{
	t_node	*tmp;
	int		size;

	tmp = *node;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
/*
void	print_cmdline(t_cmd **cmd)
{
	t_node	*tmp;
	int		i;

	if (!cmd)
		return ;
	tmp = (*cmd)->cmd_start;
	i = 0;
	printf("\n");
	printf("\033[1;34m----------DEBUG---------\n");
	printf("\n");
	printf(" NODE | TYPE  |    STR(NOSPACE, EMPTYSTR)    \n");
	while (tmp && i < (*cmd)->size)
	{
		printf("------|-------|-----------\n");
		if (tmp->type >= CMD)
		{
			if (i >= 10)
				printf("  %d  |   %d  | %s(%d, %d) \n", i++,
				tmp->type, tmp->str, tmp->flag_nospace, tmp->flag_emptystr);
			else
				printf("  %d   |   %d  | %s(%d, %d) \n",
				i++, tmp->type, tmp->str, tmp->flag_nospace, tmp->flag_emptystr);
		}
		else if (i >= 10)
			printf("  %d  |   %d   | %s(%d, %d) \n", i++,
			tmp->type, tmp->str, tmp->flag_nospace, tmp->flag_emptystr);
		else
			printf("  %d   |   %d   | %s(%d, %d) \n", i++,
			tmp->type, tmp->str, tmp->flag_nospace, tmp->flag_emptystr);
		tmp = tmp->next;
	}
	printf("\n");
	printf("----------DONE---------\n");
}
*/
