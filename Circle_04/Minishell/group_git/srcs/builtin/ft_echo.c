/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/23 17:00:34 by hyungyoo         ###   ########.fr       */
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

void	ft_echo_type_2_sans_espace(char **key, char *str)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (i == 0 && str[0] != '$')
			ft_putstr(key[i]);
		else if (key[i][0] == '$')
		{
			if (!ft_strcmp(key[i], "?"))
				ft_putnbr_fd(g_info.exit_code, 1);
		}
		else
		{
			if (ft_getenv(g_info.envp, key[i]))
				ft_putstr(ft_getenv(g_info.envp, key[i]));
		}
		i++;
	}
}

void	ft_type2_sans_espace(t_node **cmd)
{
	char	**split_str;

	split_str = ft_split((*cmd)->str, '$');
	ft_echo_type_2_sans_espace(split_str, (*cmd)->str);
}

int	ft_check_type(int type)
{
	if (!(type == PIPE || type == RIGHT
			|| type == DRIGHT || type == LEFT || type == DLEFT))
		return (1);
	return (0);
}

void	ft_print_echo(t_node **cmd)
{
	while (*cmd && ft_check_type((*cmd)->type))
	{
		if ((*cmd)->type == DOLR)
			ft_echo_type_3(cmd);
		else if ((*cmd)->type == DOUQ)
		{
			if (ft_check_sans_espace((*cmd)->str) >= 1)
				ft_type2_sans_espace(cmd);
			else
				ft_echo_type_2(cmd);
		}
		else
			ft_putstr((*cmd)->str);
		if ((*cmd)->next)
			ft_putstr(" ");
		if ((*cmd)->flag_nospace == 1)
			ft_putstr("\b");
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
