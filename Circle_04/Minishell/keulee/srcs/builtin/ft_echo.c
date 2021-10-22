/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 17:03:36 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_option(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i])
		if (str[i++] != 'n')
			return (0);
	return (1);
}

void	ft_echo_type_3(t_node **cmd)
{
	if ((*cmd)->next)
		(*cmd) = (*cmd)->next;
	if ((*cmd)->type == 12)
	{
		if (!ft_strcmp((*cmd)->str, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else
		{
			if (ft_getenv(g_info.envp, (*cmd)->str))
				ft_putstr(ft_getenv(g_info.envp, (*cmd)->str));
		}
	}
}

void	ft_echo_type_2(t_node **cmd)
{
	if (((*cmd)->str)[0] == '$')
	{
		if (!ft_strcmp((*cmd)->str + 1, "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else
		{
			if (ft_getenv(g_info.envp, (*cmd)->str + 1))
				ft_putstr(ft_getenv(g_info.envp, (*cmd)->str + 1));
		}
	}
	else
		ft_putstr((*cmd)->str);
}

int	ft_check_sans_espace(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}

void	ft_echo_type_2_sans_espace(char **key)
{
	int	i;

	i = -1;
	while (key[++i])
	{
		if (key[i][0] == '$')
		{
			if (!ft_strcmp(key[i], "?"))
				ft_putnbr_fd(g_info.exit_code, 1);
		}
		else
		{
			if (ft_getenv(g_info.envp, key[i]))
				ft_putstr(ft_getenv(g_info.envp, key[i]));
		}
	}
}

void	ft_type2_sans_espace(t_node **cmd)
{
	char	**split_str;

	split_str = ft_split((*cmd)->str, '$');
	ft_echo_type_2_sans_espace(split_str);
}

void	ft_print_echo(t_node **cmd)
{
	int	flag_space;

	flag_space = 1;
	while (*cmd && !((*cmd)->type == PIPE || (*cmd)->type == RIGHT 
			|| (*cmd)->type == DRIGHT || (*cmd)->type == LEFT ||  (*cmd)->type == DLEFT))
	{
		if (!(*cmd)->next)
			flag_space = 0;
		if ((*cmd)->type == 3)
			ft_echo_type_3(cmd);
		else if ((*cmd)->type == 2)
		{
			if (ft_check_sans_espace((*cmd)->str) > 1)
				ft_type2_sans_espace(cmd);
			else
				ft_echo_type_2(cmd);
		}
		else
			ft_putstr((*cmd)->str);
		if (flag_space)
			ft_putstr(" ");
		/////////////////////////////////
		//if ((*cmd)->flag_espace == 1)
		//	ft_putstr("\b");
		/////////////////////////////////
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else
			return ;
	}
}

void	ft_echo(t_node **cmd)
{
	int	flag_option;

	flag_option = 0;
	if (!cmd || !*cmd)
		return ;
	if (!((*cmd)->next))
		return ;
	(*cmd) = (*cmd)->next;
	if (ft_check_option((*cmd)->str))
	{
		flag_option = 1;
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
	}
	ft_print_echo(cmd);
	if (!flag_option)
		ft_putstr("\n");
	g_info.exit_code = 0;
}
